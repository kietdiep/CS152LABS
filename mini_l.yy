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
%token BEGINPARAMS
%token ENDPARAMS
%token INTEGER
%token ARRAY
%token OF
%token BEGINLOCALS
%token ENDLOCALS
%token BEGINBODY
%token ENDBODY
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

%token MINUS
%token ADD
%token MULTIPLICATION
%token DIVISION
%token MOD
%token EQUAL
%token POINTED_BRACKETS
%token LESS_THAN_BRACKET
%token GREATER_THAN BRACKET
%token LESS_THAN_OR_EQUAL
%token GREATER_THAN_OR_EQUAL
%token L_PARENTHASIS
%token R_PARENTHASIS
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

%start prog_start;

	/* define your grammars here use the same grammars 
	 * you used in Phase 2 and modify their actions to generate codes
	 * assume that your grammars start with prog_start
	 */

prog_start: 
	|
	PROGRAM {cout << "program starting here" << endl;}
	;

identifier: 
	IDENT {cout << "ident -> IDENT " << $1 << endl;}
	;



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

