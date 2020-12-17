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

  // maps to 0 for single value and maps to array size  > 0
  map<string, int> variables;
  map<string, int> functions;

  vector<string> reservedWords = {"FUNCTION", 
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
    char* place;
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

%type <expr> identifier identifier_variable function_identifier
%type <expr> declaration_loop declaration identifier_loop var var_loop
%type <stat> statement_loop statement else_statement
%type <expr> expression exp_loop mult_exp term bool_exp relation_and_exp relation_exp relation_exp_not comp

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
%left AND
%left OR 
%right NOT

%token TRUE
%token FALSE
%token RETURN

%left SUB
%left ADD
%left MULT
%left DIV
%left MOD
%left EQ
%left NEQ
%left LT
%left GT
%left LTE
%left GTE

%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token COLON
%token SEMICOLON
%token COMMA
%left ASSIGN

%%  

Program:         %empty
{
  string tempMain = "main";
  if ( functions.find(tempMain) == functions.end()) {
    char temp[128];
    yyerror(temp);
  }
  // Check if user declared vartemp the same as program name
  if (variables.find(string(progStart)) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Declared program name as vartemp.");
    yyerror(temp);
  }
}
| Function Program
{
    // Nothing needed he
};
   
Function:        FUNCTION function_identifier SEMICOLON BEGIN_PARAMS declaration_loop END_PARAMS BEGIN_LOCALS declaration_loop END_LOCALS BEGIN_BODY statement_loop END_BODY
{
  string temp = "func ";            // Need to fix function_identifier
  temp.append($2.place);
  temp.append("\n");
  temp.append($2.code);
  temp.append($5.code);
  // Parameter initalization
  string init_params = $5.code;
  int param_number = 0;
  while (init_params.find(".") != string::npos) {
    size_t pos = init_params.find(".");
    init_params.replace(pos, 1, "=");
    string param = ", $";
    param.append(to_string(param_number++));
    param.append("\n");
    init_params.replace(init_params.find("\n", pos), 1, param);
  }
  temp.append(init_params);
  temp.append($8.code);
  string statement_loop($11.code);
  // Check if there are any leftover continues (test 09)
  if (statement_loop.find("continue") != string::npos) {
    printf("ERROR: Continue outside loop in function %s\n", $2.place);
  }
  temp.append(statement_loop);
  temp.append("endfunc\n");
  
  printf("%s", temp.c_str());
};


declaration:     identifier_loop COLON INTEGER
{
  string vars($1.place);
  string temp;
  string vartemp;
  bool cont = true;

  // Build list of declaration_loop base on list of identifier_loop
  // identifier_loop use "|" as delimeter
  size_t oldpos = 0;
  size_t pos = 0;
  bool isReserved = false;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == string::npos) {
      temp.append(". ");
      vartemp = vars.substr(oldpos,pos);
      temp.append(vartemp);
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(". ");
      vartemp = vars.substr(oldpos, len);
      temp.append(vartemp);
      temp.append("\n");
    }
    //check for reserved keywords (test 05)
    for (unsigned int i = 0; i < reservedWords.size(); ++i) {
      if (reservedWords.at(i) == vartemp) {
        isReserved = true;
      }
    } 
    // Check for redeclaration (test 04) TODO same name as program
    if (variables.find(vartemp) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of vartemp %s", vartemp.c_str());
      yyerror(temp);
    }
    else if (isReserved){
      char temp[128];
      snprintf(temp, 128, "Invalid declaration of reserved words %s", vartemp.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(vartemp,0));
    }
    
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);	      
}
| identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER
{
  // Check if declaring arrays of size <= 0 (test 08)
  if ($5 <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  string vars($1.place);
  string temp;
  string vartemp;
  bool cont = true;

  // Build list of declaration_loop base on list of identifier_loop
  // identifier_loop use "|" as delimeter
  size_t oldpos = 0;
  size_t pos = 0;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == string::npos) {
      temp.append(".[] ");
      vartemp = vars.substr(oldpos, pos);
      temp.append(vartemp);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      vartemp = vars.substr(oldpos, len);
      temp.append(vartemp);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
    }
    // Check for redeclaraion (test 04)
    if (variables.find(vartemp) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of vartemp %s", vartemp.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(vartemp,$5));
    }
      
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);	      
}
| identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER 
{
    // Check if declaring arrays of size <= 0 (test 08)
  if ($5 <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  string vars($1.place);
  string temp;
  string vartemp;
  bool cont = true;

  // Build list of declaration_loop base on list of identifier_loop
  // identifier_loop use "|" as delimeter
  size_t oldpos = 0;
  size_t pos = 0;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == string::npos) {
      temp.append(".[] ");
      vartemp = vars.substr(oldpos, pos);
      temp.append(vartemp);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      vartemp = vars.substr(oldpos, len);
      temp.append(vartemp);
      temp.append(", ");
      temp.append(to_string($5));
      temp.append("\n");
    }
    // Check for redeclaraion (test 04)
    if (variables.find(vartemp) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of vartemp %s", vartemp.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(vartemp,$5));
    }
      
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);	  

};

declaration_loop:    %empty
{
  $$.code = strdup(empty);
  $$.place = strdup(empty);
}
| declaration_loop declaration SEMICOLON

{ 
  // declaration SEMICOLON declaration_loop <- original, take out later
  string temp;
  temp.append($1.code);
  temp.append($2.code);
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
};

identifier_loop:     identifier
{
  $$.place = strdup($1.place);
  $$.code = strdup(empty);
}
| identifier_loop identifier COMMA
{
  // identifier COMMA identifier_loop <- original, take out later
  // use "|" as delimeter
  string temp;
  temp.append($1.place);
  temp.append($2.place);
  temp.append("|");
  
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}

statement_loop:     statement_loop statement SEMICOLON
{
                    // statement SEMICOLON statement_loop <- original, take out later
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

statement:      var ASSIGN expression
{
  string temp;
  temp.append($1.code);
  temp.append($3.code);
  string intermediate = $3.place;
  if ($1.array && $3.array) {
    intermediate = newTemp();
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append($3.place);
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
  temp.append($1.place);
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

  // evaluate expression
  temp.append($2.code);
  // if true goto then label
  temp.append("?:= ");
  temp.append(then_begin);
  temp.append(", ");
  temp.append($2.place);
  temp.append("\n");
  // else code
  temp.append($5.code);
  // goto after
  temp.append(":= ");
  temp.append(after);
  temp.append("\n");
  // then label
  temp.append(": ");
  temp.append(then_begin);
  temp.append("\n");
  // then code
  temp.append($4.code);
  // after label
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
  // replace continue
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
  temp.append($2.place);
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
  // replace continue
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
  temp.append($6.place);
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
  // replace continue
  string statement = $6.code;
  string jump;
  jump.append(":= ");
  jump.append(increment);
  while (statement.find("continue") != string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  // Checks for second ident
  if (variables.find(string($4.place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared vartemp %s", $4.place);
    yyerror(temp);
  }
  // Check if second ident is scalar
  else if (variables.find(string($4.place))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Use of scalar vartemp %s in for", $4.place);
    yyerror(temp);
  }
  // checks for identifier_variable happen in identifier_variable (redeclaration test)

  // Initalize first ident and check
  temp.append(". ");
  temp.append($2.place);
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
  // Check if count is less than size of array
  temp.append(": ");
  temp.append(begin);
  temp.append("\n");
  temp.append("< ");
  temp.append(check);
  temp.append(", ");
  temp.append(count);
  temp.append(", ");
  temp.append(to_string(variables.find(string($4.place))->second));
  temp.append("\n");
  // Jump to begin loop if check is true
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append(check);
  temp.append("\n");
  // Jump to end loop if check is false
  temp.append(":= ");
  temp.append(endLoop);
  temp.append("\n");
  // Begin loop
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");
  // Set first ident to value of second ident
  temp.append("=[] ");
  temp.append($2.place);
  temp.append(", ");
  temp.append($4.place);
  temp.append(", ");
  temp.append(count);
  temp.append("\n");
  // Execute code
  temp.append(statement);
  // Increment
  temp.append(": ");
  temp.append(increment);
  temp.append("\n");
  temp.append("+ ");
  temp.append(count);
  temp.append(", ");
  temp.append(count);
  temp.append(", 1\n");
  // Jump to check
  temp.append(":= ");
  temp.append(begin);
  temp.append("\n");
  // label endLoop
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
  // insert continue on a new line
  // search for continue in loop
  // and replace with := loop check
  string temp = "continue\n";
  $$.code = strdup(temp.c_str());
}
| RETURN expression
{
  string temp;
  temp.append($2.code);
  temp.append("ret ");
  temp.append($2.place);
  temp.append("\n");
  $$.code = strdup(temp.c_str());
};


else_statement:   %empty
{
  $$.code = strdup(empty);
}
| ELSE statement_loop
{
  $$.code = strdup($2.code);
};

var:             identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET
{
  // Check for use of undeclared vartemp (test 01)
  if (variables.find(string($1.place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared vartemp %s", $1.place);
    yyerror(temp);
  }
  // Check for use of single value as array (test 07)
  else if (variables.find(string($1.place))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Indexing a non-array vartemp %s", $1.place);
    yyerror(temp);
  }

  string temp;
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);

  $$.code = strdup($3.code);
  $$.place = strdup(temp.c_str());
  $$.array = true;
}
| identifier
{
  // Check for use of undeclared vartemp (test 01)
  if (variables.find(string($1.place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared vartemp %s", $1.place);
    yyerror(temp);
  }
  // Check for use of array as single value (test 06)
  else if (variables.find(string($1.place))->second > 0) {
    char temp[128];
    snprintf(temp, 128, "Failed to provide index for array vartemp %s", $1.place);
    yyerror(temp);
  }

  $$.code = strdup(empty);
  $$.place = strdup($1.place);
  $$.array = false;
};

/* var_loop is only used by read and write
 * pass back the code ".[]| dst/src"
 * replace "|" with correct < or > depending on read/write
 * in read and write production
 */
var_loop:            var
{
  string temp;
  temp.append($1.code);
  if ($1.array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append($1.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
}
| var_loop var COMMA
{
  // var COMMA var_loop
  // switched the $1 and $2 to match alignment but not sure if order mattered ... pretty sure it does
  string temp;
  temp.append($2.code);
  if ($2.array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append($1.place);
  temp.append("\n");
  temp.append($1.code);
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
};

expression:      mult_exp
{
  $$.code = strdup($1.code);
  $$.place = strdup($1.place);
}
| expression ADD mult_exp
{
  // mult_exp ADD expression ... current code has not changed  $ values yet, will check with tagsoccer
  $$.place = strdup(newTemp().c_str());
  
  string temp;
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append("+ ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| expression SUB mult_exp
{
  // mult_exp SUB expression ... current code has not changed $ values; check with tagsoccer
  $$.place = strdup(newTemp().c_str());
  
  string temp;
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append("- ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
};

// used only for function calls
exp_loop:     %empty
{
  $$.code = strdup(empty);
  $$.place = strdup(empty);
}
| exp_loop expression COMMA 
{
  // expression COMMA exp_loop
  string temp;
  temp.append($1.code);
  temp.append("param ");
  temp.append($1.place);
  temp.append("\n");
  temp.append($3.code);

  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
}
| expression
{
  string temp;
  temp.append($1.code);
  temp.append("param ");
  temp.append($1.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
};


mult_exp:         term
{
  $$.code = strdup($1.code);
  $$.place = strdup($1.place);
}
| mult_exp MULT term
{
  //term MULT mult_exp <- og code has not changed
  $$.place = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("* ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| mult_exp DIV term
{
  // term DIV mult_exp <- og code has not changed
  $$.place = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("/ ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| mult_exp MOD term
{
  // term MOD mult_exp <- og code has not changed
  $$.place = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("% ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
};


term:            var
{
  // var can be an array or not
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
    temp.append($1.place);
    temp.append("\n");
    $$.code = strdup(temp.c_str());
    $$.place = strdup(intermediate.c_str());
    $$.array = false;
  }
  else {
    $$.code = strdup($1.code);
    $$.place = strdup($1.place);
  }
}
| SUB var
{
  // var can either be an array or not an array
  $$.place = strdup(newTemp().c_str());
  string temp;
  temp.append($2.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  if ($2.array) {
    temp.append("=[] ");
    temp.append($$.place);
    temp.append(", ");
    temp.append($2.place);
    temp.append("\n");
  }
  else {
    temp.append("= ");
    temp.append($$.place);
    temp.append(", ");
    temp.append($2.place);
    temp.append("\n");
  }
  temp.append("* ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($$.place);
  temp.append(", -1\n");
  
  $$.code = strdup(temp.c_str());
  $$.array = false;
}
| number
{
  $$.code = strdup(empty);
  $$.place = strdup(to_string($1).c_str());
}
| SUB number
{
  string temp;
  temp.append("-");
  temp.append(to_string($2));
  $$.code = strdup(empty);
  $$.place = strdup(temp.c_str());
}
| L_PAREN expression R_PAREN
{
  $$.code = strdup($2.code);
  $$.place = strdup($2.place);
}
| SUB L_PAREN expression R_PAREN
{
  $$.place = strdup($3.place);
  string temp;
  temp.append($3.code);
  temp.append("* ");
  temp.append($3.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append(", -1\n");
  $$.code = strdup(temp.c_str());
}
| identifier L_PAREN exp_loop R_PAREN
{
   // Check for use of undeclared function (test 2)
  if (functions.find(string($1.place)) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared function %s", $1.place);
    yyerror(temp);
  }

  $$.place = strdup(newTemp().c_str());

  string temp;
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append("call ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($$.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
};

bool_exp:         relation_and_exp 
{
  $$.place = strdup($1.place);
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
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
};

relation_and_exp:           relation_exp
{
  $$.place = strdup($1.place);
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
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
};

relation_exp:            NOT relation_exp_not 
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
  temp.append($2.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
}
| relation_exp_not
{
  $$.place = strdup($1.place);
  $$.code = strdup($1.code);
};

relation_exp_not:           expression comp expression
{
  string dest = newTemp();
  string temp;  

  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  temp.append($2.place);
  temp.append(dest);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
}
| TRUE
{
  char temp[2] = "1";
  $$.place = strdup(temp);
  $$.code = strdup(empty);
}
| FALSE
{
  char temp[2] = "0";
  $$.place = strdup(temp);
  $$.code = strdup(empty);
}
| L_PAREN bool_exp R_PAREN
{
  $$.place = strdup($2.place);
  $$.code = strdup($2.code);
};

comp:            EQ
{
  string temp = "== ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| NEQ
{
  string temp = "!= ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| LT
{
  string temp = "< ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| GT
{
  string temp = "> ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| LTE
{
  string temp = "<= ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| GTE
{
  string temp = ">= ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
};

identifier:      IDENT
{
  $$.place = strdup($1);
  $$.code = strdup(empty);;
};
identifier_variable:      IDENT
{
  // Check for redeclaration (test 04) TODO same name as program
  string vartemp($1);
  if (variables.find(vartemp) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of vartemp %s", vartemp.c_str());
    yyerror(temp);
  }
  else {
    variables.insert(pair<string,int>(vartemp,0));
  }
  $$.place = strdup($1);
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
  $$.place = strdup($1);
  $$.code = strdup(empty);;
}
%%

void yyerror(const char* s) {
   printf("ERROR: %s at symbol \"%s\" on line %d, col %d\n", s, yytext, line, position);
}

string newTemp() {
  static int count = 0;
  return "_t" + to_string(++count);
}

string newLabel() {
  static int count = 0;
  return 'L' + to_string(++count);
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
	//yylex();
    yyparse();
    return 0;
}
