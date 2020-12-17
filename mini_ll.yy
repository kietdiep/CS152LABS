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
	/* you may need these deader files 
	 * add more header file if you need more
	 */

    #include <iostream>
    #include <list>
    #include <string>
    #include <functional>
    #include <vector>
    #include <stdlib.h>
    #include <stdio.h>
    #include <tuple>
    #include <utility>

    #ifndef FOO
    #define FOO

    #define debug false

    void debug_print(std::string msg);
    void debug_print_char(std::string msg, std::string c);
    void debug_print_int(std::string msg, int i);

    std::string concat(std::vector<std::string> strings, std::string prefix, std::string delim);

    enum IdentType {

        INTEGER,
        ARRAY,
        FUNCTION
    };

    void populateKeywords();

    bool isKeyword(std::string str);

    bool isInSymbolTable(std::string name);

    bool checkIdType(std::string id, IdentType type);

    std::string generateTempReg();
    std::string generateTempLabel();

    struct ExprStruct {

    public:

        // std::string original_name;
        std::string reg_name;
        std::vector < std::string > code;

        // ~ExprStruct() {}

        // ExprStruct& operator =(const ExprStruct& other) {

        //     this->reg_name = other.reg_name;
        //     this->code.insert(this->code.end(), other.code.begin(), other.code.end());
        // }

        friend std::ostream& operator <<(std::ostream& out, const ExprStruct& printMe) {
            for (std::string thisLineOfCode : printMe.code)
                out << thisLineOfCode << std::endl;
            return out;
        }
    };
    struct StatementStruct {
    public:
        std::string begin_label;
        std::string end_label;
        std::vector < std::string > code;
    };

    std::ostream& operator <<(std::ostream& out, const std::vector< ExprStruct > & printMe);

    std::ostream& operator <<(std::ostream& out, const std::vector< std::string> & printMe);



	/* define the stuctures using as types for non-terminals */

	/* end the structures for non-terminal types */

    #endif // FOO

}



%code
{
    #include "parser.tab.hh"

    	/* you may need these deader files 
    	 * add more header file if you need more
    	 */
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <map>
    #include <regex>
    #include <set>
    #include <algorithm>
    #include <climits>
    #include <unordered_set>
    #include <stack>

    //extern yy::location loc;

    yy::parser::symbol_type yylex();

    	/* define your symbol table, global variables,
    	 * list of keywords or any function you may need here */
    	
    enum IdentType;

    std::map< std::string, IdentType > symbol_table;
    std::unordered_set < std::string > keywords;            // reserved keywords
    std::stack <std::string> loop_scope;

    bool errorOccurred = false;
    int paramCount = 0;

    
	/* end of your code */
}

%token END 0 "end of file";

	/* specify tokens, type of non-terminals and terminals here */
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER ARRAY OF IF THEN ENDIF ELSE 
%token WHILE DO BEGINLOOP ENDLOOP CONTINUE
%token READ WRITE AND OR NOT TRUE FALSE RETURN
%token ADD SUB MULT DIV MOD
%token EQ NEQ LT GT LTE GTE
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%token <std::string> IDENTIFIER
%token <int> NUMBER

%type  <std::vector<ExprStruct>> declaration_loop var_loop expression_loop
%type  <ExprStruct> program declaration var expression term mult_expr bool_expr relation_and_expr relation_expr

%type  <std::vector<StatementStruct>> statement_loop
%type  <StatementStruct> statement function identifier identifier_loop


%type  <std::string> mulop comp


%right ASSIGN
%left  OR
%left  AND
%right NOT
%left  LT GT LTE GTE EQ NEQ
%left  ADD SUB
%left  MULT DIV MOD
%right UMINUS
%left  L_SQUARE_BRACKET R_SQUARE_BRACKET
%left  L_PAREN R_PAREN
	/* end of token specifications */

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
	IDENTIFIER {$$ = $1;}
	;



declaration_loop: /*deleted a number grammar right above this*/
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
	|identifier_loop COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
	{
	for(list<string>::iterator it = $1.begin(); it != $1.end(); i++) {
		$$.code += ".[] " + *it + ", " + to_string($5) + "\n";
		$$.ids.push_back(*it);
	}
	}
	|identifier_loop COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
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


statement:

    var ASSIGN expression {
        debug_print("statement -> var ASSIGN expression\n"); 
        // ExprStruct es;
        // es.reg_name = generateTempReg();
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());
        // $$.code.push_back(". " + $1.reg_name);
        $$.code.push_back("= " + $1.reg_name + ", " + $3.reg_name);
        // $$ = es;
    }

	| IF bool_expr THEN statement_loop ENDIF {

        debug_print("statement -> IF bool_expr THEN statement_loop ENDIF\n");

        // Before anything else, copy code from bool_expr,
        // and define your own reg_name
        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());
        $$.begin_label = generateTempReg();
        $$.code.push_back(". " + $$.begin_label);

        // Prepare the endif label
        std::string endif_label = generateTempLabel();

        // Compute the negation of the result of bool_expr,
        // which is in $2.reg_name
        std::string negation_reg = generateTempReg();
        $$.code.push_back(". " + negation_reg);
        $$.code.push_back("! " + negation_reg + ", " + $2.reg_name);

        // If negation_neg is true,
        // then bool_expr was false,
        // so jump to endif label
        $$.code.push_back("?:= " + endif_label + ", " + negation_reg);

        // Else if !negation_reg, then bool_expr was true,
        // and you should fall through to the body code
        for (StatementStruct thisStatement : $4) {

            $$.code.insert($$.code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        // After we're done with body code, append the endif label
        $$.code.push_back(": " + endif_label);
        
    
    }

	| IF bool_expr THEN statement_loop ELSE statement_loop ENDIF {

        debug_print("statement -> IF bool_expr THEN statement_loop ELSE statement_loop ENDIF\n");

        // Copy code for evaluating bool_expr
        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());

        // Need 2 labels, else and end
        $$.begin_label = generateTempLabel();   // else
        $$.end_label = generateTempLabel();     // end

        std::string negation_reg = generateTempReg();
        $$.code.push_back(". " + negation_reg);
        $$.code.push_back("! " + negation_reg + ", " + $2.reg_name);

        // If !bool_expr, jump to else
        $$.code.push_back("?:= " + $$.begin_label + ", " + negation_reg);

        // Fall through to code from statement loop
        for (StatementStruct thisStatement : $4) {

            $$.code.insert($$.code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        // Jump to end to avoid else statement
        $$.code.push_back(":= " + $$.end_label /*+ " ; end of if, jump to end"*/);

        $$.code.push_back(": " + $$.begin_label /*+ " ; else label"*/);

        for (StatementStruct thisStatement : $6) {

            $$.code.insert($$.code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        $$.code.push_back(": " + $$.end_label /*+ " ; endif label"*/);

    }

	| WHILE bool_expr BEGINLOOP {loop_scope.push(generateTempLabel());} statement_loop ENDLOOP {

        debug_print("statement -> WHILE bool_expr BEGINLOOP statement_loop ENDLOOP\n");

        StatementStruct css;
        assert(!loop_scope.empty());
        css.begin_label = loop_scope.top();
        std::string middle_label = generateTempLabel();
        css.end_label = generateTempLabel();


        $$.code.push_back(": " + css.begin_label);

        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end()); // bool_expr code

        $$.code.push_back("?:= " + middle_label + ", " + $2.reg_name);
        $$.code.push_back(":= " + css.end_label);
        $$.code.push_back(": " + middle_label);



        for (StatementStruct thisStatement : $5) {

            $$.code.insert($$.code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        $$.code.push_back(":= " + css.begin_label);
        $$.code.push_back(": " + css.end_label);


        $$.begin_label = css.begin_label;
        $$.end_label = css.end_label;

        loop_scope.pop();

    }

	| DO BEGINLOOP { loop_scope.push(generateTempLabel()); } statement_loop ENDLOOP WHILE bool_expr {

        debug_print("statement -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_expr\n");

        StatementStruct ss;
        // ss.begin_label = generateTempLabel();
        assert(!loop_scope.empty());
        ss.end_label = loop_scope.top();
        ss.begin_label = generateTempLabel();

        $$.code.push_back(": " + ss.begin_label);

        // code from statement_loop
        for (StatementStruct thisStatement : $4) {

            $$.code.insert($$.code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        // set end_label to be between end of body code and before bool_expr
        $$.code.push_back(": " + ss.end_label);

        // code from bool_expr
        $$.code.insert($$.code.end(), $7.code.begin(), $7.code.end());

        // if bool_expr, jump to ss.begin_label
        $$.code.push_back("?:= " + ss.begin_label + ", " + $7.reg_name);

        loop_scope.pop();

    }

	| READ var_loop {

        debug_print("statement -> READ var_loop\n");


        for (ExprStruct this_expr_struct : $2) {
            // thisCode.push_back(".< " + this_expr_struct.reg_name);


            //this_expr_struct.reg_name = 

            //$$.code.insert($$.code.end(), this_expr_struct.code.begin(), this_expr_struct.code.end());
            // $$.code.push_back(".< " + this_expr_struct.original_name);
            $$.code.push_back(".< " + this_expr_struct.reg_name);
        }
    }

	| WRITE var_loop {

        debug_print("statement -> WRITE var_loop\n");
        // $$ = concat($2, ".> ", "\n");

        for (ExprStruct this_expr_struct : $2) {
            //$$.code.insert($$.code.end(), this_expr_struct.code.begin(), this_expr_struct.code.end());
            // $$.code.push_back(".> " + this_expr_struct.original_name);
            $$.code.push_back(".> " + this_expr_struct.reg_name);
        }
    }

    | CONTINUE {

        debug_print("statement -> CONTINUE\n");

        // std::cout << "loop_scope size: " << loop_scope.size() << std::endl;

        if (loop_scope.empty()) {

            yy::parser::error(@1, "\'continue\' keyword forbidden outside loops");
        }

        else {

            std::string jump_here = loop_scope.top();
            $$.code.push_back(":= " + jump_here);
        }
    }

    | RETURN expression {

        debug_print("statement -> RETURN expression\n");

        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());
        // $$.reg_name = $2.reg_name;
        $$.begin_label = $2.reg_name;
        $$.code.push_back("ret " + $2.reg_name);

    }
;

var_loop:

    var {

        debug_print("var_loop -> var\n");
        $$.push_back($1);

    }

	| var_loop COMMA var {

        debug_print("var_loop -> var_loop COMMA var\n");
        $$.insert($$.end(), $1.begin(), $1.end());
        $$.push_back($3);
    }
;

bool_expr:	 
    relation_and_expr { 
        debug_print("bool_expr -> relation_and_expr\n");
        $$ = $1;

    }
    | bool_expr OR relation_and_expr {
        debug_print("bool_expr -> bool_expr OR relation_and_expr\n"); 

    }
;

relation_and_expr:
    relation_expr { 
        debug_print("relation_and_expr -> relation_expr\n"); 
        $$ = $1;

    }
    | relation_and_expr AND relation_expr { 
        debug_print("relation_and_expr -> relation_and_expr AND relation_expr\n"); 

    }
;

relation_expr:

    expression comp expression {

        debug_print("relation_expr -> expression comp expression\n");

        $$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);

        $$.code.push_back($2 + " " + $$.reg_name + ", " + $1.reg_name + ", " + $3.reg_name);

    }

	| NOT expression comp expression {

        std::cout << "In relation_expr -> NOT expression comp expression" << std::endl;

        debug_print("relation_expr -> NOT expression comp expression\n");

        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());
        $$.code.insert($$.code.end(), $4.code.begin(), $4.code.end());

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);

        $$.code.push_back($3 + " " + $$.reg_name + ", " + $2.reg_name + ", " + $4.reg_name);

        $$.code.push_back("! " + $$.reg_name + ", " + $$.reg_name);
    }

	| TRUE { 

        debug_print("relation_expr -> TRUE\n");

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);

        $$.code.push_back("= " + $$.reg_name + ", 1");
    }
	| NOT TRUE { debug_print("relation_expr -> NOT TRUE\n"); 

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);

        $$.code.push_back("= " + $$.reg_name + ", 0");
    }
	| FALSE { 
        debug_print("relation_expr -> FALSE\n"); 

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);

        $$.code.push_back("= " + $$.reg_name + ", 0");
    }
	| NOT FALSE { 
        debug_print("relation_expr -> NOT FALSE\n"); 

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);

        $$.code.push_back("= " + $$.reg_name + ", 1");
    }
	| L_PAREN bool_expr R_PAREN { 
        debug_print("relation_expr -> L_PAREN bool_expr R_PAREN\n"); 

        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("= " + $$.reg_name + ", " + $2.reg_name);
    }
;

comp:
    EQ { $$  = "=="; }
	| NEQ { $$  = "!="; }
	| LT { $$  = "<"; }
	| GT { $$  = ">"; }
	| LTE { $$  = "<="; }
	| GTE { $$  = ">="; }
;

expression: 
    mult_expr { debug_print("expression -> mult_expr\n"); 
        $$ = $1;
        //$$.code.push_back("= " + $$.reg_name + ", " + $1.reg_name);
    }
    | expression ADD mult_expr {

        debug_print("expression -> expression ADD mult_expr\n"); 

        $$ = $1;
        $$.reg_name = generateTempReg();
        // $$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("+ " + $$.reg_name + ", " + $1.reg_name + ", " + $3.reg_name);


    }
    | expression SUB mult_expr {

        debug_print("expression -> expression SUB mult_expr\n");

        $$ = $1;
        $$.reg_name = generateTempReg();
        // $$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("- " + $$.reg_name + ", " + $1.reg_name + ", " + $3.reg_name);
    }
;

mult_expr:

    term {
        debug_print("mult_expr -> term\n"); 
        $$ = $1;
    }

    | mult_expr mulop term {
        debug_print_char("mult_expr -> mult_expr %s term\n", $2); 
        $$.reg_name = generateTempReg();
        $$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back($2 + " " + $$.reg_name + ", " + $1.reg_name + ", " + $3.reg_name);

        // std::cout << "In mult_expr -> mult_expr mulop term:" << std::endl
        //     << "term.code.size(): " << $3.code.size() << std::endl
        //     << "term.code[0]: " << $3.code[0] << ", term.code[1]" << $3.code[1] << std::endl
        //     << std::endl;
    }
;

mulop:
    MULT { $$ = "*"; }
	| DIV  { $$ = "/"; }
	| MOD { $$ = "%"; }
;

term:

    var {

        debug_print("term -> var\n"); 
        $$ = $1;
        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("= " + $$.reg_name + ", " + $1.reg_name);

    }
	| SUB var {

        debug_print("term -> SUB var\n");

        $$ = $2;

        std::string twoTemp = generateTempReg();
        $$.code.push_back(". " + twoTemp);
        $$.code.push_back("= " + twoTemp + ", " + "2");

        std::string doubleTemp = generateTempReg();
        $$.code.push_back(". " + doubleTemp);
        $$.code.push_back("= " + doubleTemp + ", " + $2.reg_name);

        // Right now the var is in doubleTemp,
        // and 2 is in twoTemp

        // doubleTemp *= 2
        $$.code.push_back("* " + doubleTemp + ", " + doubleTemp + ", " + twoTemp);

        // Give $$ its own copy of the original var
        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("= " + $$.reg_name + ", " + $2.reg_name);

        // Now, do $$ -= doubleTemp
        $$.code.push_back("- " + $$.reg_name + ", " + $$.reg_name + ", " + doubleTemp);
    }
	| NUMBER {

        debug_print_int("term -> NUMBER %d\n", $1);

        //ExprStruct es;
        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("= " + $$.reg_name + ", " + std::to_string($1));
    }

	| SUB NUMBER { 
        debug_print_int("term -> SUB NUMBER %d\n", $2); 

        ExprStruct number_es;

        // Give number_es.reg_name a register and declare it
        number_es.reg_name = generateTempReg();
        $$.code.push_back(". " + number_es.reg_name);
        $$.code.push_back("= " + number_es.reg_name + ", " + std::to_string($2));

        // Put the result for 0 - number_es.reg_name into $$
        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("- " + $$.reg_name + ", 0, " + number_es.reg_name);

    }
	| L_PAREN expression R_PAREN {

        debug_print("term -> L_PAREN expression R_PAREN\n");

        $$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("= " + $$.reg_name + ", " + $2.reg_name);

    }

	| SUB L_PAREN expression R_PAREN {

        debug_print("term -> SUB L_PAREN expression R_PAREN\n");

        $$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("= " + $$.reg_name + ", " + $3.reg_name);
        $$.code.push_back("- " + $$.reg_name + ", 0, " + $$.reg_name);

    }
	| IDENTIFIER L_PAREN R_PAREN {

        debug_print_char("term -> IDENTIFIER %s L_PAREN R_PAREN\n", $1);

        if (!isInSymbolTable($1)) {

            yy::parser::error(@1, "Function \"" + $1 + "\" has not been declared in the current context");
        }

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("call " + $1 + ", " + $$.reg_name);
    }

	| IDENTIFIER L_PAREN expression_loop R_PAREN {

        debug_print_char("term -> IDENTIFIER %s L_PAREN expression_loop R_PAREN\n", $1);

        if (!isInSymbolTable($1)) {

            yy::parser::error(@1, "Function \"" + $1 + "\" has not been declared in the current context");
        }
        if (!checkIdType($1, IdentType::FUNCTION)) {

            yy::parser::error(@1, "Attempted to call non-function \"" + $1 + "\"");
        }

        for (ExprStruct this_expr_struct : $3) {

            $$.code.insert($$.code.end(), this_expr_struct.code.begin(), this_expr_struct.code.end());
            $$.code.push_back("param " + this_expr_struct.reg_name);
        }

        $$.reg_name = generateTempReg();
        $$.code.push_back(". " + $$.reg_name);
        $$.code.push_back("call " + $1 + ", " + $$.reg_name);

        paramCount = 0;

    }
;

expression_loop:

    expression {

        debug_print("expression_loop -> expression");

        $1.reg_name = generateTempReg();
        $1.code.push_back(". " + $1.reg_name);
        // $1.code.push_back("= " + $1.reg_name + ", $" + paramCount);

        $$.push_back($1);

        paramCount++;
    }

    | expression_loop COMMA expression {

        debug_print("expression_loop -> expression_loop COMMA expression");

        $$ = $1;

        $$.push_back($3);
    }
;
		
var:

    IDENTIFIER {

        debug_print_char("var -> IDENTIFIER %s\n", $1);

        if (!isInSymbolTable($1)) {

            yy::parser::error(@1, "Attempted to use undeclared variable \"" + $1 + "\".");
        }

        else if (checkIdType($1, IdentType::ARRAY)) {

            yy::parser::error(@1, "Attempted to use array variable \"" + $1 + "\" as a non-array variable.");
        }

        ExprStruct es;
        es.reg_name = $1;
        // es.code.push_back(". " + $1);

        $$ = es;
    }

	| IDENTIFIER L_SQUARE_BRACKET expression R_SQUARE_BRACKET {

        debug_print_char("var -> IDENTIFIER %s L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n", $1);

        // $$ = ".[] " + $1 + ", " + $3;
        ExprStruct es;
        // es.original_name = $1;
        es.code.push_back(".[] " + $1 + ", " + $3.reg_name);
        es.reg_name = generateTempReg();

        $$ = es;
    }
;


// going_into_loop: %empty { currentlyInLoop = true; }
// returning_from_loop: %empty { currentlyInLoop = false; }

%%

int main(int argc, char *argv[])
{
	yy::parser p;
	return p.parse();
}

void yy::parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << "Error at location " << l << ": " << m << std::endl;
    errorOccurred = true;
}

void debug_print(std::string msg) {

    if (debug) printf("%s", msg.c_str());
}

void debug_print_char(std::string msg, std::string c) {

    if (debug) printf(msg.c_str(), c.c_str());
}

void debug_print_int(std::string msg, int i) {

    if (debug) printf(msg.c_str(), i);
}

std::string concat(std::vector<std::string> strings, std::string prefix, std::string delim) {

    std::string str = "";

    for (std::string this_str : strings)
        str += prefix + this_str + delim;

    return str;

}

// int Ident::static_id = 0;

bool isKeyword(std::string name) {
    return keywords.find(name) != keywords.end();
}

bool isInSymbolTable(std::string name) {

    return symbol_table.find(name) != symbol_table.end();
}

bool checkIdType(std::string id, IdentType type) {

    if (!isInSymbolTable(id)) return false;

    // If you're here, then id is in the symbol table
    return type == symbol_table.at(id);
}

std::ostream& operator <<(std::ostream& out, const std::vector< ExprStruct > & printMe) {

    for (ExprStruct thisExpr : printMe) {

        out << thisExpr << std::endl;
    }

    return out;
}


std::ostream& operator <<(std::ostream& out, const std::vector< std::string> & printMe) {

    for (std::string thisStr : printMe) {

        out << thisStr << std::endl;
    } 

    return out;
}

std::string generateTempReg() {

    static int i = 0;

    return "__temp__" + std::to_string(i++);
}

std::string generateTempLabel() {

    static int i = 0;

    return "__label__" + std::to_string(i++);
}

void populateKeywords() {

    keywords.insert("function");
    keywords.insert("beginparams");
    keywords.insert("endparams");
    keywords.insert("beginlocals");
    keywords.insert("endlocals");
    keywords.insert("beginbody");
    keywords.insert("endbody");
    keywords.insert("integer");
    keywords.insert("array");
    keywords.insert("of");
    keywords.insert("if");
    keywords.insert("then");
    keywords.insert("endif");
    keywords.insert("else");
    keywords.insert("while");
    keywords.insert("do");
    keywords.insert("beginloop");
    keywords.insert("endloop");
    keywords.insert("continue");
    keywords.insert("read");
    keywords.insert("write");
    keywords.insert("and");
    keywords.insert("or");
    keywords.insert("not");
    keywords.insert("true");
    keywords.insert("false");
    keywords.insert("return");
}
