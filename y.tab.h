/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    number = 259,
    FUNCTION = 260,
    IDENTIFIER = 261,
    BEGIN_PARAMS = 262,
    END_PARAMS = 263,
    BEGIN_LOCALS = 264,
    END_LOCALS = 265,
    BEGIN_BODY = 266,
    END_BODY = 267,
    INTEGER = 268,
    ARRAY = 269,
    OF = 270,
    IF = 271,
    THEN = 272,
    ENDIF = 273,
    ELSE = 274,
    WHILE = 275,
    DO = 276,
    FOR = 277,
    IN = 278,
    BEGINLOOP = 279,
    ENDLOOP = 280,
    CONTINUE = 281,
    READ = 282,
    WRITE = 283,
    EXIT = 284,
    COMMA = 285,
    COLON = 286,
    SEMICOLON = 287,
    TRUE = 288,
    FALSE = 289,
    RETURN = 290,
    ASSIGN = 291,
    OR = 292,
    AND = 293,
    NOT = 294,
    LT = 295,
    LTE = 296,
    GT = 297,
    GTE = 298,
    EQ = 299,
    NEQ = 300,
    ADD = 301,
    SUB = 302,
    MULT = 303,
    DIV = 304,
    MOD = 305,
    UMINUS = 306,
    L_SQUARE_BRACKET = 307,
    R_SQUARE_BRACKET = 308,
    L_PAREN = 309,
    R_PAREN = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "mini_l.y" /* yacc.c:1909  */

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
 

#line 125 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
