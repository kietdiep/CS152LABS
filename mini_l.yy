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


declaration_loop: {cout << "declaration_loop -> epsilon" << endl;}
	|declaration_loop declaration SEMICOLON {cout << "declaration_loop -> declaration_loop declaration SEMICOLON" << endl;}
	;

statement_loop: statement SEMICOLON {cout << "statement -> SEMICOLON";}
	|statement_loop statement SEMICOLON {cout << "statement_loop -> statement_loop statement SEMICOLON" << endl;}
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

