%{
//libraries first
//JASON DERULOOOOO
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <vector>

#include <map>

using namespace std;

  void yyerror(const char* s);
  int yylex();

  extern int line;
  extern char* yytext;
  extern char* progStart;
  extern int position;
  extern FILE * yyin;
  
  string newTemp();
  string newLabel();

  char empty[1] = "";

  map<string, int> variables;
  map<string, int> functions;

  vector<string> reservedWords = {
  "FUNCTION", 
  "BEGIN_PARAMS", 
  "END_PARAMS", 
  "BEGIN_LOCALS", 
  "END_LOCALS", 
  "BEGIN_BODY", 
  "END_BODY", 
  "INTEGER",
  "ARRAY",
  "OF", 
  "IF", 
  "THEN", 
  "ENDIF", 
  "ELSE", 
  "WHILE", 
  "DO", "FOR", 
  "IN", 
  "BEGINLOOP", 
  "ENDLOOP", 
  "CONTINUE", 
  "READ", 
  "WRITE", 
  "AND", 
  "OR", 
  "NOT", 
  "TRUE", 
  "FALSE", 
  "RETURN", 
  "SUB", 
  "ADD", 
  "MULT", 
  "DIV", 
  "MOD", 
  "EQ", 
  "NEQ", 
  "LT", 
  "GT", 
  "LTE", 
  "GTE", 
  "L_PAREN", 
  "R_PAREN", 
  "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", 
  "COLON", 
  "SEMICOLON", 
  "COMMA", 
  "ASSIGN", 
  "function", 
  "identifier", 
  "beginparams", 
  "endparams", 
  "beginlocals", 
  "endlocals", 
  "integer", 
  "beginbody", 
  "endbody", 
  "beginloop", 
  "endloop", 
  "if", 
  "endif", 
  "for", 
  "continue", 
  "while", 
  "else", 
  "read", 
  "do", 
  "write"};
%}


%union{
  char* charVal;
  int intVal;
  struct exprStruct {
    char* location;
    char* code;
    bool array;
  } expr;

  struct statementStruct {
    char* code;
  } stat;
 }

%error-verbose
%start Program

%token <charVal> IDENT
%token <intVal> number

%type <expr> identifier 
%type <expr> identifier_variable 
%type <expr> function_identifier
%type <expr> declaration_loop 
%type <expr> declaration 
%type <expr> identifier_loop 
%type <expr> var 
%type <expr> var_loop
%type <stat> statement_loop 
%type <stat> statement 
%type <stat> else_statement
%type <expr> expression 
%type <expr> exp_loop 
%type <expr> mult_exp 
%type <expr> term 
%type <expr> bool_exp 
%type <expr> relation_and_exp 
%type <expr> relation_exp 
%type <expr> relation_exp_not 
%type <expr> comp

%token FUNCTION
%token IDENTIFIER
%token BEGIN_PARAMS
%token END_PARAMS
%token BEGIN_LOCALS
%token END_LOCALS
%token BEGIN_BODY
%token END_BODY
%token INTEGER
%token ARRAY
%token OF
%token IF
%token THEN
%token ENDIF
%token ELSE
%token WHILE
%token DO
%token FOR
%token IN
%token BEGINLOOP
%token ENDLOOP
%token CONTINUE
%token READ
%token WRITE
%token EXIT
%token COMMA
%token COLON
%token SEMICOLON
%token TRUE
%token FALSE
%token RETURN

// order here from phase 2
%right ASSIGN
%left OR
%left AND
%right NOT
%left LT LTE GT GTE EQ NEQ
%left ADD SUB
%left MULT DIV MOD
%right UMINUS
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left L_PAREN R_PAREN

%%  

Program: %empty
{
  if ( functions.find("main") == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Function main not declared");
    yyerror(temp);
  }
  if (variables.find(string(progStart)) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Declared program name as tempVar.");
    yyerror(temp);
  }
}
| Function Program
{
    // Nothing needed here?
};
   
Function: FUNCTION function_identifier SEMICOLON BEGIN_PARAMS declaration_loop END_PARAMS BEGIN_LOCALS declaration_loop END_LOCALS BEGIN_BODY statement_loop END_BODY
{
  string temp = "func ";  //starts function with func
  temp.append($2.location);
  temp.append("\n");
  temp.append($2.code);
  temp.append($5.code);
  string params = $5.code;
  int param_number = 0;
  while (params.find(".") != string::npos) {
    size_t pos = params.find(".");
    params.replace(pos, 1, "=");
    string param = ", $";
    param.append(to_string(param_number++));
    param.append("\n");
    params.replace(params.find("\n", pos), 1, param);
  }
  temp.append(params);
  temp.append($8.code);
  string statement_loop($11.code);
  if (statement_loop.find("continue") != string::npos) {
    printf("ERROR: Continue outside loop in function %s\n", $2.location);
  }
  temp.append(statement_loop);
  temp.append("endfunc\n"); //must end function with endfunc
  
  printf("%s", temp.c_str());
};


declaration: identifier_loop COLON INTEGER
{
  string vars($1.location);
  string temp;
  string tempVar;
  bool cont = true;

  size_t oldpos = 0;
  size_t pos = 0;
  bool isReserved = false;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == string::npos) {
      temp.append(". ");
      tempVar = vars.substr(oldpos,pos);
      temp.append(tempVar);
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(". ");
      tempVar = vars.substr(oldpos, len);
      temp.append(tempVar);
      temp.append("\n");
    }
    for (unsigned int i = 0; i < reservedWords.size(); ++i) {
      if (reservedWords.at(i) == tempVar) {
        isReserved = true;
      }
    } 
    if (variables.find(tempVar) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
      yyerror(temp);
    }
    else if (isReserved){
      char temp[128];
      snprintf(temp, 128, "Invalid declaration of reserved words %s", tempVar.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(tempVar,0));
    }
    
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);	      
}
| identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER
{
  // Check if declaring arrays of size <= 0 
  if ($5 <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  string vars($1.location);
  string temp;
  string tempVar;
  bool cont = true;

  size_t oldpos = 0;
  size_t pos = 0;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == string::npos) {
      temp.append(".[] ");
      tempVar = vars.substr(oldpos, pos);
      temp.append(tempVar);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      tempVar = vars.substr(oldpos, len);
      temp.append(tempVar);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
    }
    if (variables.find(tempVar) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(tempVar,$5));
    }
      
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);	      
}
| identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER 
{
  if ($5 <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  string vars($1.location);
  string temp;
  string tempVar;
  bool cont = true;

  size_t oldpos = 0;
  size_t pos = 0;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == string::npos) {
      temp.append(".[] ");
      tempVar = vars.substr(oldpos, pos);
      temp.append(tempVar);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      tempVar = vars.substr(oldpos, len);
      temp.append(tempVar);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
    }
    if (variables.find(tempVar) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(tempVar,$5));
    }
      
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);	  

};

declaration_loop: %empty
{
  $$.code = strdup(empty);
  $$.location = strdup(empty);
}
| declaration_loop declaration SEMICOLON

{ 
  string temp;
  temp.append($1.code);
  temp.append($2.code);
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);
};

identifier_loop: identifier
{
  $$.location = strdup($1.location);
  $$.code = strdup(empty);
}
| identifier_loop identifier COMMA
{
  string temp;
  temp.append($1.location);
  temp.append($2.location);
  temp.append("|");
  
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
}

statement_loop: statement_loop statement SEMICOLON
{
  string temp;
  temp.append($1.code);
  temp.append($2.code);

  $$.code = strdup(temp.c_str());
}
| statement SEMICOLON
{
  string temp;
  temp.append($1.code);

  $$.code = strdup(temp.c_str());
};

statement: var ASSIGN expression
{
  string temp;
  temp.append($1.code);
  temp.append($3.code);
  string intermediate = $3.location;
  if ($1.array && $3.array) {
    intermediate = newTemp();
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append($3.location);
    temp.append("\n");
    temp.append("[]= ");
  }
  else if ($1.array) {
    temp.append("[]= ");
  }
  else if ($3.array) {
    temp.append("=[] ");
  }
  else {
    temp.append("= ");
  }
  temp.append($1.location);
  temp.append(", ");
  temp.append(intermediate);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| IF bool_exp THEN statement_loop else_statement ENDIF
{
  string then_begin = newLabel();
  string after = newLabel();
  string temp;

  temp.append($2.code);
  temp.append("?:= ");
  temp.append(then_begin);
  temp.append(", ");
  temp.append($2.location);
  temp.append("\n");
  temp.append($5.code);
  temp.append(":= ");
  temp.append(after);
  temp.append("\n");
  temp.append(": ");
  temp.append(then_begin);
  temp.append("\n");
  temp.append($4.code);
  temp.append(": ");
  temp.append(after);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
}		 
| WHILE bool_exp BEGINLOOP statement_loop ENDLOOP
{
  string temp;
  string beginWhile = newLabel();
  string beginLoop = newLabel();
  string endLoop = newLabel();
  string statement = $4.code;
  string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append($2.code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append($2.location);
  temp.append("\n");
  temp.append(":= ");
  temp.append(endLoop);
  temp.append("\n");
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  temp.append(statement);
  temp.append(":= ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append(": ");
  temp.append(endLoop);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp
{
  string temp;
  string beginLoop = newLabel();
  string beginWhile = newLabel();
  string statement = $3.code;
  string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  temp.append(statement);
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append($6.code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append($6.location);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
}
| FOR identifier_variable IN identifier BEGINLOOP statement_loop ENDLOOP
{
  string temp;
  string count = newTemp();
  string check = newTemp();
  string begin = newLabel();
  string beginLoop = newLabel();
  string increment = newLabel();
  string endLoop = newLabel();
  string statement = $6.code;
  string jump;
  jump.append(":= ");
  jump.append(increment);
  while (statement.find("continue") != string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  if (variables.find(string($4.location)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared tempVar %s", $4.location);
    yyerror(temp);
  }
  else if (variables.find(string($4.location))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Use of scalar tempVar %s in for", $4.location);
    yyerror(temp);
  }

  temp.append(". ");
  temp.append($2.location);
  temp.append("\n");
  temp.append(". ");
  temp.append(check);
  temp.append("\n");
  temp.append(". ");
  temp.append(count);
  temp.append("\n");
  temp.append("= ");
  temp.append(count);
  temp.append(", 0");
  temp.append("\n");
  temp.append(": ");
  temp.append(begin);
  temp.append("\n");
  temp.append("< ");
  temp.append(check);
  temp.append(", ");
  temp.append(count);
  temp.append(", ");
  temp.append(to_string(variables.find(string($4.location))->second));
  temp.append("\n");
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append(check);
  temp.append("\n");
  temp.append(":= ");
  temp.append(endLoop);
  temp.append("\n");
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  temp.append("=[] ");
  temp.append($2.location);
  temp.append(", ");
  temp.append($4.location);
  temp.append(", ");
  temp.append(count);
  temp.append("\n");
  temp.append(statement);
  temp.append(": ");
  temp.append(increment);
  temp.append("\n");
  temp.append("+ ");
  temp.append(count);
  temp.append(", ");
  temp.append(count);
  temp.append(", 1\n");
  temp.append(":= ");
  temp.append(begin);
  temp.append("\n");
  temp.append(": ");
  temp.append(endLoop);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
}
| READ var_loop
{
  string temp = $2.code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == string::npos)
      break;
    temp.replace(pos, 1, "<");
  } while (true);

  $$.code = strdup(temp.c_str());
}
| WRITE var_loop
{
  string temp = $2.code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == string::npos)
      break;
    temp.replace(pos, 1, ">");
  } while (true);

  $$.code = strdup(temp.c_str());
}
| CONTINUE
{
  string temp = "continue\n";
  $$.code = strdup(temp.c_str());
}
| RETURN expression
{
  string temp;
  temp.append($2.code);
  temp.append("ret ");
  temp.append($2.location);
  temp.append("\n");
  $$.code = strdup(temp.c_str());
};


else_statement: %empty
{
  $$.code = strdup(empty);
}
| ELSE statement_loop
{
  $$.code = strdup($2.code);
};

var: identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET
{
  if (variables.find(string($1.location)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared tempVar %s", $1.location);
    yyerror(temp);
  }
  else if (variables.find(string($1.location))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Indexing a non-array tempVar %s", $1.location);
    yyerror(temp);
  }

  string temp;
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);

  $$.code = strdup($3.code);
  $$.location = strdup(temp.c_str());
  $$.array = true;
}
| identifier
{
  if (variables.find(string($1.location)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared tempVar %s", $1.location);
    yyerror(temp);
  }
  else if (variables.find(string($1.location))->second > 0) {
    char temp[128];
    snprintf(temp, 128, "Failed to provide index for array tempVar %s", $1.location);
    yyerror(temp);
  }

  $$.code = strdup(empty);
  $$.location = strdup($1.location);
  $$.array = false;
};

var_loop: var
{
  string temp;
  temp.append($1.code);
  if ($1.array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append($1.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);
}
| var_loop var COMMA
{
  //cgheck this one 
  //not sure
  string temp;
  temp.append($2.code);
  if ($2.array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append($1.location);
  temp.append("\n");
  temp.append($1.code);
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);
};

expression: mult_exp
{
  $$.code = strdup($1.code);
  $$.location = strdup($1.location);
}
| expression ADD mult_exp
{
  $$.location = strdup(newTemp().c_str());
  
  string temp;
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  temp.append("+ ");
  temp.append($$.location);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| expression SUB mult_exp
 { //TAGSOCCER HEHE69
  $$.location = strdup(newTemp().c_str());
  
  string temp;
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  temp.append("- ");
  temp.append($$.location);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
};

exp_loop: %empty
{
  $$.code = strdup(empty);
  $$.location = strdup(empty);
}
| exp_loop expression COMMA 
{
  string temp;
  temp.append($2.code);
  temp.append("param ");
  temp.append($2.location);
  temp.append("\n");
  temp.append($1.code);

  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);
} 
| expression 
{  string temp;
  temp.append($1.code);
  temp.append("param ");
  temp.append($1.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
  $$.location = strdup(empty);
};


mult_exp: term
{
  $$.code = strdup($1.code);
  $$.location = strdup($1.location);
}
| mult_exp MULT term
{
  $$.location = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("* ");
  temp.append($$.location);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| mult_exp DIV term
{
  $$.location = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("/ ");
  temp.append($$.location);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| mult_exp MOD term
{
  $$.location = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("% ");
  temp.append($$.location);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
};


term: var
{
  // array? or not an array? will we ever know?
  if ($$.array == true) {
    string temp;
    string intermediate = newTemp();
    temp.append($1.code);
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append($1.location);
    temp.append("\n");
    $$.code = strdup(temp.c_str());
    $$.location = strdup(intermediate.c_str());
    $$.array = false;
  }
  else {
    $$.code = strdup($1.code);
    $$.location = strdup($1.location);
  }
}
| SUB var
{
  // array? or not an array? will we ever know?
  $$.location = strdup(newTemp().c_str());
  string temp;
  temp.append($2.code);
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  if ($2.array) {
    temp.append("=[] ");
    temp.append($$.location);
    temp.append(", ");
    temp.append($2.location);
    temp.append("\n");
  }
  else {
    temp.append("= ");
    temp.append($$.location);
    temp.append(", ");
    temp.append($2.location);
    temp.append("\n");
  }
  temp.append("* ");
  temp.append($$.location);
  temp.append(", ");
  temp.append($$.location);
  temp.append(", -1\n");
  
  $$.code = strdup(temp.c_str());
  $$.array = false;
}
| number
{
  $$.code = strdup(empty);
  $$.location = strdup(to_string($1).c_str());
}
| SUB number
{
  string temp;
  temp.append("-");
  temp.append(to_string($2));
  $$.code = strdup(empty);
  $$.location = strdup(temp.c_str());
}
| L_PAREN expression R_PAREN
{
  $$.code = strdup($2.code);
  $$.location = strdup($2.location);
}
| SUB L_PAREN expression R_PAREN
{
  $$.location = strdup($3.location);
  string temp;
  temp.append($3.code);
  temp.append("* ");
  temp.append($3.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append(", -1\n");
  $$.code = strdup(temp.c_str());
}
| identifier L_PAREN exp_loop R_PAREN
{
  if (functions.find(string($1.location)) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared function %s", $1.location);
    yyerror(temp);
  }

  $$.location = strdup(newTemp().c_str());

  string temp;
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.location);
  temp.append("\n");
  temp.append("call ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($$.location);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
};

bool_exp: relation_and_exp 
{
  $$.location = strdup($1.location);
  $$.code = strdup($1.code);
}
| relation_and_exp OR bool_exp
{
  string dest = newTemp();
  string temp;

  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("|| ");
  temp.append(dest);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(dest.c_str());
};

relation_and_exp: relation_exp
{
  $$.location = strdup($1.location);
  $$.code = strdup($1.code);
}
| relation_exp AND relation_and_exp
{
  string dest = newTemp();
  string temp;

  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("&& ");
  temp.append(dest);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");
  $$.code = strdup(temp.c_str());
  $$.location = strdup(dest.c_str());
};

relation_exp: NOT relation_exp_not 
{
  string dest = newTemp();
  string temp;

  temp.append($2.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("! ");
  temp.append(dest);
  temp.append(", ");
  temp.append($2.location);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(dest.c_str());
}
| relation_exp_not
{
  $$.location = strdup($1.location);
  $$.code = strdup($1.code);
};

relation_exp_not: expression comp expression
{
  string dest = newTemp();
  string temp;  
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  temp.append($2.location);
  temp.append(dest);
  temp.append(", ");
  temp.append($1.location);
  temp.append(", ");
  temp.append($3.location);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.location = strdup(dest.c_str());
}
| TRUE
{
  char temp[2] = "1";
  $$.location = strdup(temp);
  $$.code = strdup(empty);
}
| FALSE
{
  char temp[2] = "0";
  $$.location = strdup(temp);
  $$.code = strdup(empty);
}
| L_PAREN bool_exp R_PAREN
{
  $$.location = strdup($2.location);
  $$.code = strdup($2.code);
};

comp: EQ
{
  string temp = "== ";
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| NEQ
{
  string temp = "!= ";
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| LT
{
  string temp = "< ";
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| GT
{
  string temp = "> ";
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| LTE
{
  string temp = "<= ";
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| GTE
{
  string temp = ">= ";
  $$.location = strdup(temp.c_str());
  $$.code = strdup(empty);
};

identifier: IDENT
{
  $$.location = strdup($1);
  $$.code = strdup(empty);;
};
identifier_variable: IDENT
{
  string tempVar($1);
  if (variables.find(tempVar) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
    yyerror(temp);
  }
  else {
    variables.insert(pair<string,int>(tempVar,0));
  }
  $$.location = strdup($1);
  $$.code = strdup(empty);;
};
function_identifier: IDENT
{
  if (functions.find(string($1)) != functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of function %s", $1);
    yyerror(temp);
  }
  else {
    functions.insert(pair<string,int>($1,0));
  }
  $$.location = strdup($1);
  $$.code = strdup(empty);;
}
%%

void yyerror(const char* s) {
   printf("ERROR: %s at symbol \"%s\" on line %d, col %d\n", s, yytext, line, position);
}

string newTemp() {
  static int count = 0;
  return "__temp__" + to_string(count++);
}

string newLabel() {
  static int count = 0;
  return "__label__" + to_string(count++);
}
		 
int main(int argc, char ** argv) {
	if (argc >= 2) {
		yyin = fopen(argv[1], "r");
		if (yyin == NULL) {
			yyin = stdin;
		}
	}
	else {
	    yyin = stdin;
	}
    yyparse();
    return 0;
}
