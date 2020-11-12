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
#include <list>
#include <string>
#include <functional>
	/* define the sturctures using as types for non-terminals */

	/* end the structures for non-terminal types */
}


%code
{
#include "parser.tab.hh"

	/* you may need these header files 
	 * add more header file if you need more
	 */
#include <sstream>
#include <map>
#include <regex>
#include <set>
yy::parser::symbol_type yylex();

	/* define your symbol table, global variables,
	 * list of keywords or any function you may need here */
	
	/* end of your code */
}

%token END 0 "end of file";

	/* specify tokens, type of non-terminals and terminals here */
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
	
%%

%start program
	/* define your grammars here use the same grammars 
	 * you used in Phase 2 and modify their actions to generate codes
	 * assume that your grammars start with prog_start
	 */

program: {cout << "program -> epsilon" << endl;} 
	|program function {cout << "program -> functions" << endl;}
	;

function: FUNCTION identifier SEMICOLON BEGINPARAMS declaration_loop ENDPARAMS BEGINLOCALS declaration_loop ENDLOCALS BEGINBODY statement_loop ENDBODY {cout << "function -> FUNCTION identifier SEMICOLON BEGINPARAMS declaration_loop ENDPARAMS BEGINLOCALS declaration_loop ENDLOCALS BEGINBODY statement_loop ENDBODY" << endl;}
	;

identifier: 
	IDENT {cout << "ident -> IDENT " << $1 << endl;}
	;

number:
	NUMBER {cout << "number -> NUMBER " << $1 << endl;} /*make sure this is right*/
	;

declaration_loop: {cout << "declaration_loop -> epsilon" << endl;}
	|declaration_loop declaration SEMICOLON {cout << "declaration_loop -> declaration_loop declaration SEMICOLON" << endl;}
	;

statement_loop: statement SEMICOLON {cout << "statement -> SEMICOLON";}
	|statement_loop statement SEMICOLON {cout << "statement_loop -> statement_loop statement SEMICOLON" << endl;}/*could be worng recursion*/
	;


declaration: identifier_loop COLON INTEGER {cout << "declaration -> identifier_loop COLON INTEGER" << endl;}
	|identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET OF INTEGER {cout << "declaration -> identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET OF INTEGER" << endl;}
	|identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER {cout << "declaration -> identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER" cout << endl;}
	;

identifier_loop: identifier {cout << "identifier_loop -> identifier" << endl;}
	|identifier_loop identifier COMMA {cout << "identifier_loop -> identifier_loop identifier COMMA" << endl;}
	;

statement: var ASSIGN expression {cout << "statement  -> var ASSIGN expression" << endl;}
	|IF bool_exp THEN statement_loop ENDIF {cout << "statement -> IF bool_exp THEN statement_loop ENDIF" << endl;}
	|IF bool_exp THEN statement_loop ELSE statement_loop ENDIF {cout << "statement -> IF bool_exp THEN statement_loop ELSE statement_loop ENDIF" << endl;}
	|WHILE bool_exp BEGINLOOP statement_loop ENDLOOP {cout << "statement -> WHILE bool_exp BEGINLOOP statement_loop ENDLOOP" << endl;}
	|DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp {cout << "statement -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp" << endl;} 
	|FOR var ASSIGN number SEMICOLON bool_exp SEMICOLON var ASSIGN expression BEGINLOOP statement_loop ENDLOOP {cout<< "statement -> FOR var ASSIGN number SEMICOLON bool_exp SEMICOLON var ASSIGN expression BEGINLOOP statement_loop ENDLOOP" << endl;}
	|READ var_loop  {cout << "statement -> READ var_loop" << endl;}
	|WRITE var_loop  {cout << "statement -> WRITE var_loop" << endl;} 
	|CONTINUE {cout << "statement -> continue" << endl;}
	|RETURN expression {cout << "statement -> RETURN expression" << endl;}
	;

var_loop: var {cout << "var_loop -> var" << endl;}
	|var_loop var COMMA {cout << "var_loop -> var_loop var COMMA" << endl;} /*could be worng recursion*/
	;

bool_exp: relation_and_exp {cout << "bool_exp -> relation_and_exp" <<endl;}
	|relation_and_exp OR bool_exp {cout << "bool_exp -> relation_and_exp OR bool_exp" <<endl;} /*having bool_exp at the end makes more sense to me but  could be wrong*/












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

