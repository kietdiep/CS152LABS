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
#line 1 "mini_ll.yy" // lalr1.cc:404


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
#line 104 "mini_ll.yy" // lalr1.cc:413

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

#line 92 "y.tab.cc" // lalr1.cc:413


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
#line 178 "y.tab.cc" // lalr1.cc:479

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
      case 53: // program
      case 58: // declaration
      case 64: // bool_expr
      case 65: // relation_and_expr
      case 66: // relation_expr
      case 68: // expression
      case 69: // mult_expr
      case 71: // term
      case 73: // var
        value.move< ExprStruct > (that.value);
        break;

      case 54: // function
      case 55: // identifier
      case 59: // identifier_loop
      case 60: // statement
        value.move< StatementStruct > (that.value);
        break;

      case 50: // NUMBER
        value.move< int > (that.value);
        break;

      case 49: // IDENTIFIER
      case 67: // comp
      case 70: // mulop
        value.move< std::string > (that.value);
        break;

      case 56: // declaration_loop
      case 63: // var_loop
      case 72: // expression_loop
        value.move< std::vector<ExprStruct> > (that.value);
        break;

      case 57: // statement_loop
        value.move< std::vector<StatementStruct> > (that.value);
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
      case 53: // program
      case 58: // declaration
      case 64: // bool_expr
      case 65: // relation_and_expr
      case 66: // relation_expr
      case 68: // expression
      case 69: // mult_expr
      case 71: // term
      case 73: // var
        value.copy< ExprStruct > (that.value);
        break;

      case 54: // function
      case 55: // identifier
      case 59: // identifier_loop
      case 60: // statement
        value.copy< StatementStruct > (that.value);
        break;

      case 50: // NUMBER
        value.copy< int > (that.value);
        break;

      case 49: // IDENTIFIER
      case 67: // comp
      case 70: // mulop
        value.copy< std::string > (that.value);
        break;

      case 56: // declaration_loop
      case 63: // var_loop
      case 72: // expression_loop
        value.copy< std::vector<ExprStruct> > (that.value);
        break;

      case 57: // statement_loop
        value.copy< std::vector<StatementStruct> > (that.value);
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
      case 53: // program
      case 58: // declaration
      case 64: // bool_expr
      case 65: // relation_and_expr
      case 66: // relation_expr
      case 68: // expression
      case 69: // mult_expr
      case 71: // term
      case 73: // var
        yylhs.value.build< ExprStruct > ();
        break;

      case 54: // function
      case 55: // identifier
      case 59: // identifier_loop
      case 60: // statement
        yylhs.value.build< StatementStruct > ();
        break;

      case 50: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 49: // IDENTIFIER
      case 67: // comp
      case 70: // mulop
        yylhs.value.build< std::string > ();
        break;

      case 56: // declaration_loop
      case 63: // var_loop
      case 72: // expression_loop
        yylhs.value.build< std::vector<ExprStruct> > ();
        break;

      case 57: // statement_loop
        yylhs.value.build< std::vector<StatementStruct> > ();
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
#line 182 "mini_ll.yy" // lalr1.cc:859
    {yylhs.value.as< ExprStruct > () = "";}
#line 668 "y.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 183 "mini_ll.yy" // lalr1.cc:859
    {yylhs.value.as< ExprStruct > () = yystack_[1].value.as< ExprStruct > () + "\n" + yystack_[0].value.as< StatementStruct > ();}
#line 674 "y.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 187 "mini_ll.yy" // lalr1.cc:859
    {
	yylhs.value.as< StatementStruct > () = "func " + yystack_[10].value.as< StatementStruct > () + "\n";
	yylhs.value.as< StatementStruct > () += yystack_[7].value.as< std::vector<ExprStruct> > ().code;
	int i = 0;
	for(list<string>::iterator it = yystack_[7].value.as< std::vector<ExprStruct> > ().ids.begin(); it != yystack_[7].value.as< std::vector<ExprStruct> > ().ids.end(); it++){
		yylhs.value.as< StatementStruct > () += "= " + *it + ", $" + to_string(i) + "\n";
		i++;
	}
	yylhs.value.as< StatementStruct > () += yystack_[4].value.as< std::vector<ExprStruct> > ().code;
	yylhs.value.as< StatementStruct > () += yystack_[1].value.as< std::vector<StatementStruct> > ();
	yylhs.value.as< StatementStruct > () += "endfunc";
	}
#line 691 "y.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 202 "mini_ll.yy" // lalr1.cc:859
    {yylhs.value.as< StatementStruct > () = yystack_[0].value.as< std::string > ();}
#line 697 "y.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 209 "mini_ll.yy" // lalr1.cc:859
    {
	yylhs.value.as< std::vector<ExprStruct> > ().code = "";
	yylhs.value.as< std::vector<ExprStruct> > ().ids = list<string>();
	}
#line 706 "y.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 214 "mini_ll.yy" // lalr1.cc:859
    {
	/* Note: Since our code is different from TA's changed $3 to $2 because of the order of declaration_loop and declaration. Not sure if we should change or not */
	yylhs.value.as< std::vector<ExprStruct> > ().code = yystack_[2].value.as< std::vector<ExprStruct> > ().code + "\n" + yystack_[1].value.as< ExprStruct > ().code;
	yylhs.value.as< std::vector<ExprStruct> > ().ids = yystack_[2].value.as< std::vector<ExprStruct> > ().ids;
	for(list<string>::iterator it = yystack_[1].value.as< ExprStruct > ().ids.begin(); it != yystack_[1].value.as< ExprStruct > ().ids.end(); i++) {
		yylhs.value.as< std::vector<ExprStruct> > ().ids.push_back(*it);
	} 	
	}
#line 719 "y.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 225 "mini_ll.yy" // lalr1.cc:859
    {
	yylhs.value.as< std::vector<StatementStruct> > () = yystack_[1].value.as< StatementStruct > (); 
	}
#line 727 "y.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 229 "mini_ll.yy" // lalr1.cc:859
    {
	yylhs.value.as< std::vector<StatementStruct> > () = yystack_[2].value.as< std::vector<StatementStruct> > () + "\n" + yystack_[1].value.as< StatementStruct > ();
	}
#line 735 "y.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 236 "mini_ll.yy" // lalr1.cc:859
    {
        for(list<string>::iterator it = yystack_[2].value.as< StatementStruct > ().begin(); it != yystack_[2].value.as< StatementStruct > ().end(); i++) {
                yylhs.value.as< ExprStruct > ().code += ". " + *it + "\n";
                yylhs.value.as< ExprStruct > ().ids.push_back(*it);
        }
        }
#line 746 "y.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 243 "mini_ll.yy" // lalr1.cc:859
    {
	for(list<string>::iterator it = yystack_[7].value.as< StatementStruct > ().begin(); it != yystack_[7].value.as< StatementStruct > ().end(); i++) {
		yylhs.value.as< ExprStruct > ().code += ".[] " + *it + ", " + to_string(yystack_[3].value.as< int > ()) + "\n";
		yylhs.value.as< ExprStruct > ().ids.push_back(*it);
	}
	}
#line 757 "y.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 250 "mini_ll.yy" // lalr1.cc:859
    {
	for(list<string>::iterator it = yystack_[10].value.as< StatementStruct > ().begin(); it != yystack_[10].value.as< StatementStruct > ().end(); i++) {
                yylhs.value.as< ExprStruct > ().code += ".[] " + *it + ", " + to_string(yystack_[6].value.as< int > ()*yystack_[3].value.as< int > ()) + "\n";
                yylhs.value.as< ExprStruct > ().ids.push_back(*it);
        }
	/*confused why u multiplied $5 and $8 */
	}
#line 769 "y.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 260 "mini_ll.yy" // lalr1.cc:859
    {
	yylhs.value.as< StatementStruct > ().push_back(yystack_[0].value.as< StatementStruct > ());
	}
#line 777 "y.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 264 "mini_ll.yy" // lalr1.cc:859
    {
	/* Note: Ta's code is identifier_loop COMMA identifier, but ours is id_loop id COMMA, so changed $$ = $2, $$.push_front($1) */
	yylhs.value.as< StatementStruct > () = yystack_[1].value.as< StatementStruct > ();
	yylhs.value.as< StatementStruct > ().push_front(yystack_[2].value.as< StatementStruct > ());
	}
#line 787 "y.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 274 "mini_ll.yy" // lalr1.cc:859
    {
        debug_print("statement -> var ASSIGN expression\n"); 
        // ExprStruct es;
        // es.reg_name = generateTempReg();
        yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());
        // $$.code.push_back(". " + $1.reg_name);
        yylhs.value.as< StatementStruct > ().code.push_back("= " + yystack_[2].value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);
        // $$ = es;
    }
#line 801 "y.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 284 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> IF bool_expr THEN statement_loop ENDIF\n");

        // Before anything else, copy code from bool_expr,
        // and define your own reg_name
        yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), yystack_[3].value.as< ExprStruct > ().code.begin(), yystack_[3].value.as< ExprStruct > ().code.end());
        yylhs.value.as< StatementStruct > ().begin_label = generateTempReg();
        yylhs.value.as< StatementStruct > ().code.push_back(". " + yylhs.value.as< StatementStruct > ().begin_label);

        // Prepare the endif label
        std::string endif_label = generateTempLabel();

        // Compute the negation of the result of bool_expr,
        // which is in $2.reg_name
        std::string negation_reg = generateTempReg();
        yylhs.value.as< StatementStruct > ().code.push_back(". " + negation_reg);
        yylhs.value.as< StatementStruct > ().code.push_back("! " + negation_reg + ", " + yystack_[3].value.as< ExprStruct > ().reg_name);

        // If negation_neg is true,
        // then bool_expr was false,
        // so jump to endif label
        yylhs.value.as< StatementStruct > ().code.push_back("?:= " + endif_label + ", " + negation_reg);

        // Else if !negation_reg, then bool_expr was true,
        // and you should fall through to the body code
        for (StatementStruct thisStatement : yystack_[1].value.as< std::vector<StatementStruct> > ()) {

            yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        // After we're done with body code, append the endif label
        yylhs.value.as< StatementStruct > ().code.push_back(": " + endif_label);
        
    
    }
#line 842 "y.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 321 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> IF bool_expr THEN statement_loop ELSE statement_loop ENDIF\n");

        // Copy code for evaluating bool_expr
        yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), yystack_[5].value.as< ExprStruct > ().code.begin(), yystack_[5].value.as< ExprStruct > ().code.end());

        // Need 2 labels, else and end
        yylhs.value.as< StatementStruct > ().begin_label = generateTempLabel();   // else
        yylhs.value.as< StatementStruct > ().end_label = generateTempLabel();     // end

        std::string negation_reg = generateTempReg();
        yylhs.value.as< StatementStruct > ().code.push_back(". " + negation_reg);
        yylhs.value.as< StatementStruct > ().code.push_back("! " + negation_reg + ", " + yystack_[5].value.as< ExprStruct > ().reg_name);

        // If !bool_expr, jump to else
        yylhs.value.as< StatementStruct > ().code.push_back("?:= " + yylhs.value.as< StatementStruct > ().begin_label + ", " + negation_reg);

        // Fall through to code from statement loop
        for (StatementStruct thisStatement : yystack_[3].value.as< std::vector<StatementStruct> > ()) {

            yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        // Jump to end to avoid else statement
        yylhs.value.as< StatementStruct > ().code.push_back(":= " + yylhs.value.as< StatementStruct > ().end_label /*+ " ; end of if, jump to end"*/);

        yylhs.value.as< StatementStruct > ().code.push_back(": " + yylhs.value.as< StatementStruct > ().begin_label /*+ " ; else label"*/);

        for (StatementStruct thisStatement : yystack_[1].value.as< std::vector<StatementStruct> > ()) {

            yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        yylhs.value.as< StatementStruct > ().code.push_back(": " + yylhs.value.as< StatementStruct > ().end_label /*+ " ; endif label"*/);

    }
#line 884 "y.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 359 "mini_ll.yy" // lalr1.cc:859
    {loop_scope.push(generateTempLabel());}
#line 890 "y.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 359 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> WHILE bool_expr BEGINLOOP statement_loop ENDLOOP\n");

        StatementStruct css;
        assert(!loop_scope.empty());
        css.begin_label = loop_scope.top();
        std::string middle_label = generateTempLabel();
        css.end_label = generateTempLabel();


        yylhs.value.as< StatementStruct > ().code.push_back(": " + css.begin_label);

        yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), yystack_[4].value.as< ExprStruct > ().code.begin(), yystack_[4].value.as< ExprStruct > ().code.end()); // bool_expr code

        yylhs.value.as< StatementStruct > ().code.push_back("?:= " + middle_label + ", " + yystack_[4].value.as< ExprStruct > ().reg_name);
        yylhs.value.as< StatementStruct > ().code.push_back(":= " + css.end_label);
        yylhs.value.as< StatementStruct > ().code.push_back(": " + middle_label);



        for (StatementStruct thisStatement : yystack_[1].value.as< std::vector<StatementStruct> > ()) {

            yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        yylhs.value.as< StatementStruct > ().code.push_back(":= " + css.begin_label);
        yylhs.value.as< StatementStruct > ().code.push_back(": " + css.end_label);


        yylhs.value.as< StatementStruct > ().begin_label = css.begin_label;
        yylhs.value.as< StatementStruct > ().end_label = css.end_label;

        loop_scope.pop();

    }
#line 931 "y.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 396 "mini_ll.yy" // lalr1.cc:859
    { loop_scope.push(generateTempLabel()); }
#line 937 "y.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 396 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_expr\n");

        StatementStruct ss;
        // ss.begin_label = generateTempLabel();
        assert(!loop_scope.empty());
        ss.end_label = loop_scope.top();
        ss.begin_label = generateTempLabel();

        yylhs.value.as< StatementStruct > ().code.push_back(": " + ss.begin_label);

        // code from statement_loop
        for (StatementStruct thisStatement : yystack_[3].value.as< std::vector<StatementStruct> > ()) {

            yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), thisStatement.code.begin(), thisStatement.code.end());
        }

        // set end_label to be between end of body code and before bool_expr
        yylhs.value.as< StatementStruct > ().code.push_back(": " + ss.end_label);

        // code from bool_expr
        yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());

        // if bool_expr, jump to ss.begin_label
        yylhs.value.as< StatementStruct > ().code.push_back("?:= " + ss.begin_label + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

        loop_scope.pop();

    }
#line 972 "y.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 427 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> READ var_loop\n");


        for (ExprStruct this_expr_struct : yystack_[0].value.as< std::vector<ExprStruct> > ()) {
            // thisCode.push_back(".< " + this_expr_struct.reg_name);


            //this_expr_struct.reg_name = 

            //$$.code.insert($$.code.end(), this_expr_struct.code.begin(), this_expr_struct.code.end());
            // $$.code.push_back(".< " + this_expr_struct.original_name);
            yylhs.value.as< StatementStruct > ().code.push_back(".< " + this_expr_struct.reg_name);
        }
    }
#line 993 "y.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 444 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> WRITE var_loop\n");
        // $$ = concat($2, ".> ", "\n");

        for (ExprStruct this_expr_struct : yystack_[0].value.as< std::vector<ExprStruct> > ()) {
            //$$.code.insert($$.code.end(), this_expr_struct.code.begin(), this_expr_struct.code.end());
            // $$.code.push_back(".> " + this_expr_struct.original_name);
            yylhs.value.as< StatementStruct > ().code.push_back(".> " + this_expr_struct.reg_name);
        }
    }
#line 1009 "y.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 456 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> CONTINUE\n");

        // std::cout << "loop_scope size: " << loop_scope.size() << std::endl;

        if (loop_scope.empty()) {

            yy::parser::error(yystack_[0].location, "\'continue\' keyword forbidden outside loops");
        }

        else {

            std::string jump_here = loop_scope.top();
            yylhs.value.as< StatementStruct > ().code.push_back(":= " + jump_here);
        }
    }
#line 1031 "y.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 474 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("statement -> RETURN expression\n");

        yylhs.value.as< StatementStruct > ().code.insert(yylhs.value.as< StatementStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());
        // $$.reg_name = $2.reg_name;
        yylhs.value.as< StatementStruct > ().begin_label = yystack_[0].value.as< ExprStruct > ().reg_name;
        yylhs.value.as< StatementStruct > ().code.push_back("ret " + yystack_[0].value.as< ExprStruct > ().reg_name);

    }
#line 1046 "y.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 488 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("var_loop -> var\n");
        yylhs.value.as< std::vector<ExprStruct> > ().push_back(yystack_[0].value.as< ExprStruct > ());

    }
#line 1057 "y.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 495 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("var_loop -> var_loop COMMA var\n");
        yylhs.value.as< std::vector<ExprStruct> > ().insert(yylhs.value.as< std::vector<ExprStruct> > ().end(), yystack_[2].value.as< std::vector<ExprStruct> > ().begin(), yystack_[2].value.as< std::vector<ExprStruct> > ().end());
        yylhs.value.as< std::vector<ExprStruct> > ().push_back(yystack_[0].value.as< ExprStruct > ());
    }
#line 1068 "y.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 504 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print("bool_expr -> relation_and_expr\n");
        yylhs.value.as< ExprStruct > () = yystack_[0].value.as< ExprStruct > ();

    }
#line 1078 "y.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 509 "mini_ll.yy" // lalr1.cc:859
    {
        debug_print("bool_expr -> bool_expr OR relation_and_expr\n"); 

    }
#line 1087 "y.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 516 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print("relation_and_expr -> relation_expr\n"); 
        yylhs.value.as< ExprStruct > () = yystack_[0].value.as< ExprStruct > ();

    }
#line 1097 "y.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 521 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print("relation_and_expr -> relation_and_expr AND relation_expr\n"); 

    }
#line 1106 "y.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 529 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("relation_expr -> expression comp expression\n");

        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[2].value.as< ExprStruct > ().code.begin(), yystack_[2].value.as< ExprStruct > ().code.end());
        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back(yystack_[1].value.as< std::string > () + " " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[2].value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

    }
#line 1124 "y.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 543 "mini_ll.yy" // lalr1.cc:859
    {

        std::cout << "In relation_expr -> NOT expression comp expression" << std::endl;

        debug_print("relation_expr -> NOT expression comp expression\n");

        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[2].value.as< ExprStruct > ().code.begin(), yystack_[2].value.as< ExprStruct > ().code.end());
        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back(yystack_[1].value.as< std::string > () + " " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[2].value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back("! " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yylhs.value.as< ExprStruct > ().reg_name);
    }
#line 1145 "y.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 560 "mini_ll.yy" // lalr1.cc:859
    { 

        debug_print("relation_expr -> TRUE\n");

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", 1");
    }
#line 1159 "y.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 569 "mini_ll.yy" // lalr1.cc:859
    { debug_print("relation_expr -> NOT TRUE\n"); 

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", 0");
    }
#line 1171 "y.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 576 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print("relation_expr -> FALSE\n"); 

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", 0");
    }
#line 1184 "y.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 584 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print("relation_expr -> NOT FALSE\n"); 

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);

        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", 1");
    }
#line 1197 "y.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 592 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print("relation_expr -> L_PAREN bool_expr R_PAREN\n"); 

        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[1].value.as< ExprStruct > ().code.begin(), yystack_[1].value.as< ExprStruct > ().code.end());

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[1].value.as< ExprStruct > ().reg_name);
    }
#line 1211 "y.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 604 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > ()  = "=="; }
#line 1217 "y.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 605 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > ()  = "!="; }
#line 1223 "y.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 606 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > ()  = "<"; }
#line 1229 "y.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 607 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > ()  = ">"; }
#line 1235 "y.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 608 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > ()  = "<="; }
#line 1241 "y.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 609 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > ()  = ">="; }
#line 1247 "y.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 613 "mini_ll.yy" // lalr1.cc:859
    { debug_print("expression -> mult_expr\n"); 
        yylhs.value.as< ExprStruct > () = yystack_[0].value.as< ExprStruct > ();
        //$$.code.push_back("= " + $$.reg_name + ", " + $1.reg_name);
    }
#line 1256 "y.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 617 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("expression -> expression ADD mult_expr\n"); 

        yylhs.value.as< ExprStruct > () = yystack_[2].value.as< ExprStruct > ();
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        // $$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("+ " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[2].value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);


    }
#line 1274 "y.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 630 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("expression -> expression SUB mult_expr\n");

        yylhs.value.as< ExprStruct > () = yystack_[2].value.as< ExprStruct > ();
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        // $$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("- " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[2].value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);
    }
#line 1290 "y.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 645 "mini_ll.yy" // lalr1.cc:859
    {
        debug_print("mult_expr -> term\n"); 
        yylhs.value.as< ExprStruct > () = yystack_[0].value.as< ExprStruct > ();
    }
#line 1299 "y.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 650 "mini_ll.yy" // lalr1.cc:859
    {
        debug_print_char("mult_expr -> mult_expr %s term\n", yystack_[1].value.as< std::string > ()); 
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[2].value.as< ExprStruct > ().code.begin(), yystack_[2].value.as< ExprStruct > ().code.end());
        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[0].value.as< ExprStruct > ().code.begin(), yystack_[0].value.as< ExprStruct > ().code.end());
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back(yystack_[1].value.as< std::string > () + " " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[2].value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

        // std::cout << "In mult_expr -> mult_expr mulop term:" << std::endl
        //     << "term.code.size(): " << $3.code.size() << std::endl
        //     << "term.code[0]: " << $3.code[0] << ", term.code[1]" << $3.code[1] << std::endl
        //     << std::endl;
    }
#line 1317 "y.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 666 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = "*"; }
#line 1323 "y.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 667 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = "/"; }
#line 1329 "y.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 668 "mini_ll.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = "%"; }
#line 1335 "y.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 673 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("term -> var\n"); 
        yylhs.value.as< ExprStruct > () = yystack_[0].value.as< ExprStruct > ();
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

    }
#line 1349 "y.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 682 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("term -> SUB var\n");

        yylhs.value.as< ExprStruct > () = yystack_[0].value.as< ExprStruct > ();

        std::string twoTemp = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + twoTemp);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + twoTemp + ", " + "2");

        std::string doubleTemp = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + doubleTemp);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + doubleTemp + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

        // Right now the var is in doubleTemp,
        // and 2 is in twoTemp

        // doubleTemp *= 2
        yylhs.value.as< ExprStruct > ().code.push_back("* " + doubleTemp + ", " + doubleTemp + ", " + twoTemp);

        // Give $$ its own copy of the original var
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[0].value.as< ExprStruct > ().reg_name);

        // Now, do $$ -= doubleTemp
        yylhs.value.as< ExprStruct > ().code.push_back("- " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yylhs.value.as< ExprStruct > ().reg_name + ", " + doubleTemp);
    }
#line 1382 "y.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 710 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print_int("term -> NUMBER %d\n", yystack_[0].value.as< int > ());

        //ExprStruct es;
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", " + std::to_string(yystack_[0].value.as< int > ()));
    }
#line 1396 "y.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 720 "mini_ll.yy" // lalr1.cc:859
    { 
        debug_print_int("term -> SUB NUMBER %d\n", yystack_[0].value.as< int > ()); 

        ExprStruct number_es;

        // Give number_es.reg_name a register and declare it
        number_es.reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + number_es.reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + number_es.reg_name + ", " + std::to_string(yystack_[0].value.as< int > ()));

        // Put the result for 0 - number_es.reg_name into $$
        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("- " + yylhs.value.as< ExprStruct > ().reg_name + ", 0, " + number_es.reg_name);

    }
#line 1417 "y.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 736 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("term -> L_PAREN expression R_PAREN\n");

        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[1].value.as< ExprStruct > ().code.begin(), yystack_[1].value.as< ExprStruct > ().code.end());

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[1].value.as< ExprStruct > ().reg_name);

    }
#line 1433 "y.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 748 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("term -> SUB L_PAREN expression R_PAREN\n");

        yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), yystack_[1].value.as< ExprStruct > ().code.begin(), yystack_[1].value.as< ExprStruct > ().code.end());

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("= " + yylhs.value.as< ExprStruct > ().reg_name + ", " + yystack_[1].value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("- " + yylhs.value.as< ExprStruct > ().reg_name + ", 0, " + yylhs.value.as< ExprStruct > ().reg_name);

    }
#line 1450 "y.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 760 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print_char("term -> IDENTIFIER %s L_PAREN R_PAREN\n", yystack_[2].value.as< std::string > ());

        if (!isInSymbolTable(yystack_[2].value.as< std::string > ())) {

            yy::parser::error(yystack_[2].location, "Function \"" + yystack_[2].value.as< std::string > () + "\" has not been declared in the current context");
        }

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("call " + yystack_[2].value.as< std::string > () + ", " + yylhs.value.as< ExprStruct > ().reg_name);
    }
#line 1468 "y.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 774 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print_char("term -> IDENTIFIER %s L_PAREN expression_loop R_PAREN\n", yystack_[3].value.as< std::string > ());

        if (!isInSymbolTable(yystack_[3].value.as< std::string > ())) {

            yy::parser::error(yystack_[3].location, "Function \"" + yystack_[3].value.as< std::string > () + "\" has not been declared in the current context");
        }
        if (!checkIdType(yystack_[3].value.as< std::string > (), IdentType::FUNCTION)) {

            yy::parser::error(yystack_[3].location, "Attempted to call non-function \"" + yystack_[3].value.as< std::string > () + "\"");
        }

        for (ExprStruct this_expr_struct : yystack_[1].value.as< std::vector<ExprStruct> > ()) {

            yylhs.value.as< ExprStruct > ().code.insert(yylhs.value.as< ExprStruct > ().code.end(), this_expr_struct.code.begin(), this_expr_struct.code.end());
            yylhs.value.as< ExprStruct > ().code.push_back("param " + this_expr_struct.reg_name);
        }

        yylhs.value.as< ExprStruct > ().reg_name = generateTempReg();
        yylhs.value.as< ExprStruct > ().code.push_back(". " + yylhs.value.as< ExprStruct > ().reg_name);
        yylhs.value.as< ExprStruct > ().code.push_back("call " + yystack_[3].value.as< std::string > () + ", " + yylhs.value.as< ExprStruct > ().reg_name);

        paramCount = 0;

    }
#line 1499 "y.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 804 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("expression_loop -> expression");

        yystack_[0].value.as< ExprStruct > ().reg_name = generateTempReg();
        yystack_[0].value.as< ExprStruct > ().code.push_back(". " + yystack_[0].value.as< ExprStruct > ().reg_name);
        // $1.code.push_back("= " + $1.reg_name + ", $" + paramCount);

        yylhs.value.as< std::vector<ExprStruct> > ().push_back(yystack_[0].value.as< ExprStruct > ());

        paramCount++;
    }
#line 1516 "y.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 817 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print("expression_loop -> expression_loop COMMA expression");

        yylhs.value.as< std::vector<ExprStruct> > () = yystack_[2].value.as< std::vector<ExprStruct> > ();

        yylhs.value.as< std::vector<ExprStruct> > ().push_back(yystack_[0].value.as< ExprStruct > ());
    }
#line 1529 "y.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 829 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print_char("var -> IDENTIFIER %s\n", yystack_[0].value.as< std::string > ());

        if (!isInSymbolTable(yystack_[0].value.as< std::string > ())) {

            yy::parser::error(yystack_[0].location, "Attempted to use undeclared variable \"" + yystack_[0].value.as< std::string > () + "\".");
        }

        else if (checkIdType(yystack_[0].value.as< std::string > (), IdentType::ARRAY)) {

            yy::parser::error(yystack_[0].location, "Attempted to use array variable \"" + yystack_[0].value.as< std::string > () + "\" as a non-array variable.");
        }

        ExprStruct es;
        es.reg_name = yystack_[0].value.as< std::string > ();
        // es.code.push_back(". " + $1);

        yylhs.value.as< ExprStruct > () = es;
    }
#line 1554 "y.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 850 "mini_ll.yy" // lalr1.cc:859
    {

        debug_print_char("var -> IDENTIFIER %s L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n", yystack_[3].value.as< std::string > ());

        // $$ = ".[] " + $1 + ", " + $3;
        ExprStruct es;
        // es.original_name = $1;
        es.code.push_back(".[] " + yystack_[3].value.as< std::string > () + ", " + yystack_[1].value.as< ExprStruct > ().reg_name);
        es.reg_name = generateTempReg();

        yylhs.value.as< ExprStruct > () = es;
    }
#line 1571 "y.tab.cc" // lalr1.cc:859
    break;


#line 1575 "y.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -67;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
     -67,    49,   -67,   -35,   -67,   -67,     0,    14,   -67,    -3,
      47,   -67,    16,   -15,   -67,   -67,    78,    23,    -4,   -67,
      57,   -67,   102,    43,   156,    69,    -6,    -6,   105,   -67,
      79,    79,   122,    89,    58,    99,   111,     4,    71,   -67,
     -67,    28,    -6,    51,   -67,    10,   143,   -67,   159,    52,
     -67,   -67,    12,   -67,   127,   -67,   127,   122,   103,   122,
     -67,   135,   -67,   122,   170,   131,   -67,   -67,   159,   122,
     -67,   -67,   -17,    25,    92,   156,    -6,    -6,   122,   122,
     -67,   -67,   -67,   -67,   -67,   -67,   122,   -67,   -67,   -67,
     122,   -67,   156,    79,     9,   -18,   -67,   103,   -67,   136,
     122,   120,   -67,   -67,   -67,   103,    61,    96,   143,   -67,
      52,    52,   103,   -67,   156,   109,   -67,   -67,   172,   103,
     -67,   122,   -67,   -67,   156,   126,   165,   176,   103,   139,
     -67,    -6,   -67,   -67,   162
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     3,     5,     0,     0,     6,     0,
       0,    13,     0,     0,     6,     7,     0,     0,     0,    10,
       0,    14,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    63,     0,     0,     0,     0,     0,    34,
      36,     0,     0,    63,    55,     0,    28,    30,     0,    45,
      48,    53,     0,    20,    22,    26,    23,     0,    25,     0,
       4,     0,     8,     0,     0,     0,    35,    37,     0,     0,
      56,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,     0,    50,    51,    52,
       0,    18,     0,     0,     0,     0,     9,    15,    11,     0,
       0,     0,    38,    57,    59,    61,     0,     0,    29,    31,
      46,    47,    32,    49,     0,     0,    27,    64,     0,    33,
      58,     0,    60,    16,     0,     0,     0,     0,    62,     0,
      19,     0,    12,    17,    21
  };

  const short int
  parser::yypgoto_[] =
  {
     -67,   -67,   -67,    20,   177,   -66,   -67,   -67,   -33,   -67,
     -67,   161,   -23,   117,   123,   133,   -27,    85,   -67,   112,
     -67,   -24
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     4,    11,     9,    34,    12,    13,    35,   114,
      92,    54,    45,    46,    47,    86,    48,    49,    90,    50,
     106,    51
  };

  const unsigned char
  parser::yytable_[] =
  {
      36,    61,    10,    22,    52,    58,    55,    55,    76,   107,
      36,    68,    78,    79,     5,    73,    64,    71,     8,    72,
      38,    39,    40,     6,    75,    41,   115,    16,   102,   117,
      94,    91,    95,    17,     5,    76,    97,    76,    42,    78,
      79,     7,   101,    43,    44,     5,     5,   105,   125,     2,
      65,    36,     3,    14,   103,    78,    79,    15,   129,   112,
      80,    81,    82,    83,    84,    85,    21,    60,    36,   116,
     103,    26,    69,   119,    61,    27,    28,    33,    70,    29,
      30,    31,    61,    36,    87,    88,    89,    32,    19,    20,
      36,    36,    61,    25,   128,    74,    61,    59,    66,    67,
      36,    36,    41,    23,   121,    36,   122,    33,   134,    26,
      24,   123,   124,    27,    28,    57,    37,    29,    30,    31,
      43,    44,    26,    41,    53,    32,    27,    28,    33,   126,
      29,    30,    31,    78,    79,    59,    57,   104,    32,    26,
      62,    43,    44,    27,    28,    33,   130,    29,    30,    31,
      78,    79,    26,    41,   133,    32,    27,    28,    33,    63,
      29,    30,    31,   110,   111,   120,    57,    77,    32,    26,
      93,    43,    44,    27,    28,    33,    96,    29,    30,    31,
      98,    99,   131,   118,   127,    32,   132,    76,    33,    78,
      79,    18,    56,   108,    80,    81,    82,    83,    84,    85,
     109,   100,   113,     0,     0,    33
  };

  const short int
  parser::yycheck_[] =
  {
      24,    34,     5,     7,    27,    32,    30,    31,    25,    75,
      34,    38,    30,    31,    49,    42,    12,    41,     4,    42,
      26,    27,    28,     3,    14,    31,    92,    42,    45,    47,
      57,    19,    59,    13,    49,    25,    63,    25,    44,    30,
      31,    41,    69,    49,    50,    49,    49,    74,   114,     0,
      46,    75,     3,     6,    45,    30,    31,    41,   124,    86,
      35,    36,    37,    38,    39,    40,    43,     9,    92,    93,
      45,    13,    44,   100,   107,    17,    18,    49,    50,    21,
      22,    23,   115,   107,    32,    33,    34,    29,    10,    11,
     114,   115,   125,    50,   121,    44,   129,    46,    27,    28,
     124,   125,    31,    46,    43,   129,    45,    49,   131,    13,
       8,    15,    16,    17,    18,    44,    47,    21,    22,    23,
      49,    50,    13,    31,    19,    29,    17,    18,    49,    20,
      21,    22,    23,    30,    31,    46,    44,    45,    29,    13,
      41,    49,    50,    17,    18,    49,    20,    21,    22,    23,
      30,    31,    13,    31,    15,    29,    17,    18,    49,    48,
      21,    22,    23,    78,    79,    45,    44,    24,    29,    13,
      43,    49,    50,    17,    18,    49,    41,    21,    22,    23,
      10,    50,    17,    47,    12,    29,    10,    25,    49,    30,
      31,    14,    31,    76,    35,    36,    37,    38,    39,    40,
      77,    68,    90,    -1,    -1,    49
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    53,     0,     3,    54,    49,    55,    41,     4,    56,
       5,    55,    58,    59,     6,    41,    42,    55,    56,    10,
      11,    43,     7,    46,     8,    50,    13,    17,    18,    21,
      22,    23,    29,    49,    57,    60,    73,    47,    26,    27,
      28,    31,    44,    49,    50,    64,    65,    66,    68,    69,
      71,    73,    64,    19,    63,    73,    63,    44,    68,    46,
       9,    60,    41,    48,    12,    46,    27,    28,    68,    44,
      50,    73,    64,    68,    44,    14,    25,    24,    30,    31,
      35,    36,    37,    38,    39,    40,    67,    32,    33,    34,
      70,    19,    62,    43,    68,    68,    41,    68,    10,    50,
      67,    68,    45,    45,    45,    68,    72,    57,    65,    66,
      69,    69,    68,    71,    61,    57,    73,    47,    47,    68,
      45,    43,    45,    15,    16,    57,    20,    12,    68,    57,
      20,    17,    10,    15,    64
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    52,    53,    53,    54,    55,    56,    56,    57,    57,
      58,    58,    58,    59,    59,    60,    60,    60,    61,    60,
      62,    60,    60,    60,    60,    60,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,    12,     1,     0,     3,     2,     3,
       3,     8,    11,     1,     3,     3,     5,     7,     0,     6,
       0,     7,     2,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     3,     4,     1,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     2,     3,     4,     3,
       4,     1,     3,     1,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS",
  "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY",
  "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO",
  "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT",
  "TRUE", "FALSE", "RETURN", "ADD", "SUB", "MULT", "DIV", "MOD", "EQ",
  "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA",
  "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN",
  "IDENTIFIER", "NUMBER", "UMINUS", "$accept", "program", "function",
  "identifier", "declaration_loop", "statement_loop", "declaration",
  "identifier_loop", "statement", "$@1", "$@2", "var_loop", "bool_expr",
  "relation_and_expr", "relation_expr", "comp", "expression", "mult_expr",
  "mulop", "term", "expression_loop", "var", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   182,   182,   183,   186,   202,   209,   213,   224,   228,
     235,   242,   249,   259,   263,   274,   284,   321,   359,   359,
     396,   396,   427,   444,   456,   474,   488,   495,   504,   509,
     516,   521,   529,   543,   560,   569,   576,   584,   592,   604,
     605,   606,   607,   608,   609,   613,   617,   630,   645,   650,
     666,   667,   668,   673,   682,   710,   720,   736,   748,   760,
     774,   804,   817,   829,   850
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
#line 2049 "y.tab.cc" // lalr1.cc:1167
#line 868 "mini_ll.yy" // lalr1.cc:1168


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
