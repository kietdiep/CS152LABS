/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

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

#line 166 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 102 "mini_l.y" /* yacc.c:355  */

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
 

#line 277 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 294 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   189,   189,   202,   207,   237,   288,   339,   391,   396,
     407,   412,   423,   431,   439,   473,   499,   538,   567,   653,
     666,   679,   684,   695,   699,   704,   726,   744,   759,   778,
     783,   803,   824,   829,   841,   853,   858,   878,   898,   920,
     944,   976,   981,   989,   994,  1006,  1030,  1035,  1058,  1063,
    1085,  1104,  1110,  1130,  1136,  1142,  1148,  1154,  1160,  1166,
    1172,  1178,  1185,  1190,  1204
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "number", "FUNCTION",
  "IDENTIFIER", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS",
  "BEGIN_BODY", "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN",
  "ENDIF", "ELSE", "WHILE", "DO", "FOR", "IN", "BEGINLOOP", "ENDLOOP",
  "CONTINUE", "READ", "WRITE", "EXIT", "COMMA", "COLON", "SEMICOLON",
  "TRUE", "FALSE", "RETURN", "ASSIGN", "OR", "AND", "NOT", "LT", "LTE",
  "GT", "GTE", "EQ", "NEQ", "ADD", "SUB", "MULT", "DIV", "MOD", "UMINUS",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "L_PAREN", "R_PAREN", "$accept",
  "Program", "Function", "declaration", "declaration_loop",
  "identifier_loop", "statement_loop", "statement", "else_statement",
  "var", "var_loop", "expression", "exp_loop", "mult_exp", "term",
  "bool_exp", "relation_and_exp", "relation_exp", "relation_exp_not",
  "comp", "identifier", "identifier_variable", "function_identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -49

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-49)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    14,    48,     2,   -49,    22,   -49,   -49,    53,   -49,
      33,   -49,    59,    44,    -2,   -49,   -49,   -49,    20,    58,
      11,   -49,    61,   -49,   103,   112,   219,    73,    71,    71,
     100,   125,   -49,   128,   128,     9,   127,   102,    96,    84,
      -9,   -49,   -49,   -49,    86,    -1,    71,   -49,   231,   -30,
     -49,   121,   105,   106,   -49,     3,   126,   219,   -49,   122,
     -49,   128,   128,     9,    45,   -49,   119,   -49,     9,     9,
     139,   152,   -49,   -49,     9,   -49,   215,   117,   -49,   -49,
     -49,   -49,   -49,   -49,     9,     9,     9,     9,     9,     9,
     219,    71,    71,     9,   219,   143,   128,   130,    12,   -49,
      45,    54,   -49,   104,    26,   -49,   -49,   -30,   -30,    45,
     -49,   -49,   -49,   163,   -49,   -49,    45,    24,   183,   138,
     137,   -49,   -49,   158,   -49,   219,   149,   -49,   -15,   -49,
      71,   219,   161,   219,   -49,   -49,   -49,   199,   -49,   -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,    64,     0,     1,     3,     0,     8,
       0,    62,     0,     0,     0,    10,     8,     9,     0,     0,
       0,     5,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    26,
       0,    41,    53,    54,     0,     0,     0,    39,     0,    29,
      35,     0,    46,    48,    51,    26,     0,     0,    63,     0,
      27,    19,    20,     0,    22,     4,     0,    13,     0,     0,
       0,     0,    50,    42,     0,    40,     0,     0,    58,    60,
      59,    61,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,    12,
      14,     0,     6,     0,     0,    43,    55,    30,    31,    52,
      36,    37,    38,    23,    47,    49,    34,     0,     0,     0,
       0,    28,    25,     0,    44,     0,     0,    45,     0,    16,
       0,     0,     0,    24,    15,    33,    17,     0,     7,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   172,   -49,   -49,   160,   -49,   -48,   -31,   -49,     4,
     146,   -24,   -49,    27,     8,   -21,    85,   -49,   144,   -49,
     -10,   -49,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    10,    14,    36,    37,   126,    47,
      61,    48,   117,    49,    50,    51,    52,    53,    54,    86,
      55,    59,     5
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    11,    11,    73,    19,    66,    70,     1,    56,    95,
      15,    64,    11,    41,    11,   135,    39,     4,    87,    88,
      89,    24,    76,    39,    39,    77,    39,    11,    41,    18,
      38,    84,    85,    21,    22,    39,    11,    60,    60,    98,
      38,    12,   113,    71,   100,   101,   118,    39,     6,    75,
     104,    39,    39,    74,     8,    69,    45,    93,    84,    85,
       9,    38,   109,    63,    66,    97,    97,   105,    16,   116,
     114,    45,    84,    85,    11,    41,    17,   133,    63,   127,
      39,   124,    66,   137,    39,    39,   120,    66,    23,    11,
      41,    84,    85,   128,    38,   110,   111,   112,    38,    38,
      84,    85,    66,    39,    42,    43,    66,   122,    39,   136,
      44,   107,   108,    25,    26,    39,    27,    38,    45,    42,
      43,    39,    38,    39,    57,    46,    40,    39,    58,    38,
      11,    11,    68,    45,    67,    38,    69,    38,    90,    65,
      46,    38,    91,    28,    92,    96,    11,    29,    30,    31,
      94,    99,   102,    32,    33,    34,   103,   123,   130,    28,
     121,   131,    35,    29,    30,    31,    11,   134,   119,    32,
      33,    34,   106,   132,   138,     7,    20,   115,    35,    28,
      62,     0,   125,    29,    30,    31,    11,     0,    72,    32,
      33,    34,     0,     0,     0,     0,     0,     0,    35,    28,
       0,     0,    11,    29,    30,    31,     0,     0,   129,    32,
      33,    34,     0,     0,     0,    28,     0,     0,    35,    29,
      30,    31,    11,     0,   139,    32,    33,    34,     0,     0,
       0,     0,     0,     0,    35,    28,     0,     0,     0,    29,
      30,    31,     0,     0,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,    35,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,     0,
     105,    78,    79,    80,    81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      10,     3,     3,     4,    14,    36,    15,     5,    29,    57,
      20,    35,     3,     4,     3,    30,    26,     3,    48,    49,
      50,    10,    46,    33,    34,    46,    36,     3,     4,    31,
      26,    46,    47,    13,    14,    45,     3,    33,    34,    63,
      36,     8,    90,    52,    68,    69,    94,    57,     0,    45,
      74,    61,    62,    54,    32,    52,    47,    54,    46,    47,
       7,    57,    86,    54,    95,    61,    62,    55,     9,    93,
      91,    47,    46,    47,     3,     4,    32,   125,    54,    55,
      90,    55,   113,   131,    94,    95,    96,   118,    30,     3,
       4,    46,    47,   117,    90,    87,    88,    89,    94,    95,
      46,    47,   133,   113,    33,    34,   137,    53,   118,   130,
      39,    84,    85,    52,    11,   125,     4,   113,    47,    33,
      34,   131,   118,   133,    24,    54,    53,   137,     3,   125,
       3,     3,    36,    47,    32,   131,    52,   133,    17,    12,
      54,   137,    37,    16,    38,    23,     3,    20,    21,    22,
      24,    32,    13,    26,    27,    28,     4,    53,    20,    16,
      30,    24,    35,    20,    21,    22,     3,    18,    25,    26,
      27,    28,    55,    15,    13,     3,    16,    92,    35,    16,
      34,    -1,    19,    20,    21,    22,     3,    -1,    44,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    16,
      -1,    -1,     3,    20,    21,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    -1,    16,    -1,    -1,    35,    20,
      21,    22,     3,    -1,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    16,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    40,    41,    42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    57,    58,     3,    78,     0,    57,    32,     7,
      60,     3,     8,    59,    61,    76,     9,    32,    31,    76,
      60,    13,    14,    30,    10,    52,    11,     4,    16,    20,
      21,    22,    26,    27,    28,    35,    62,    63,    65,    76,
      53,     4,    33,    34,    39,    47,    54,    65,    67,    69,
      70,    71,    72,    73,    74,    76,    71,    24,     3,    77,
      65,    66,    66,    54,    67,    12,    63,    32,    36,    52,
      15,    52,    74,     4,    54,    65,    67,    71,    40,    41,
      42,    43,    44,    45,    46,    47,    75,    48,    49,    50,
      17,    37,    38,    54,    24,    62,    23,    65,    67,    32,
      67,    67,    13,     4,    67,    55,    55,    69,    69,    67,
      70,    70,    70,    62,    71,    72,    67,    68,    62,    25,
      76,    30,    53,    53,    55,    19,    64,    55,    67,    25,
      20,    24,    15,    62,    18,    30,    71,    62,    13,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,    12,     3,     8,    11,     0,     3,
       1,     3,     3,     2,     3,     6,     5,     6,     7,     2,
       2,     1,     2,     0,     2,     4,     1,     1,     3,     1,
       3,     3,     0,     3,     1,     1,     3,     3,     3,     1,
       2,     1,     2,     3,     4,     4,     1,     3,     1,     3,
       2,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 190 "mini_l.y" /* yacc.c:1646  */
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
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 203 "mini_l.y" /* yacc.c:1646  */
    {
    // Nothing needed here?
}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 208 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "func ";  //starts function with func
  temp.append((yyvsp[-10].expr).location);
  temp.append("\n");
  temp.append((yyvsp[-10].expr).code);
  temp.append((yyvsp[-7].expr).code);
  string params = (yyvsp[-7].expr).code;
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
  temp.append((yyvsp[-4].expr).code);
  string statement_loop((yyvsp[-1].stat).code);
  if (statement_loop.find("continue") != string::npos) {
    printf("ERROR: Continue outside loop in function %s\n", (yyvsp[-10].expr).location);
  }
  temp.append(statement_loop);
  temp.append("endfunc\n"); //must end function with endfunc
  
  printf("%s", temp.c_str());
}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 238 "mini_l.y" /* yacc.c:1646  */
    {
  string vars((yyvsp[-2].expr).location);
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
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);	      
}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 289 "mini_l.y" /* yacc.c:1646  */
    {
  // Check if declaring arrays of size <= 0 
  if ((yyvsp[-3].intVal) <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  string vars((yyvsp[-7].expr).location);
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
      temp.append(to_string((yyvsp[-3].intVal)));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      tempVar = vars.substr(oldpos, len);
      temp.append(tempVar);
      temp.append(", ");
      temp.append(to_string((yyvsp[-3].intVal)));
      temp.append("\n");
    }
    if (variables.find(tempVar) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(tempVar,(yyvsp[-3].intVal)));
    }
      
    oldpos = pos + 1;
  }
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);	      
}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 340 "mini_l.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-6].intVal) <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size can't be less than 1");
    yyerror(temp);
  }
  
  string vars((yyvsp[-10].expr).location);
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
      temp.append(to_string((yyvsp[-6].intVal)));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      tempVar = vars.substr(oldpos, len);
      temp.append(tempVar);
      temp.append(", ");
      temp.append(to_string((yyvsp[-6].intVal)));
      temp.append("\n");
    }
    if (variables.find(tempVar) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(pair<string,int>(tempVar,(yyvsp[-6].intVal)));
    }
      
    oldpos = pos + 1;
  }
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);	  

}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 392 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup(empty);
  (yyval.expr).location = strdup(empty);
}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 398 "mini_l.y" /* yacc.c:1646  */
    { 
  string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[-1].expr).code);
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);
}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 408 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
  (yyval.expr).code = strdup(empty);
}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 413 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[-2].expr).location);
  temp.append((yyvsp[-1].expr).location);
  temp.append("|");
  
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 424 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[-2].stat).code);
  temp.append((yyvsp[-1].stat).code);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 432 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[-1].stat).code);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 440 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  string intermediate = (yyvsp[0].expr).location;
  if ((yyvsp[-2].expr).array && (yyvsp[0].expr).array) {
    intermediate = newTemp();
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append((yyvsp[0].expr).location);
    temp.append("\n");
    temp.append("[]= ");
  }
  else if ((yyvsp[-2].expr).array) {
    temp.append("[]= ");
  }
  else if ((yyvsp[0].expr).array) {
    temp.append("=[] ");
  }
  else {
    temp.append("= ");
  }
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append(intermediate);
  temp.append("\n");

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 474 "mini_l.y" /* yacc.c:1646  */
    {
  string then_begin = newLabel();
  string after = newLabel();
  string temp;

  temp.append((yyvsp[-4].expr).code);
  temp.append("?:= ");
  temp.append(then_begin);
  temp.append(", ");
  temp.append((yyvsp[-4].expr).location);
  temp.append("\n");
  temp.append((yyvsp[-1].stat).code);
  temp.append(":= ");
  temp.append(after);
  temp.append("\n");
  temp.append(": ");
  temp.append(then_begin);
  temp.append("\n");
  temp.append((yyvsp[-2].stat).code);
  temp.append(": ");
  temp.append(after);
  temp.append("\n");
  
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 500 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  string beginWhile = newLabel();
  string beginLoop = newLabel();
  string endLoop = newLabel();
  string statement = (yyvsp[-1].stat).code;
  string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");
  temp.append((yyvsp[-3].expr).code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append((yyvsp[-3].expr).location);
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

  (yyval.stat).code = strdup(temp.c_str());
}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 539 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  string beginLoop = newLabel();
  string beginWhile = newLabel();
  string statement = (yyvsp[-3].stat).code;
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
  temp.append((yyvsp[0].expr).code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");
  
  (yyval.stat).code = strdup(temp.c_str());
}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 568 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  string count = newTemp();
  string check = newTemp();
  string begin = newLabel();
  string beginLoop = newLabel();
  string increment = newLabel();
  string endLoop = newLabel();
  string statement = (yyvsp[-1].stat).code;
  string jump;
  jump.append(":= ");
  jump.append(increment);
  while (statement.find("continue") != string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  if (variables.find(string((yyvsp[-3].expr).location)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared tempVar %s", (yyvsp[-3].expr).location);
    yyerror(temp);
  }
  else if (variables.find(string((yyvsp[-3].expr).location))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Use of scalar tempVar %s in for", (yyvsp[-3].expr).location);
    yyerror(temp);
  }

  temp.append(". ");
  temp.append((yyvsp[-5].expr).location);
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
  temp.append(to_string(variables.find(string((yyvsp[-3].expr).location))->second));
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
  temp.append((yyvsp[-5].expr).location);
  temp.append(", ");
  temp.append((yyvsp[-3].expr).location);
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
  
  (yyval.stat).code = strdup(temp.c_str());
}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 654 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = (yyvsp[0].expr).code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == string::npos)
      break;
    temp.replace(pos, 1, "<");
  } while (true);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 667 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = (yyvsp[0].expr).code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == string::npos)
      break;
    temp.replace(pos, 1, ">");
  } while (true);

  (yyval.stat).code = strdup(temp.c_str());
}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 680 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "continue\n";
  (yyval.stat).code = strdup(temp.c_str());
}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 685 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[0].expr).code);
  temp.append("ret ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");
  (yyval.stat).code = strdup(temp.c_str());
}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 696 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.stat).code = strdup(empty);
}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 700 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.stat).code = strdup((yyvsp[0].stat).code);
}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 705 "mini_l.y" /* yacc.c:1646  */
    {
  if (variables.find(string((yyvsp[-3].expr).location)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared tempVar %s", (yyvsp[-3].expr).location);
    yyerror(temp);
  }
  else if (variables.find(string((yyvsp[-3].expr).location))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Indexing a non-array tempVar %s", (yyvsp[-3].expr).location);
    yyerror(temp);
  }

  string temp;
  temp.append((yyvsp[-3].expr).location);
  temp.append(", ");
  temp.append((yyvsp[-1].expr).location);

  (yyval.expr).code = strdup((yyvsp[-1].expr).code);
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).array = true;
}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 727 "mini_l.y" /* yacc.c:1646  */
    {
  if (variables.find(string((yyvsp[0].expr).location)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared tempVar %s", (yyvsp[0].expr).location);
    yyerror(temp);
  }
  else if (variables.find(string((yyvsp[0].expr).location))->second > 0) {
    char temp[128];
    snprintf(temp, 128, "Failed to provide index for array tempVar %s", (yyvsp[0].expr).location);
    yyerror(temp);
  }

  (yyval.expr).code = strdup(empty);
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
  (yyval.expr).array = false;
}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 745 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[0].expr).code);
  if ((yyvsp[0].expr).array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);
}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 760 "mini_l.y" /* yacc.c:1646  */
    {
  //cgheck this one 
  //not sure
  string temp;
  temp.append((yyvsp[-1].expr).code);
  if ((yyvsp[-1].expr).array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append((yyvsp[-2].expr).location);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);
}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 779 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 784 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup(newTemp().c_str());
  
  string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  temp.append("+ ");
  temp.append((yyval.expr).location);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 804 "mini_l.y" /* yacc.c:1646  */
    { //TAGSOCCER HEHE69
  (yyval.expr).location = strdup(newTemp().c_str());
  
  string temp;
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  temp.append("- ");
  temp.append((yyval.expr).location);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 825 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup(empty);
  (yyval.expr).location = strdup(empty);
}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 830 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append((yyvsp[-1].expr).code);
  temp.append("param ");
  temp.append((yyvsp[-1].expr).location);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);

  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);
}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 842 "mini_l.y" /* yacc.c:1646  */
    {  string temp;
  temp.append((yyvsp[0].expr).code);
  temp.append("param ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(empty);
}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 854 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 859 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append("* ");
  temp.append((yyval.expr).location);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 879 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append("/ ");
  temp.append((yyval.expr).location);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 899 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup(newTemp().c_str());
  
  string temp;
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append("% ");
  temp.append((yyval.expr).location);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");

  (yyval.expr).code = strdup(temp.c_str());
}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 921 "mini_l.y" /* yacc.c:1646  */
    {
  // array? or not an array? will we ever know?
  if ((yyval.expr).array == true) {
    string temp;
    string intermediate = newTemp();
    temp.append((yyvsp[0].expr).code);
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");
    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append((yyvsp[0].expr).location);
    temp.append("\n");
    (yyval.expr).code = strdup(temp.c_str());
    (yyval.expr).location = strdup(intermediate.c_str());
    (yyval.expr).array = false;
  }
  else {
    (yyval.expr).code = strdup((yyvsp[0].expr).code);
    (yyval.expr).location = strdup((yyvsp[0].expr).location);
  }
}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 945 "mini_l.y" /* yacc.c:1646  */
    {
  // array? or not an array? will we ever know?
  (yyval.expr).location = strdup(newTemp().c_str());
  string temp;
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  if ((yyvsp[0].expr).array) {
    temp.append("=[] ");
    temp.append((yyval.expr).location);
    temp.append(", ");
    temp.append((yyvsp[0].expr).location);
    temp.append("\n");
  }
  else {
    temp.append("= ");
    temp.append((yyval.expr).location);
    temp.append(", ");
    temp.append((yyvsp[0].expr).location);
    temp.append("\n");
  }
  temp.append("* ");
  temp.append((yyval.expr).location);
  temp.append(", ");
  temp.append((yyval.expr).location);
  temp.append(", -1\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).array = false;
}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 977 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup(empty);
  (yyval.expr).location = strdup(to_string((yyvsp[0].intVal)).c_str());
}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 982 "mini_l.y" /* yacc.c:1646  */
    {
  string temp;
  temp.append("-");
  temp.append(to_string((yyvsp[0].intVal)));
  (yyval.expr).code = strdup(empty);
  (yyval.expr).location = strdup(temp.c_str());
}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 990 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).code = strdup((yyvsp[-1].expr).code);
  (yyval.expr).location = strdup((yyvsp[-1].expr).location);
}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 995 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[-1].expr).location);
  string temp;
  temp.append((yyvsp[-1].expr).code);
  temp.append("* ");
  temp.append((yyvsp[-1].expr).location);
  temp.append(", ");
  temp.append((yyvsp[-1].expr).location);
  temp.append(", -1\n");
  (yyval.expr).code = strdup(temp.c_str());
}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1007 "mini_l.y" /* yacc.c:1646  */
    {
  if (functions.find(string((yyvsp[-3].expr).location)) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared function %s", (yyvsp[-3].expr).location);
    yyerror(temp);
  }

  (yyval.expr).location = strdup(newTemp().c_str());

  string temp;
  temp.append((yyvsp[-1].expr).code);
  temp.append(". ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  temp.append("call ");
  temp.append((yyvsp[-3].expr).location);
  temp.append(", ");
  temp.append((yyval.expr).location);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
}
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1031 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1036 "mini_l.y" /* yacc.c:1646  */
    {
  string dest = newTemp();
  string temp;

  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("|| ");
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(dest.c_str());
}
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1059 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1064 "mini_l.y" /* yacc.c:1646  */
    {
  string dest = newTemp();
  string temp;

  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("&& ");
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(dest.c_str());
}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1086 "mini_l.y" /* yacc.c:1646  */
    {
  string dest = newTemp();
  string temp;

  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("! ");
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(dest.c_str());
}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1105 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[0].expr).location);
  (yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1111 "mini_l.y" /* yacc.c:1646  */
    {
  string dest = newTemp();
  string temp;  
  temp.append((yyvsp[-2].expr).code);
  temp.append((yyvsp[0].expr).code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  temp.append((yyvsp[-1].expr).location);
  temp.append(dest);
  temp.append(", ");
  temp.append((yyvsp[-2].expr).location);
  temp.append(", ");
  temp.append((yyvsp[0].expr).location);
  temp.append("\n");
  
  (yyval.expr).code = strdup(temp.c_str());
  (yyval.expr).location = strdup(dest.c_str());
}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1131 "mini_l.y" /* yacc.c:1646  */
    {
  char temp[2] = "1";
  (yyval.expr).location = strdup(temp);
  (yyval.expr).code = strdup(empty);
}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1137 "mini_l.y" /* yacc.c:1646  */
    {
  char temp[2] = "0";
  (yyval.expr).location = strdup(temp);
  (yyval.expr).code = strdup(empty);
}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1143 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[-1].expr).location);
  (yyval.expr).code = strdup((yyvsp[-1].expr).code);
}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1149 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "== ";
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1155 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "!= ";
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1161 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "< ";
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1167 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "> ";
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1173 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = "<= ";
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1179 "mini_l.y" /* yacc.c:1646  */
    {
  string temp = ">= ";
  (yyval.expr).location = strdup(temp.c_str());
  (yyval.expr).code = strdup(empty);
}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1186 "mini_l.y" /* yacc.c:1646  */
    {
  (yyval.expr).location = strdup((yyvsp[0].charVal));
  (yyval.expr).code = strdup(empty);;
}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1191 "mini_l.y" /* yacc.c:1646  */
    {
  string tempVar((yyvsp[0].charVal));
  if (variables.find(tempVar) != variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of tempVar %s", tempVar.c_str());
    yyerror(temp);
  }
  else {
    variables.insert(pair<string,int>(tempVar,0));
  }
  (yyval.expr).location = strdup((yyvsp[0].charVal));
  (yyval.expr).code = strdup(empty);;
}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1205 "mini_l.y" /* yacc.c:1646  */
    {
  if (functions.find(string((yyvsp[0].charVal))) != functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of function %s", (yyvsp[0].charVal));
    yyerror(temp);
  }
  else {
    functions.insert(pair<string,int>((yyvsp[0].charVal),0));
  }
  (yyval.expr).location = strdup((yyvsp[0].charVal));
  (yyval.expr).code = strdup(empty);;
}
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2750 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1217 "mini_l.y" /* yacc.c:1906  */


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
