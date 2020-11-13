// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 1 "mini_l.yy" // lalr1.cc:404


#line 39 "y.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "y.tab.hh"

// User implementation prologue.

#line 53 "y.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 29 "mini_l.yy" // lalr1.cc:413

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

#line 75 "y.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 161 "y.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 52: // NUMBER
        value.move< int > (that.value);
        break;

      case 53: // IDENT
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 52: // NUMBER
        value.copy< int > (that.value);
        break;

      case 53: // IDENT
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 52: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 53: // IDENT
        yylhs.value.build< string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 116 "mini_l.yy" // lalr1.cc:859
    {cout << "program -> epsilon" << endl;}
#line 558 "y.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 117 "mini_l.yy" // lalr1.cc:859
    {cout << "program -> functions" << endl;}
#line 564 "y.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 120 "mini_l.yy" // lalr1.cc:859
    {cout << "function -> FUNCTION identifier SEMICOLON BEGINPARAMS declaration_loop ENDPARAMS BEGINLOCALS declaration_loop ENDLOCALS BEGIN_BODY statement_loop ENDBODY" << endl;}
#line 570 "y.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 124 "mini_l.yy" // lalr1.cc:859
    {cout << "ident -> IDENT " << yystack_[0].value.as< string > () << endl;}
#line 576 "y.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 128 "mini_l.yy" // lalr1.cc:859
    {cout << "number -> NUMBER " << yystack_[0].value.as< int > () << endl;}
#line 582 "y.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 131 "mini_l.yy" // lalr1.cc:859
    {cout << "declaration_loop -> epsilon" << endl;}
#line 588 "y.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 132 "mini_l.yy" // lalr1.cc:859
    {cout << "declaration_loop -> declaration_loop declaration SEMICOLON" << endl;}
#line 594 "y.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 135 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> SEMICOLON";}
#line 600 "y.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 136 "mini_l.yy" // lalr1.cc:859
    {cout << "statement_loop -> statement_loop statement SEMICOLON" << endl;}
#line 606 "y.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 140 "mini_l.yy" // lalr1.cc:859
    {cout << "declaration -> identifier_loop COLON INTEGER" << endl;}
#line 612 "y.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 141 "mini_l.yy" // lalr1.cc:859
    {cout << "declaration -> identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET OF INTEGER" << endl;}
#line 618 "y.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 142 "mini_l.yy" // lalr1.cc:859
    {cout << "declaration -> identifier loop COLON ARRAY L_SQAURE_BRACKET number R_SQUARE_BRACKET L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER" << endl;}
#line 624 "y.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 145 "mini_l.yy" // lalr1.cc:859
    {cout << "identifier_loop -> identifier" << endl;}
#line 630 "y.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 146 "mini_l.yy" // lalr1.cc:859
    {cout << "identifier_loop -> identifier_loop identifier COMMA" << endl;}
#line 636 "y.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 149 "mini_l.yy" // lalr1.cc:859
    {cout << "statement  -> var ASSIGN expression" << endl;}
#line 642 "y.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 150 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> IF bool_exp THEN statement_loop ENDIF" << endl;}
#line 648 "y.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 151 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> IF bool_exp THEN statement_loop ELSE statement_loop ENDIF" << endl;}
#line 654 "y.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 152 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> WHILE bool_exp BEGINLOOP statement_loop ENDLOOP" << endl;}
#line 660 "y.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 153 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp" << endl;}
#line 666 "y.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 154 "mini_l.yy" // lalr1.cc:859
    {cout<< "statement -> FOR var ASSIGN number SEMICOLON bool_exp SEMICOLON var ASSIGN expression BEGINLOOP statement_loop ENDLOOP" << endl;}
#line 672 "y.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 155 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> READ var_loop" << endl;}
#line 678 "y.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 156 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> WRITE var_loop" << endl;}
#line 684 "y.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 157 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> continue" << endl;}
#line 690 "y.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 158 "mini_l.yy" // lalr1.cc:859
    {cout << "statement -> RETURN expression" << endl;}
#line 696 "y.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 161 "mini_l.yy" // lalr1.cc:859
    {cout << "var_loop -> var" << endl;}
#line 702 "y.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 162 "mini_l.yy" // lalr1.cc:859
    {cout << "var_loop -> var_loop var COMMA" << endl;}
#line 708 "y.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 165 "mini_l.yy" // lalr1.cc:859
    {cout << "bool_exp -> relation_and_exp" <<endl;}
#line 714 "y.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 166 "mini_l.yy" // lalr1.cc:859
    {cout << "bool_exp -> relation_and_exp OR bool_exp" <<endl;}
#line 720 "y.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 169 "mini_l.yy" // lalr1.cc:859
    {cout << "bool_exp -> relation_exp" <<endl;}
#line 726 "y.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 170 "mini_l.yy" // lalr1.cc:859
    {cout << "bool_exp -> relation_exp OR relation_and_exp" <<endl;}
#line 732 "y.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 173 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> NOT expression comp expression" << endl;}
#line 738 "y.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 174 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> expression comp expression" << endl;}
#line 744 "y.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 175 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> NOT TRUE" << endl;}
#line 750 "y.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 176 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> TRUE" << endl;}
#line 756 "y.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 177 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> NOT FALSE" << endl;}
#line 762 "y.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 178 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> FALSE" << endl;}
#line 768 "y.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 179 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> NOT L_PAREN bool_exp R_PAREN" << endl;}
#line 774 "y.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 180 "mini_l.yy" // lalr1.cc:859
    {cout << "relation_exp -> L_PAREN bool_exp R_PAREN" << endl;}
#line 780 "y.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 183 "mini_l.yy" // lalr1.cc:859
    {cout << "comp -> EQ" << endl;}
#line 786 "y.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 184 "mini_l.yy" // lalr1.cc:859
    {cout << "comp -> NEQ" << endl;}
#line 792 "y.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 185 "mini_l.yy" // lalr1.cc:859
    {cout << "comp -> LT" << endl;}
#line 798 "y.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 186 "mini_l.yy" // lalr1.cc:859
    {cout << "comp -> GT" << endl;}
#line 804 "y.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 187 "mini_l.yy" // lalr1.cc:859
    {cout << "comp -> LTE" << endl;}
#line 810 "y.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 188 "mini_l.yy" // lalr1.cc:859
    {cout << "comp -> GTE" << endl;}
#line 816 "y.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 191 "mini_l.yy" // lalr1.cc:859
    {cout << "expression -> mult_exp" << endl;}
#line 822 "y.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 192 "mini_l.yy" // lalr1.cc:859
    {cout << "expression -> mult_exp add_mult_loop" << endl;}
#line 828 "y.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 193 "mini_l.yy" // lalr1.cc:859
    {cout << "expression -> mult_exp sub_mult_loop" << endl;}
#line 834 "y.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 196 "mini_l.yy" // lalr1.cc:859
    {cout << "add_mult_loop -> ADD mult_exp" << endl;}
#line 840 "y.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 199 "mini_l.yy" // lalr1.cc:859
    {cout << "sub_mult_loop -> SUB mult_exp" << endl;}
#line 846 "y.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 202 "mini_l.yy" // lalr1.cc:859
    {cout << "mult_exp -> term" << endl;}
#line 852 "y.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 203 "mini_l.yy" // lalr1.cc:859
    {cout << "mult_exp -> term MULT term" << endl;}
#line 858 "y.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 204 "mini_l.yy" // lalr1.cc:859
    {cout << "mult_exp -> term DIV term" << endl;}
#line 864 "y.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 205 "mini_l.yy" // lalr1.cc:859
    {cout << "mult_exp -> term MOD term" << endl;}
#line 870 "y.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 208 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> identifier L_PAREN exp_loop R_PAREN" << endl;}
#line 876 "y.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 209 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> SUB var" << endl;}
#line 882 "y.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 210 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> var" << endl;}
#line 888 "y.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 211 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> SUB number" << endl;}
#line 894 "y.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 212 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> number" << endl;}
#line 900 "y.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 213 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> SUB L_PAREN expression R_PAREN" << endl;}
#line 906 "y.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 214 "mini_l.yy" // lalr1.cc:859
    {cout << "term -> L_PAREN expression R_PAREN" << endl;}
#line 912 "y.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 217 "mini_l.yy" // lalr1.cc:859
    {cout << "exp_loop -> epsilon" << endl;}
#line 918 "y.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 218 "mini_l.yy" // lalr1.cc:859
    {cout << "exp_loop -> exp_loop expression COMMA" << endl;}
#line 924 "y.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 221 "mini_l.yy" // lalr1.cc:859
    {cout << "var -> identifier" << endl;}
#line 930 "y.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 222 "mini_l.yy" // lalr1.cc:859
    {cout << "var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;}
#line 936 "y.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 223 "mini_l.yy" // lalr1.cc:859
    {cout << "var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET" << endl;}
#line 942 "y.tab.cc" // lalr1.cc:859
    break;


#line 946 "y.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -49;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
     -49,    13,   -49,   -48,   -49,   -49,   -36,    12,   -49,    -2,
      14,   -49,   -15,   -41,   -49,   -49,    22,    -8,   -10,   -49,
     -13,   -49,    32,    -4,   242,   -49,     2,   -30,   -49,   -48,
     -48,   -48,    39,   240,   240,    25,   137,    24,     8,    -7,
      31,   -30,   -24,   -49,   -49,    35,    53,   -49,   -48,   -49,
     -48,    27,   242,    83,   -49,   -49,   240,    47,    58,    60,
     247,    71,   -30,   -49,    52,   -49,   -30,    87,    -4,   -30,
     -49,   -49,    56,   -49,   -30,   -30,   -49,   -49,   -30,   -30,
     -30,    63,    -4,   172,   -49,   -49,   240,   247,    74,   258,
     242,   240,   240,   -49,   -49,   -49,   -49,   -49,   -49,   -30,
     242,    70,   -49,   -49,   -49,    72,    78,   -49,    20,   -49,
     -49,   -49,   -49,   -49,   -49,    79,    93,    84,   -30,   -49,
     153,   -49,   -49,   -49,   191,    82,   124,   -49,   -49,    92,
     240,   240,   -49,   -49,   -49,   242,   -49,   -30,   133,   -49,
      94,   -49,   207,    96,   -49,   -48,   -49,   -49,   102,   -30,
     128,   242,   226,   -49
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     3,     5,     0,     0,     7,     0,
       0,    14,     0,     0,     7,     8,     0,     0,     0,    11,
       0,    15,     0,     0,     0,     6,     0,     0,    24,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,    64,    59,    25,    46,    51,    57,    22,    26,
      23,     0,     0,     0,    35,    37,     0,     0,    28,    30,
       0,     0,     0,     4,     0,     9,     0,     0,     0,     0,
      58,    56,     0,    62,     0,     0,    47,    48,     0,     0,
       0,     0,     0,     0,    34,    36,     0,     0,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,    45,     0,
       0,     0,    10,    16,    12,     0,     0,    61,     0,    50,
      49,    52,    53,    54,    27,     0,     0,     0,     0,    39,
       0,    29,    31,    33,     0,    65,     0,    60,    55,     0,
       0,     0,    38,    32,    17,     0,    19,     0,     0,    63,
       0,    20,     0,     0,    13,     0,    18,    66,     0,     0,
       0,     0,     0,    21
  };

  const short int
  parser::yypgoto_[] =
  {
     -49,   -49,   -49,    -3,    -5,   130,   -33,   -49,   -49,   -28,
     129,   -25,    66,   -49,    73,    29,   -49,   -49,   -49,    33,
     -49,    10
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     4,    42,    43,     9,    36,    12,    13,    37,
      48,    57,    58,    59,    99,    60,    76,    77,    45,    46,
     108,    47
  };

  const unsigned char
  parser::yytable_[] =
  {
       6,    22,    67,    40,    10,     5,    11,    16,    64,    61,
      17,     7,     5,     2,    41,    11,     3,     8,    26,    83,
      73,    35,    25,     5,    14,    62,    35,    35,    35,    19,
      20,    88,    15,    35,    38,    70,    23,    35,    21,    49,
      49,    51,    68,     5,    24,    35,    38,    35,    25,    35,
      71,     5,    39,    40,    52,    64,    44,   120,    81,    66,
      81,   117,    38,   105,    41,   128,   121,   124,    74,    75,
      72,    65,    25,     5,    62,    69,    90,   115,    82,    91,
      35,    92,    87,    25,     5,    89,   100,    35,    78,    79,
      80,   101,    64,    38,   104,   103,    64,    35,   106,   102,
      38,   107,   142,   109,   110,   140,   141,    84,    85,   114,
      38,   111,   112,   113,    64,    89,    40,    35,   152,   119,
     125,    35,   126,   127,    64,   131,   130,    86,   123,   132,
      38,   137,    35,   138,    38,    25,     5,   129,   139,    35,
     144,   145,    35,   151,    18,    38,   147,   133,    35,    35,
      63,    27,    38,   149,    28,   148,    29,    30,   122,    50,
     118,    38,    38,    31,    32,    33,   143,    27,     0,    34,
      28,     0,    29,    30,     0,     0,     0,     0,   150,    31,
      32,    33,     0,   134,   135,    34,    27,     0,   116,    28,
       5,    29,    30,     0,     0,     0,     0,     0,    31,    32,
      33,     0,     0,     0,    34,    27,     5,   136,    28,     0,
      29,    30,     0,     0,     0,     0,     0,    31,    32,    33,
       0,    27,     0,    34,    28,     5,    29,    30,     0,     0,
       0,     0,     0,    31,    32,    33,     0,   146,     0,    34,
      27,     0,   153,    28,     5,    29,    30,     0,     0,     0,
       0,     0,    31,    32,    33,     0,    27,     0,    34,    28,
       5,    29,    30,    53,    54,    55,     0,     0,    31,    32,
      33,     0,     0,    40,    34,     0,     0,     0,     0,     5,
       0,     0,     0,     0,    56,    93,    94,    95,    96,    97,
      98,     0,    25,     5,     0,     5,    93,    94,    95,    96,
      97,    98,     0,   107
  };

  const short int
  parser::yycheck_[] =
  {
       3,    11,     9,    33,     6,    53,     9,    48,    36,    34,
      13,    47,    53,     0,    44,    18,     3,     5,    23,    52,
      44,    24,    52,    53,    10,    49,    29,    30,    31,     7,
       8,    56,    47,    36,    24,    40,    49,    40,    46,    29,
      30,    31,    49,    53,    12,    48,    36,    50,    52,    52,
      40,    53,    50,    33,    15,    83,    27,    90,    48,    51,
      50,    86,    52,    68,    44,    45,    91,   100,    33,    34,
      41,    47,    52,    53,    49,    44,    29,    82,    51,    21,
      83,    21,    53,    52,    53,    56,    15,    90,    35,    36,
      37,    62,   120,    83,     7,    66,   124,   100,    69,    47,
      90,    45,   135,    74,    75,   130,   131,    24,    25,    46,
     100,    78,    79,    80,   142,    86,    33,   120,   151,    45,
      50,   124,    50,    45,   152,    32,    47,    44,    99,    45,
     120,    49,   135,     9,   124,    52,    53,   108,    46,   142,
       7,    47,   145,    15,    14,   135,    50,   118,   151,   152,
      13,    14,   142,    51,    17,   145,    19,    20,    92,    30,
      87,   151,   152,    26,    27,    28,   137,    14,    -1,    32,
      17,    -1,    19,    20,    -1,    -1,    -1,    -1,   149,    26,
      27,    28,    -1,    30,    31,    32,    14,    -1,    16,    17,
      53,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    32,    14,    53,    16,    17,    -1,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    14,    -1,    32,    17,    53,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    -1,    32,
      14,    -1,    16,    17,    53,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    14,    -1,    32,    17,
      53,    19,    20,    23,    24,    25,    -1,    -1,    26,    27,
      28,    -1,    -1,    33,    32,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    44,    38,    39,    40,    41,    42,
      43,    -1,    52,    53,    -1,    53,    38,    39,    40,    41,
      42,    43,    -1,    45
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    55,     0,     3,    56,    53,    57,    47,     5,    59,
       6,    57,    61,    62,    10,    47,    48,    57,    59,     7,
       8,    46,    11,    49,    12,    52,    58,    14,    17,    19,
      20,    26,    27,    28,    32,    57,    60,    63,    75,    50,
      33,    44,    57,    58,    69,    72,    73,    75,    64,    75,
      64,    75,    15,    23,    24,    25,    44,    65,    66,    67,
      69,    65,    49,    13,    63,    47,    51,     9,    49,    44,
      58,    75,    69,    44,    33,    34,    70,    71,    35,    36,
      37,    75,    51,    60,    24,    25,    44,    69,    65,    69,
      29,    21,    21,    38,    39,    40,    41,    42,    43,    68,
      15,    69,    47,    69,     7,    58,    69,    45,    74,    69,
      69,    73,    73,    73,    46,    58,    16,    65,    68,    45,
      60,    65,    66,    69,    60,    50,    50,    45,    45,    69,
      47,    32,    45,    69,    30,    31,    16,    49,     9,    46,
      65,    65,    60,    69,     7,    47,    30,    50,    75,    51,
      69,    15,    60,    16
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    55,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    70,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,    12,     1,     1,     0,     3,     2,
       3,     3,     8,    11,     1,     3,     3,     5,     7,     5,
       6,    13,     2,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     4,     3,     2,     1,     2,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     3,     3,     3,     4,     2,     1,     2,     1,
       4,     3,     0,     3,     1,     4,     7
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION", "IDENTIFIER",
  "BEGIN_PARAMS", "END_PARAMS", "INTEGER", "ARRAY", "OF", "BEGIN_LOCALS",
  "END_LOCALS", "BEGIN_BODY", "END_BODY", "RETURN", "BEGINLOOP", "ENDLOOP",
  "CONTINUE", "EXIT", "READ", "WRITE", "OR", "AND", "NOT", "TRUE", "FALSE",
  "FOR", "DO", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "SUB", "ADD",
  "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN",
  "R_PAREN", "COMMA", "SEMICOLON", "COLON", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "ASSIGN", "NUMBER", "IDENT", "$accept", "program",
  "function", "identifier", "number", "declaration_loop", "statement_loop",
  "declaration", "identifier_loop", "statement", "var_loop", "bool_exp",
  "relation_and_exp", "relation_exp", "comp", "expression",
  "add_mult_loop", "sub_mult_loop", "mult_exp", "term", "exp_loop", "var", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   116,   116,   117,   120,   124,   128,   131,   132,   135,
     136,   140,   141,   142,   145,   146,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   161,   162,   165,   166,
     169,   170,   173,   174,   175,   176,   177,   178,   179,   180,
     183,   184,   185,   186,   187,   188,   191,   192,   193,   196,
     199,   202,   203,   204,   205,   208,   209,   210,   211,   212,
     213,   214,   217,   218,   221,   222,   223
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1446 "y.tab.cc" // lalr1.cc:1167
#line 228 "mini_l.yy" // lalr1.cc:1168


int main(int argc, char *argv[])
{
	yy::parser p;
	return p.parse();
}

void yy::parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

