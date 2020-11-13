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
/*#include <list>*/
#include <string>
#include <functional>
	/* define the sturctures using as types for non-terminals */

	/* end the structures for non-terminal types */
}


%code
{
#include "y.tab.hh"

	/* you may need these header files 
	 * add more header file if you need more
	 */
#include <sstream>
#include <map>
#include <regex>
#include <set>

using namespace std;
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

%start program
	/* define your grammars here use the same grammars 
	 * you used in Phase 2 and modify their actions to generate codes
	 * assume that your grammars start with prog_start
	 */
%%
program: {cout << "program -> epsilon" << endl;} 
	|program function {cout << "program -> functions" << endl;}
	;

function: FUNCTION identifier SEMICOLON BEGIN_PARAMS declaration_loop END_PARAMS BEGIN_LOCALS declaration_loop END_LOCALS BEGIN_BODY statement_loop END_BODY {cout << "function -> FUNCTION identifier SEMICOLON BEGINPARAMS declaration_loop ENDPARAMS BEGINLOCALS declaration_loop ENDLOCALS BEGIN_BODY statement_loop ENDBODY" << endl;}
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
	|identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER {cout << "declaration -> identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET OF INTEGER" << endl;}
	|identifier_loop COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER {cout << "declaration -> identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER" << endl;}
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
	;

relation_and_exp: relation_exp {cout << "bool_exp -> relation_exp" <<endl;}
        |relation_exp OR relation_and_exp {cout << "bool_exp -> relation_exp OR relation_and_exp" <<endl;} /*having relation_and_exp at the end makes more sense to me but  could be wrong*/
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
	|GTE {cout << "comp -> GTE" << endl;}
	;

expression: mult_exp {cout << "expression -> mult_exp" << endl;}
	|mult_exp add_mult_loop {cout << "expression -> mult_exp add_mult_loop" << endl;}
	|mult_exp sub_mult_loop {cout << "expression -> mult_exp sub_mult_loop" << endl;}
	;

add_mult_loop:  ADD expression {cout << "add_mult_loop -> ADD mult_exp" << endl;}
; /*This may work but we will have to consult with our TA*/

sub_mult_loop: SUB expression {cout << "sub_mult_loop -> SUB mult_exp" << endl;}
; /*This may work but we will have to consult with our TA*/

mult_exp: term {cout << "mult_exp -> term" << endl;}
	| term mult_mult_loop {cout << "mult_exp -> term MULT term" << endl;}
	| term div_mult_loop {cout << "mult_exp -> term DIV term" << endl;}
	| term mod_mult_loop {cout << "mult_exp -> term MOD term" << endl;}
;

mult_mult_loop:
;

div_mult_loop:
;

mod_mult_loop:
;

term: identifier L_PAREN exp_loop R_PAREN {cout << "term -> identifier L_PAREN exp_loop R_PAREN" << endl;}
	|SUB var {cout << "term -> SUB var" << endl;}
	|var {cout << "term -> var" << endl;}
	|SUB number {cout << "term -> SUB number" << endl;}
        |number {cout << "term -> number" << endl;}
	|SUB L_PAREN expression R_PAREN {cout << "term -> SUB L_PAREN expression R_PAREN" << endl;}
        |L_PAREN expression R_PAREN {cout << "term -> L_PAREN expression R_PAREN" << endl;}


exp_loop: {cout << "exp_loop -> epsilon" << endl;}
	|exp_loop expression COMMA {cout << "exp_loop -> exp_loop expression COMMA" << endl;}
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

