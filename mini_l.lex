%option noyywrap
%{
    #include "y.tab.h"
    int line = 1, position = 0;
    char* progStart;
%}


%%

"function"      {position += yyleng; return FUNCTION;}
"beginparams"   {position += yyleng; return BEGIN_PARAMS;}
"endparams"     {position += yyleng; return END_PARAMS;}
"beginlocals"   {position += yyleng; return BEGIN_LOCALS;}
"endlocals"     {position += yyleng; return END_LOCALS;}
"beginbody"     {position += yyleng; return BEGIN_BODY;}
"endbody"       {position += yyleng; return END_BODY;}
"integer"       {position += yyleng; return INTEGER;}
"array"         {position += yyleng; return ARRAY;}
"of"            {position += yyleng; return OF;}
"if"            {position += yyleng; return IF;}
"then"          {position += yyleng; return THEN;}
"endif"         {position += yyleng; return ENDIF;}
"else"          {position += yyleng; return ELSE;}
"while"         {position += yyleng; return WHILE;}
"do"            {position += yyleng; return DO;}
"beginloop"     {position += yyleng; return BEGINLOOP;}
"endloop"       {position += yyleng; return ENDLOOP;}
"continue"      {position += yyleng; return CONTINUE;}
"read"          {position += yyleng; return READ;}
"write"         {position += yyleng; return WRITE;}
"and"           {position += yyleng; return AND;}
"or"            {position += yyleng; return OR;}
"not"           {position += yyleng; return NOT;}
"true"          {position += yyleng; return TRUE;}
"false"         {position += yyleng; return FALSE;}
"return"        {position += yyleng; return RETURN;}
"+"             {position += yyleng; return ADD;}
"-"             {position += yyleng; return SUB;}
"*"             {position += yyleng; return MULT;}
"/"             {position += yyleng; return DIV;}
"%"             {position += yyleng; return MOD;}
"=="            {position += yyleng; return EQ;}
"<>"            {position += yyleng; return NEQ;}
"<"             {position += yyleng; return LT;}
">"             {position += yyleng; return GT;}
"<="            {position += yyleng; return LTE;}
">="            {position += yyleng; return GTE;}
";"             {position += yyleng; return SEMICOLON;}
":"             {position += yyleng; return COLON;}
","             {position += yyleng; return COMMA;}
"("             {position += yyleng; return L_PAREN;}
")"             {position += yyleng; return R_PAREN;}
"["             {position += yyleng; return L_SQUARE_BRACKET;}
"]"             {position += yyleng; return R_SQUARE_BRACKET;}
":="            {position += yyleng; return ASSIGN;}

"##".*		{}
"\n"            {position = 0; line++;}
[ \t]+          {position += yyleng;}

[0-9]+									  {yylval.intVal = atoi(yytext); position += yyleng; return NUMBER;}
[a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]		  {yylval.charVal = yytext; position += yyleng; return IDENT;} 
[a-zA-Z][a-zA-Z0-9]*					  {yylval.charVal = yytext; position += yyleng; return IDENT;}
[0-9_][a-zA-Z0-9_]*[a-zA-Z0-9_]           {printf("Error at line %d, position %d: Identifier \"%s\" must begin with a letter\n",line,position,yytext);position += yyleng; exit(0);} 
[a-zA-Z][a-zA-Z0-9_]*[_]                  {printf("Error at line %d, position %d: Identifier \"%s\" cannot end with an underscore\n",line,position,yytext); position += yyleng; exit(0);} 

.										  {printf("Error at line %d, column %d: Unrecognized symbol \"%s\"\n",line,position,yytext); exit(0);}

 <<EOF>>	{exit(0);}
%%