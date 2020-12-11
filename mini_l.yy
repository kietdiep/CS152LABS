%{
%}

%skeleton "lalr1.cc"
%require "3.0.4"
%defines
%define api.token.constructor
%define api.value.type variant
%define parse.error verbose
%locations


%code requires
{
	/* you may need these header files 
	 * add more header file if you need more
	 */
#include <iostream>
#include <list>
#include <string>
#include <functional>
using namespace std;
	/* define the sturctures using as types for non-terminals */
	struct dec_type{
		string code;
		list<string> ids;
	};
	/* end the structures for non-terminal types */
}


%code
{
#include "y.tab.hh"
struct tests
{
	string name;
	yy::location loc;
};
	/* you may need these header files 
	 * add more header file if you need more
	 */
#include <sstream>
#include <map>
#include <regex>
#include <set>


yy::parser::symbol_type yylex();
void yyerror(const char *msg);
	
	/* define your symbol table, global variables,
	 * list of keywords or any function you may need here */
	
	/* end of your code */
}
/* Used to give tokens a type */
/* specify tokens, type of non-terminals and terminals here
* end of token specifications
* tokens, bison makes these constant variables
*/
%token END 0 "end of file";

%token FUNCTION
/*%token DECLARATION*/
%token IDENTIFIER
%token BEGIN_PARAMS
%token END_PARAMS
%token INTEGER
%token ARRAY
%token OF
%token BEGIN_LOCALS
%token END_LOCALS
%token BEGIN_BODY
%token END_BODY
%token RETURN
%token BEGINLOOP
%token ENDLOOP
%token CONTINUE
%token EXIT
%token READ
%token WRITE

%token OR
%token AND
%token NOT
%token TRUE
%token FALSE
%token FOR
%token DO
%token IF
%token THEN
%token ENDIF
%token ELSEIF
%token ELSE
%token WHILE

%token SUB
%token ADD
%token MULT
%token DIV
%token MOD
%token EQ
%token NEQ
%token LT
%token GT
%token LTE
%token GTE
%token L_PAREN
%token R_PAREN
%token COMMA
%token SEMICOLON
%token COLON
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token ASSIGN


%token <int> NUMBER
%token <string> IDENT
	/* end of token specifications */

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

%type <string> program function identifier statement_loop statement
%type <dec_type> declarations declaration
%type <list<string>> identifier_loop

%start program
	/* define your grammars here use the same grammars 
	 * you used in Phase 2 and modify their actions to generate codes
	 * assume that your grammars start with prog_start
	 */
%%
program: {$$ = "";} /*for epsilon*/ 
	|program function {$$ = $1 + "\n" + $2;}
	;

function: FUNCTION identifier SEMICOLON BEGIN_PARAMS declaration_loop END_PARAMS BEGIN_LOCALS declaration_loop END_LOCALS BEGIN_BODY statement_loop END_BODY 
	{
	$$ = "func " + $2 + "\n";
	$$ += $5.code;
	int i = 0;
	for(list<string>::iterator it = $5.ids.begin(); it != $5.ids.end(); it++){
		$$ += "= " + *it + ", $" + to_string(i) + "\n";
		i++;
	}
	$$ += $8.code;
	$$ += $11;
	$$ += "endfunc";
	}
	;

identifier: 
	IDENT {$$ = $1;}
	;

number:
	NUMBER {cout << "number -> NUMBER " << $1 << endl;} /*make sure this is right and/or neccesary*/
	;

declaration_loop: 
	/*for epsilon*/ 
	{
	$$.code = "";
	$$.ids = list<string>();
	}
	|declaration_loop declaration SEMICOLON 
	{
	/* Note: Since our code is different from TA's changed $3 to $2 because of the order of declaration_loop and declaration. Not sure if we should change or not */
	$$.code = $1.code + "\n" + $2.code;
	$$.ids = $1.ids;
	for(list<string>::iterator it = $2.ids.begin(); it != $2.ids.end(); i++) {
		$$.ids.push_back(*it);
	} 	
	}
	;

statement_loop: statement SEMICOLON 
	{
	$$ = $1; 
	}
	|statement_loop statement SEMICOLON 
	{
	$$ = $1 + "\n" + $2;
	}
	;


declaration: identifier_loop COLON INTEGER
        {
        for(list<string>::iterator it = $1.begin(); it != $1.end(); i++) {
                $$.code += ". " + *it + "\n";
                $$.ids.push_back(*it);
        }
        }
	|identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER 
	{
	for(list<string>::iterator it = $1.begin(); it != $1.end(); i++) {
		$$.code += ".[] " + *it + ", " + to_string($5) + "\n";
		$$.ids.push_back(*it);
	}
	}
	|identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER 
	{
	for(list<string>::iterator it = $1.begin(); it != $1.end(); i++) {
                $$.code += ".[] " + *it + ", " + to_string($5*$8) + "\n";
                $$.ids.push_back(*it);
        }
	/*confused why u multiplied $5 and $8 */
	}
	;

identifier_loop: identifier 
	{
	$$.push_back($1);
	}
	|identifier_loop identifier COMMA 
	{
	/* Note: Ta's code is identifier_loop COMMA identifier, but ours is id_loop id COMMA, so changed $$ = $2, $$.push_front($1) */
	$$ = $2;
	$$.push_front($1);
	}
	;

statement: var ASSIGN expression 
	{
	$$ = $1 /*ordered first var and then expression?*/
	$$.push_back($3);
	}
	|IF bool_exp THEN statement_loop ENDIF 
	{
	$$.push_back($1);
	$$ += $4;
	}
	|IF bool_exp THEN statement_loop ELSE statement_loop ENDIF 
	{
	/*$$.push_back($1);*/ /*want to specify which statement loop i go to*/
	if($1 == true) {
	$$ += $4;
	}
	else {
	$$ += $6;
	}
	}
	|WHILE bool_exp BEGINLOOP statement_loop ENDLOOP {cout << "statement -> WHILE bool_exp BEGINLOOP statement_loop ENDLOOP" << endl;}
	|DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp {cout << "statement -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp" << endl;} 
	|FOR var ASSIGN number SEMICOLON bool_exp SEMICOLON var ASSIGN expression BEGINLOOP statement_loop ENDLOOP {cout<< "statement -> FOR var ASSIGN number SEMICOLON bool_exp SEMICOLON var ASSIGN expression BEGINLOOP statement_loop ENDLOOP" << endl;}
	|READ var_loop  {cout << "statement -> READ var_loop" << endl;}
	|WRITE var_loop  {cout << "statement -> WRITE var_loop" << endl;} 
	|CONTINUE {cout << "statement -> continue" << endl;}
	{
	$$ = $1;
	}
	|RETURN expression {cout << "statement -> RETURN expression" << endl;}
	;

var_loop: var 
	{
	$$.push_back($1);
	}
	
	|var_loop var COMMA 
	{
	$$ = $1;
        $$.push_front($2);
	}
	;

bool_exp: relation_and_exp {cout << "bool_exp -> relation_and_exp" <<endl;}
	|relation_and_exp OR bool_exp {cout << "bool_exp -> relation_and_exp OR bool_exp" <<endl;} /*having bool_exp at the end makes more sense to me but  could be wrong*/
	;

relation_and_exp: relation_exp {cout << "bool_exp -> relation_exp" <<endl;}
        |relation_exp AND relation_and_exp {cout << "bool_exp -> relation_exp AND relation_and_exp" <<endl;} /*having relation_and_exp at the end makes more sense to me but  could be wrong*/
	;

relation_exp: NOT expression comp expression {cout << "relation_exp -> NOT expression comp expression" << endl;}
	|expression comp expression {cout << "relation_exp -> expression comp expression" << endl;}
	|NOT TRUE {cout << "relation_exp -> NOT TRUE" << endl;}
	|TRUE {cout << "relation_exp -> TRUE" << endl;}
	|NOT FALSE {cout << "relation_exp -> NOT FALSE" << endl;}
	|FALSE {cout << "relation_exp -> FALSE" << endl;}
	|NOT L_PAREN bool_exp R_PAREN {cout << "relation_exp -> NOT L_PAREN bool_exp R_PAREN" << endl;}
	|L_PAREN bool_exp R_PAREN {cout << "relation_exp -> L_PAREN bool_exp R_PAREN" << endl;}
	;
	
comp: EQ {cout << "comp -> EQ" << endl;}
	|NEQ {cout << "comp -> NEQ" << endl;}
	|LT {cout << "comp -> LT" << endl;}
	|GT {cout << "comp -> GT" << endl;}
	|LTE {cout << "comp -> LTE" << endl;}
	|var {cout << "term -> var" << endl;}
	|SUB number {cout << "term -> SUB number" << endl;}
        |number {cout << "term -> number" << endl;}
	|SUB L_PAREN expression R_PAREN {cout << "term -> SUB L_PAREN expression R_PAREN" << endl;}
        |L_PAREN expression R_PAREN {cout << "term -> L_PAREN expression R_PAREN" << endl;}

expression: mult_exp {cout << "expression -> mult_exp" << endl;}
	|expression ADD mult_exp {cout << "expression -> expression ADD mult_exp" << endl;}
	|expression SUB mult_exp {cout << "expression -> expression SUB mult_exp" << endl;}
	;
mult_exp: term {cout << "mult_exp -> term" << endl;}
	| mult_exp MULT term {cout << "mult_exp -> mult_exp MULT term" << endl;}
	| mult_exp DIV term {cout << "mult_exp -> mult_exp DIV term" << endl;}
	| mult_exp MOD term {cout << "mult_exp -> mult_exp MOD term" << endl;}
	;
term: identifier L_PAREN exp_loop R_PAREN {cout << "term -> identifier L_PAREN exp_loop R_PAREN" << endl;}
	|SUB var {cout << "term -> SUB var" << endl;}
	|var {cout << "term -> var" << endl;}
	|SUB number {cout << "term -> SUB number" << endl;}
        |number {cout << "term -> number" << endl;}
	|SUB L_PAREN expression R_PAREN {cout << "term -> SUB L_PAREN expression R_PAREN" << endl;}
        |L_PAREN expression R_PAREN {cout << "term -> L_PAREN expression R_PAREN" << endl;}


exp_loop: 
	/*for epsilon*/ 
        {
        $$.code = "";
        $$.ids = list<string>();
        }
	|exp_loop expression COMMA 
	{
        $$ = $1;
        $$.push_front($2);
        }
	;

var: identifier {cout << "var -> identifier" << endl;}
	|identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET {cout << "var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;}
	|identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET {cout << "var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;}
	



%%

int main(int argc, char *argv[])
{
	yy::parser p;
	return p.parse();
}

void yy::parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

