/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "parser.y"


#include <iostream>
#include <memory>
#include <string>
#include "AST.h"

int yylex();
void yyerror(std::unique_ptr<AST> &ast, const char* s);

using namespace std;


#line 85 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LOWER_THAN_ELSE = 3,            /* LOWER_THAN_ELSE  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_LESS_EQ = 8,                    /* LESS_EQ  */
  YYSYMBOL_GREAT_EQ = 9,                   /* GREAT_EQ  */
  YYSYMBOL_EQUAL = 10,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 11,                 /* NOT_EQUAL  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_IDENT = 18,                     /* IDENT  */
  YYSYMBOL_INT_CONST = 19,                 /* INT_CONST  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_21_ = 21,                       /* ','  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '['  */
  YYSYMBOL_24_ = 24,                       /* ']'  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '!'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_CompUnit = 38,                  /* CompUnit  */
  YYSYMBOL_GlobalDef = 39,                 /* GlobalDef  */
  YYSYMBOL_Decl = 40,                      /* Decl  */
  YYSYMBOL_VarDecl = 41,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 42,                /* VarDefList  */
  YYSYMBOL_VarDef = 43,                    /* VarDef  */
  YYSYMBOL_IntConstList = 44,              /* IntConstList  */
  YYSYMBOL_InitVal = 45,                   /* InitVal  */
  YYSYMBOL_FuncDef = 46,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 47,               /* FuncFParams  */
  YYSYMBOL_FuncFParamList = 48,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 49,                /* FuncFParam  */
  YYSYMBOL_Block = 50,                     /* Block  */
  YYSYMBOL_BlockItemList = 51,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 52,                 /* BlockItem  */
  YYSYMBOL_Stmt = 53,                      /* Stmt  */
  YYSYMBOL_Exp = 54,                       /* Exp  */
  YYSYMBOL_LVal = 55,                      /* LVal  */
  YYSYMBOL_ExpList = 56,                   /* ExpList  */
  YYSYMBOL_PrimaryExp = 57,                /* PrimaryExp  */
  YYSYMBOL_Number = 58,                    /* Number  */
  YYSYMBOL_UnaryExp = 59,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 60,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 61,               /* FuncRParams  */
  YYSYMBOL_ExpIter = 62,                   /* ExpIter  */
  YYSYMBOL_MulExp = 63,                    /* MulExp  */
  YYSYMBOL_AddExp = 64,                    /* AddExp  */
  YYSYMBOL_RelExp = 65,                    /* RelExp  */
  YYSYMBOL_EqExp = 66,                     /* EqExp  */
  YYSYMBOL_LAndExp = 67,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 68                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,    34,     2,     2,
      25,    26,    32,    29,    21,    30,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
      35,    22,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    43,    54,    65,    69,    81,    87,    98,
     106,   111,   117,   122,   137,   145,   150,   156,   162,   168,
     175,   194,   204,   212,   217,   223,   232,   241,   249,   254,
     259,   266,   272,   277,   282,   288,   295,   301,   305,   309,
     313,   320,   326,   331,   344,   352,   357,   362,   367,   374,
     380,   385,   390,   396,   404,   408,   412,   418,   429,   437,
     442,   447,   454,   461,   470,   475,   482,   491,   496,   504,
     512,   520,   530,   535,   543,   553,   558,   566,   571
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LOWER_THAN_ELSE",
  "ELSE", "INT", "VOID", "RETURN", "LESS_EQ", "GREAT_EQ", "EQUAL",
  "NOT_EQUAL", "AND", "OR", "IF", "WHILE", "BREAK", "CONTINUE", "IDENT",
  "INT_CONST", "';'", "','", "'='", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "'+'", "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "$accept",
  "CompUnit", "GlobalDef", "Decl", "VarDecl", "VarDefList", "VarDef",
  "IntConstList", "InitVal", "FuncDef", "FuncFParams", "FuncFParamList",
  "FuncFParam", "Block", "BlockItemList", "BlockItem", "Stmt", "Exp",
  "LVal", "ExpList", "PrimaryExp", "Number", "UnaryExp", "UnaryOp",
  "FuncRParams", "ExpIter", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,     0,     7,    43,    24,  -114,  -114,  -114,    74,    30,
      47,  -114,  -114,  -114,    62,    64,     5,    72,    78,    18,
      32,  -114,    62,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,    62,    69,    56,    -2,    94,    82,    93,    89,
      97,    90,    92,   100,    87,    30,  -114,    90,    96,    62,
      48,    98,  -114,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,   102,   103,    -3,  -114,
      90,   118,  -114,  -114,  -114,    90,   104,  -114,   106,   105,
    -114,  -114,  -114,  -114,    69,    69,    56,    56,    56,    56,
      -2,    -2,    94,    82,   110,  -114,   108,    72,    34,   109,
     111,   113,   115,  -114,  -114,   112,    -3,  -114,   117,   116,
    -114,   100,  -114,   107,    62,  -114,  -114,   119,   102,  -114,
     121,    62,    62,  -114,  -114,  -114,  -114,  -114,    62,  -114,
      62,  -114,   106,   102,  -114,  -114,   120,   122,   124,   123,
    -114,  -114,    31,    31,  -114,   107,   135,  -114,  -114,    31,
    -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     5,     7,     6,    12,    10,
       0,     1,     3,     4,     0,     0,     0,     0,     0,     0,
      42,    49,     0,    54,    55,    56,    11,    16,    47,    50,
      48,    60,     0,    64,    67,    72,    75,    77,    41,     0,
       0,     0,     0,    23,    12,    10,     8,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    24,    28,    17,
       0,     0,    21,     9,    18,     0,     0,    51,    59,     0,
      46,    61,    62,    63,    65,    66,    70,    71,    68,    69,
      73,    74,    76,    78,     0,    13,     0,     0,     0,     0,
       0,     0,     0,    29,    33,     0,    28,    30,     0,    47,
      19,    23,    20,    45,     0,    57,    52,     0,    15,    39,
       0,     0,     0,    37,    38,    26,    27,    32,     0,    22,
       0,    43,    59,    15,    25,    40,     0,     0,     0,     0,
      58,    14,     0,     0,    31,    45,    34,    36,    44,     0,
      35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,    17,  -114,   114,   125,  -113,  -114,   141,
     130,    39,    80,   -38,    46,  -114,   -54,   -14,   -67,     8,
    -114,  -114,   -13,  -114,  -114,    22,    55,    10,    57,    91,
      95,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,   103,     6,    18,     9,    95,    26,     7,
      42,    72,    43,   104,   105,   106,   107,   108,    28,   131,
      29,    30,    31,    32,    79,   115,    33,    34,    35,    36,
      37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,   109,    97,    69,    98,   134,    58,    59,    51,    74,
      40,    99,   100,   101,   102,    20,    21,     5,     8,    52,
     141,    12,    22,    40,    68,    10,    23,    24,    25,     1,
       2,    41,   110,    60,    61,    76,    78,   112,    98,   109,
      81,    82,    83,    11,    47,    99,   100,   101,   102,    20,
      21,    17,    20,    21,   119,    49,    22,    50,    68,    22,
      23,    24,    25,    23,    24,    25,    20,    21,    86,    87,
      88,    89,    19,    22,    77,   109,   109,    23,    24,    25,
      20,    21,   109,    39,   120,    56,    57,    22,   146,   147,
      44,    23,    24,    25,    64,   150,    14,    15,    46,    16,
     132,    53,    54,    55,    62,    63,    65,   136,   137,    14,
      15,    84,    85,    66,   138,    67,   139,    68,    70,    90,
      91,    71,    75,    40,    80,    94,    96,   114,   113,   117,
     130,   116,   118,   123,   121,   124,   122,   127,   128,   149,
     125,   135,    45,   133,   144,    13,   142,   145,   143,    48,
     129,   111,   126,   148,   140,    92,     0,     0,     0,    73,
      93
};

static const yytype_int16 yycheck[] =
{
      14,    68,     5,    41,     7,   118,     8,     9,    22,    47,
       5,    14,    15,    16,    17,    18,    19,     0,    18,    32,
     133,     4,    25,     5,    27,    18,    29,    30,    31,     5,
       6,    26,    70,    35,    36,    49,    50,    75,     7,   106,
      53,    54,    55,     0,    26,    14,    15,    16,    17,    18,
      19,    21,    18,    19,    20,    23,    25,    25,    27,    25,
      29,    30,    31,    29,    30,    31,    18,    19,    58,    59,
      60,    61,    25,    25,    26,   142,   143,    29,    30,    31,
      18,    19,   149,    19,    98,    29,    30,    25,   142,   143,
      18,    29,    30,    31,    12,   149,    22,    23,    20,    25,
     114,    32,    33,    34,    10,    11,    13,   121,   122,    22,
      23,    56,    57,    24,   128,    18,   130,    27,    26,    62,
      63,    21,    26,     5,    26,    23,    23,    21,    24,    19,
      23,    26,    24,    20,    25,    20,    25,    20,    22,     4,
      28,    20,    17,    24,    20,     4,    26,    24,    26,    19,
     111,    71,   106,   145,   132,    64,    -1,    -1,    -1,    45,
      65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    38,    39,    40,    41,    46,    18,    43,
      18,     0,    40,    46,    22,    23,    25,    21,    42,    25,
      18,    19,    25,    29,    30,    31,    45,    54,    55,    57,
      58,    59,    60,    63,    64,    65,    66,    67,    68,    19,
       5,    26,    47,    49,    18,    43,    20,    26,    47,    23,
      25,    54,    59,    32,    33,    34,    29,    30,     8,     9,
      35,    36,    10,    11,    12,    13,    24,    18,    27,    50,
      26,    21,    48,    42,    50,    26,    54,    26,    54,    61,
      26,    59,    59,    59,    63,    63,    64,    64,    64,    64,
      65,    65,    66,    67,    23,    44,    23,     5,     7,    14,
      15,    16,    17,    40,    50,    51,    52,    53,    54,    55,
      50,    49,    50,    24,    21,    62,    26,    19,    24,    20,
      54,    25,    25,    20,    20,    28,    51,    20,    22,    48,
      23,    56,    54,    24,    44,    20,    54,    54,    54,    54,
      62,    44,    26,    26,    20,    24,    53,    53,    56,     4,
      53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    40,    41,    42,
      42,    43,    43,    43,    44,    44,    45,    46,    46,    46,
      46,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      59,    59,    59,    59,    60,    60,    60,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     4,     3,
       0,     3,     1,     5,     4,     0,     1,     5,     5,     6,
       6,     2,     3,     0,     2,     5,     3,     2,     0,     1,
       1,     4,     2,     1,     5,     7,     5,     2,     2,     2,
       3,     1,     1,     5,     4,     0,     3,     1,     1,     1,
       1,     3,     4,     2,     1,     1,     1,     2,     3,     0,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (ast, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::unique_ptr<AST>& ast)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::unique_ptr<AST>& ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::unique_ptr<AST>& ast)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::unique_ptr<AST>& ast)
{
  YY_USE (yyvaluep);
  YY_USE (ast);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::unique_ptr<AST>& ast)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* CompUnit: GlobalDef  */
#line 38 "parser.y"
                     {
    auto comp_unit = unique_ptr<CompUnit>((CompUnit*) (yyvsp[0].ast_val));
    ast = move(comp_unit);
}
#line 1246 "parser.cpp"
    break;

  case 3: /* GlobalDef: GlobalDef Decl  */
#line 43 "parser.y"
                           {
    auto comp_unit = new CompUnit();
    auto comp_units_it = unique_ptr<CompUnit>((CompUnit*) (yyvsp[-1].ast_val));
    for(auto &it : comp_units_it->decls){
        comp_unit->decls.emplace_back(it.release());
    }
    for(auto &it : comp_units_it->funcdefs){
        comp_unit->funcdefs.emplace_back(it.release());
    }
    comp_unit->decls.emplace_back((Decl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = comp_unit;
}
#line 1263 "parser.cpp"
    break;

  case 4: /* GlobalDef: GlobalDef FuncDef  */
#line 54 "parser.y"
                      {
    auto comp_unit = new CompUnit();
    auto comp_units_it = unique_ptr<CompUnit>((CompUnit*) (yyvsp[-1].ast_val));
    for(auto &it : comp_units_it->decls){
        comp_unit->decls.emplace_back(it.release());
    }
    for(auto &it : comp_units_it->funcdefs){
        comp_unit->funcdefs.emplace_back(it.release());
    }
    comp_unit->funcdefs.emplace_back((FuncDef*) (yyvsp[0].ast_val));
    (yyval.ast_val) = comp_unit;
}
#line 1280 "parser.cpp"
    break;

  case 5: /* GlobalDef: Decl  */
#line 65 "parser.y"
         {
    auto comp_unit = new CompUnit();
    comp_unit->decls.emplace_back((Decl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = comp_unit;
}
#line 1290 "parser.cpp"
    break;

  case 6: /* GlobalDef: FuncDef  */
#line 69 "parser.y"
            {
    auto comp_unit = new CompUnit();
    comp_unit->funcdefs.emplace_back((FuncDef*) (yyvsp[0].ast_val));
    (yyval.ast_val) = comp_unit;
}
#line 1300 "parser.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 81 "parser.y"
               {
    auto decl = new Decl();
    decl->vardecl = unique_ptr<VarDecl>((VarDecl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = decl;
}
#line 1310 "parser.cpp"
    break;

  case 8: /* VarDecl: INT VarDef VarDefList ';'  */
#line 87 "parser.y"
                                    {
    auto var_decl = new VarDecl(); 
    auto var_def_list = unique_ptr<VarDecl>((VarDecl*) (yyvsp[-1].ast_val));
    var_decl->btype = (string)"int"; 
    var_decl->vardefs.emplace_back((VarDef*) (yyvsp[-2].ast_val));
    for(auto &it : var_def_list->vardefs){
        var_decl->vardefs.emplace_back(it.release());
    }
    (yyval.ast_val) = var_decl;
}
#line 1325 "parser.cpp"
    break;

  case 9: /* VarDefList: ',' VarDef VarDefList  */
#line 98 "parser.y"
                                   {
    auto var_def_list = new VarDecl();
    auto var_def_list_it = unique_ptr<VarDecl>((VarDecl*) (yyvsp[0].ast_val));
    var_def_list->vardefs.emplace_back((VarDef*) (yyvsp[-1].ast_val));
    for(auto &it : var_def_list_it->vardefs){
        var_def_list->vardefs.emplace_back(it.release());
    }
    (yyval.ast_val) = var_def_list;
}
#line 1339 "parser.cpp"
    break;

  case 10: /* VarDefList: %empty  */
#line 106 "parser.y"
           {
    auto var_def_list = new VarDecl();
    (yyval.ast_val) = var_def_list;
}
#line 1348 "parser.cpp"
    break;

  case 11: /* VarDef: IDENT '=' InitVal  */
#line 111 "parser.y"
                           {
    auto var_def = new VarDef();
    var_def->tag = VarDef::VARIABLE;
    var_def->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    var_def->initval = unique_ptr<InitVal>((InitVal*) (yyvsp[0].ast_val));
    (yyval.ast_val) = var_def;
}
#line 1360 "parser.cpp"
    break;

  case 12: /* VarDef: IDENT  */
#line 117 "parser.y"
          {
    auto var_def = new VarDef();
    var_def->tag = VarDef::VARIABLE;
    var_def->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = var_def;
}
#line 1371 "parser.cpp"
    break;

  case 13: /* VarDef: IDENT '[' INT_CONST ']' IntConstList  */
#line 122 "parser.y"
                                         {
    auto var_def = new VarDef();
    auto temp_list = new IntConstList();
    auto int_const_list = unique_ptr<IntConstList>((IntConstList*) (yyvsp[0].ast_val));
    temp_list->list.emplace_back((int) (yyvsp[-2].int_val));
    for(int i = 0; i < int_const_list->list.size(); ++i){
        temp_list->list.emplace_back(int_const_list->list[i]);
    }
    var_def->tag = VarDef::ARRAY;
    var_def->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    var_def->int_consts = unique_ptr<IntConstList>((IntConstList*) temp_list);
    (yyval.ast_val) = var_def;
}
#line 1389 "parser.cpp"
    break;

  case 14: /* IntConstList: '[' INT_CONST ']' IntConstList  */
#line 137 "parser.y"
                                              {
    auto int_const_list = new IntConstList();
    auto int_const_list_it = unique_ptr<IntConstList>((IntConstList*) (yyvsp[0].ast_val));
    int_const_list->list.emplace_back((int) (yyvsp[-2].int_val));
    for(int i = 0; i < int_const_list_it->list.size(); ++i){
        int_const_list->list.emplace_back(int_const_list_it->list[i]);
    }
    (yyval.ast_val) = int_const_list;
}
#line 1403 "parser.cpp"
    break;

  case 15: /* IntConstList: %empty  */
#line 145 "parser.y"
           {
    auto int_const_list = new IntConstList();
    (yyval.ast_val) = int_const_list;
}
#line 1412 "parser.cpp"
    break;

  case 16: /* InitVal: Exp  */
#line 150 "parser.y"
              {
    auto init_val = new InitVal();
    init_val->exp = unique_ptr<Exp>((Exp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = init_val;
}
#line 1422 "parser.cpp"
    break;

  case 17: /* FuncDef: INT IDENT '(' ')' Block  */
#line 156 "parser.y"
                                  {
    auto func_def = new FuncDef();
    func_def->functype = (string)"int";
    func_def->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1434 "parser.cpp"
    break;

  case 18: /* FuncDef: VOID IDENT '(' ')' Block  */
#line 162 "parser.y"
                             {
    auto func_def = new FuncDef();
    func_def->functype = (string)"void";
    func_def->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1446 "parser.cpp"
    break;

  case 19: /* FuncDef: INT IDENT '(' FuncFParams ')' Block  */
#line 168 "parser.y"
                                        {
    auto func_def = new FuncDef();
    func_def->functype = (string)"int";
    func_def->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    func_def->funcfparams = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[-2].ast_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1459 "parser.cpp"
    break;

  case 20: /* FuncDef: VOID IDENT '(' FuncFParams ')' Block  */
#line 175 "parser.y"
                                         {
    auto func_def = new FuncDef();
    func_def->functype = (string)"void";
    func_def->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    func_def->funcfparams = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[-2].ast_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1472 "parser.cpp"
    break;

  case 21: /* FuncFParams: FuncFParam FuncFParamList  */
#line 194 "parser.y"
                                        {
    auto func_f_params = new FuncFParams();
    auto func_f_param_list = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[0].ast_val));
    func_f_params->funcfparams.emplace_back((FuncFParam*) (yyvsp[-1].ast_val));
    for(auto &it : func_f_param_list->funcfparams){
        func_f_params->funcfparams.emplace_back(it.release());
    }
    (yyval.ast_val) = func_f_params;
}
#line 1486 "parser.cpp"
    break;

  case 22: /* FuncFParamList: ',' FuncFParam FuncFParamList  */
#line 204 "parser.y"
                                               {
    auto func_f_param_list = new FuncFParams();
    auto func_f_param_list_it = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[0].ast_val));
    func_f_param_list->funcfparams.emplace_back((FuncFParam*) (yyvsp[-1].ast_val));
    for(auto &it : func_f_param_list_it->funcfparams){
        func_f_param_list->funcfparams.emplace_back(it.release());
    }
    (yyval.ast_val) = func_f_param_list;
}
#line 1500 "parser.cpp"
    break;

  case 23: /* FuncFParamList: %empty  */
#line 212 "parser.y"
           {
    auto func_f_param_list = new FuncFParams();
    (yyval.ast_val) = func_f_param_list;
}
#line 1509 "parser.cpp"
    break;

  case 24: /* FuncFParam: INT IDENT  */
#line 217 "parser.y"
                       {
    auto func_f_param = new FuncFParam();
    func_f_param->tag = FuncFParam::VARIABLE;
    func_f_param->btype = (string)"int";
    func_f_param->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = func_f_param;
}
#line 1521 "parser.cpp"
    break;

  case 25: /* FuncFParam: INT IDENT '[' ']' IntConstList  */
#line 223 "parser.y"
                                   {
    auto func_f_param = new FuncFParam();
    func_f_param->tag = FuncFParam::ARRAY;
    func_f_param->btype = (string)"int";
    func_f_param->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    func_f_param->int_consts = unique_ptr<IntConstList>((IntConstList*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_f_param;    
}
#line 1534 "parser.cpp"
    break;

  case 26: /* Block: '{' BlockItemList '}'  */
#line 232 "parser.y"
                              {
    auto block = new Block();
    auto block_item_list = unique_ptr<Block>((Block*) (yyvsp[-1].ast_val));
    for(auto &it : block_item_list->blockitems){
        block->blockitems.emplace_back(it.release());
    }    
    (yyval.ast_val) = block;
}
#line 1547 "parser.cpp"
    break;

  case 27: /* BlockItemList: BlockItem BlockItemList  */
#line 241 "parser.y"
                                        {
    auto block_item_list = new Block();
    auto block_item_list_it = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    block_item_list->blockitems.emplace_back((BlockItem*) (yyvsp[-1].ast_val));
    for(auto &it : block_item_list_it->blockitems){
        block_item_list->blockitems.emplace_back(it.release());
    }
    (yyval.ast_val) = block_item_list;
}
#line 1561 "parser.cpp"
    break;

  case 28: /* BlockItemList: %empty  */
#line 249 "parser.y"
           {
    auto block_item_list = new Block();
    (yyval.ast_val) = block_item_list;
}
#line 1570 "parser.cpp"
    break;

  case 29: /* BlockItem: Decl  */
#line 254 "parser.y"
                 {
    auto block_item = new BlockItem();
    block_item->tag = BlockItem::DECL;
    block_item->decl = unique_ptr<Decl>((Decl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = block_item; 
}
#line 1581 "parser.cpp"
    break;

  case 30: /* BlockItem: Stmt  */
#line 259 "parser.y"
         {
    auto block_item = new BlockItem();
    block_item->tag = BlockItem::STMT;
    block_item->stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));
    (yyval.ast_val) = block_item; 
}
#line 1592 "parser.cpp"
    break;

  case 31: /* Stmt: LVal '=' Exp ';'  */
#line 266 "parser.y"
                       {
    auto stmt = new Stmt();
    stmt->tag = Stmt::ASSIGN;
    stmt->lval = unique_ptr<LVal>((LVal*) (yyvsp[-3].ast_val));
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1604 "parser.cpp"
    break;

  case 32: /* Stmt: Exp ';'  */
#line 272 "parser.y"
            {
    auto stmt = new Stmt();
    stmt->tag = Stmt::EXP;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1615 "parser.cpp"
    break;

  case 33: /* Stmt: Block  */
#line 277 "parser.y"
          {
    auto stmt = new Stmt();
    stmt->tag = Stmt::BLOCK;
    stmt->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1626 "parser.cpp"
    break;

  case 34: /* Stmt: IF '(' Exp ')' Stmt  */
#line 282 "parser.y"
                                              {
    auto stmt = new Stmt();
    stmt->tag = Stmt::IF;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-2].ast_val));
    stmt->if_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1638 "parser.cpp"
    break;

  case 35: /* Stmt: IF '(' Exp ')' Stmt ELSE Stmt  */
#line 288 "parser.y"
                                  {
    auto stmt = new Stmt();
    stmt->tag = Stmt::IF;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-4].ast_val));
    stmt->if_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[-2].ast_val));
    stmt->else_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));    
    (yyval.ast_val) = stmt;    
}
#line 1651 "parser.cpp"
    break;

  case 36: /* Stmt: WHILE '(' Exp ')' Stmt  */
#line 295 "parser.y"
                           {
    auto stmt = new Stmt();
    stmt->tag = Stmt::WHILE;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-2].ast_val));
    stmt->while_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1663 "parser.cpp"
    break;

  case 37: /* Stmt: BREAK ';'  */
#line 301 "parser.y"
              {
    auto stmt = new Stmt();
    stmt->tag = Stmt::BREAK;
    (yyval.ast_val) = stmt;
}
#line 1673 "parser.cpp"
    break;

  case 38: /* Stmt: CONTINUE ';'  */
#line 305 "parser.y"
                 {
    auto stmt = new Stmt();
    stmt->tag = Stmt::CONTINUE;
    (yyval.ast_val) = stmt;
}
#line 1683 "parser.cpp"
    break;

  case 39: /* Stmt: RETURN ';'  */
#line 309 "parser.y"
               {
    auto stmt = new Stmt();
    stmt->tag = Stmt::RETURN;
    (yyval.ast_val) = stmt;
}
#line 1693 "parser.cpp"
    break;

  case 40: /* Stmt: RETURN Exp ';'  */
#line 313 "parser.y"
                   {
    auto stmt = new Stmt();
    stmt->tag = Stmt::RETURN;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1704 "parser.cpp"
    break;

  case 41: /* Exp: LOrExp  */
#line 320 "parser.y"
             {
    auto exp = new Exp();
    exp->lorexp = unique_ptr<LOrExp>((LOrExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = exp;
}
#line 1714 "parser.cpp"
    break;

  case 42: /* LVal: IDENT  */
#line 326 "parser.y"
             {
    auto lval = new LVal();
    lval->tag = LVal::VARIABLE;
    lval->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = lval;
}
#line 1725 "parser.cpp"
    break;

  case 43: /* LVal: IDENT '[' Exp ']' ExpList  */
#line 331 "parser.y"
                              {
    auto lval = new LVal();
    auto exp_list = unique_ptr<LVal>((LVal*) (yyvsp[0].ast_val));
    lval->tag = LVal::VARIABLE;
    lval->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    lval->exps.emplace_back((Exp*) (yyvsp[-2].ast_val));
    for(auto &it : exp_list->exps){
        lval->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = lval;    
}
#line 1741 "parser.cpp"
    break;

  case 44: /* ExpList: '[' Exp ']' ExpList  */
#line 344 "parser.y"
                              {
    auto exp_list = new LVal();
    auto exp_list_it = unique_ptr<LVal>((LVal*) (yyvsp[0].ast_val));
    exp_list->exps.emplace_back((Exp*) (yyvsp[-2].ast_val));
    for(auto &it: exp_list_it->exps){
        exp_list->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = exp_list;
}
#line 1755 "parser.cpp"
    break;

  case 45: /* ExpList: %empty  */
#line 352 "parser.y"
           {
    auto exp_list = new LVal();
    (yyval.ast_val) = exp_list;
}
#line 1764 "parser.cpp"
    break;

  case 46: /* PrimaryExp: '(' Exp ')'  */
#line 357 "parser.y"
                        {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::EXP;
    primary_exp->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = primary_exp;
}
#line 1775 "parser.cpp"
    break;

  case 47: /* PrimaryExp: LVal  */
#line 362 "parser.y"
         {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::LVAL;
    primary_exp->lval = unique_ptr<LVal>((LVal*) (yyvsp[0].ast_val));
    (yyval.ast_val) = primary_exp;
}
#line 1786 "parser.cpp"
    break;

  case 48: /* PrimaryExp: Number  */
#line 367 "parser.y"
           {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::NUMBER;
    primary_exp->number = unique_ptr<Number>((Number*) (yyvsp[0].ast_val));
    (yyval.ast_val) = primary_exp;
}
#line 1797 "parser.cpp"
    break;

  case 49: /* Number: INT_CONST  */
#line 374 "parser.y"
                   {
    auto number = new Number();
    number->num = (int) (yyvsp[0].int_val);
    (yyval.ast_val) = number;
}
#line 1807 "parser.cpp"
    break;

  case 50: /* UnaryExp: PrimaryExp  */
#line 380 "parser.y"
                      {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::PRIMARY_EXP;
    unary_exp->primaryexp = unique_ptr<PrimaryExp>((PrimaryExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = unary_exp;
}
#line 1818 "parser.cpp"
    break;

  case 51: /* UnaryExp: IDENT '(' ')'  */
#line 385 "parser.y"
                  {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::FUNC;
    unary_exp->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    (yyval.ast_val) = unary_exp;
}
#line 1829 "parser.cpp"
    break;

  case 52: /* UnaryExp: IDENT '(' FuncRParams ')'  */
#line 390 "parser.y"
                              {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::FUNC;
    unary_exp->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    unary_exp->funcrparams = unique_ptr<FuncRParams>((FuncRParams*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = unary_exp;
}
#line 1841 "parser.cpp"
    break;

  case 53: /* UnaryExp: UnaryOp UnaryExp  */
#line 396 "parser.y"
                     {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::OP_EXP;
    unary_exp->unaryop = unique_ptr<UnaryOp>((UnaryOp*) (yyvsp[-1].ast_val));
    unary_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = unary_exp;
}
#line 1853 "parser.cpp"
    break;

  case 54: /* UnaryOp: '+'  */
#line 404 "parser.y"
              {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '+';
    (yyval.ast_val) = unary_op;
}
#line 1863 "parser.cpp"
    break;

  case 55: /* UnaryOp: '-'  */
#line 408 "parser.y"
        {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '-';
    (yyval.ast_val) = unary_op;
}
#line 1873 "parser.cpp"
    break;

  case 56: /* UnaryOp: '!'  */
#line 412 "parser.y"
        {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '!';
    (yyval.ast_val) = unary_op;
}
#line 1883 "parser.cpp"
    break;

  case 57: /* FuncRParams: Exp ExpIter  */
#line 418 "parser.y"
                         {
    auto func_r_params = new FuncRParams();
    auto exp_iter = unique_ptr<FuncRParams>((FuncRParams*) (yyvsp[0].ast_val));
    func_r_params->exps.emplace_back((Exp*) (yyvsp[-1].ast_val));
    for(auto &it : exp_iter->exps){
        func_r_params->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = func_r_params;
}
#line 1897 "parser.cpp"
    break;

  case 58: /* ExpIter: ',' Exp ExpIter  */
#line 429 "parser.y"
                         {
    auto exp_iter = new FuncRParams();
    auto exp_iter_it = unique_ptr<FuncRParams>((FuncRParams*) (yyvsp[0].ast_val));
    exp_iter->exps.emplace_back((Exp*) (yyvsp[-1].ast_val));
    for(auto &it : exp_iter_it->exps){
        exp_iter->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = exp_iter;
}
#line 1911 "parser.cpp"
    break;

  case 59: /* ExpIter: %empty  */
#line 437 "parser.y"
           {
    auto exp_iter = new FuncRParams();
    (yyval.ast_val) = exp_iter;
}
#line 1920 "parser.cpp"
    break;

  case 60: /* MulExp: UnaryExp  */
#line 442 "parser.y"
                  {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
}
#line 1931 "parser.cpp"
    break;

  case 61: /* MulExp: MulExp '*' UnaryExp  */
#line 447 "parser.y"
                        {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[-2].ast_val));
    mul_exp->op = '*';
    (yyval.ast_val) = mul_exp;
}
#line 1944 "parser.cpp"
    break;

  case 62: /* MulExp: MulExp '/' UnaryExp  */
#line 454 "parser.y"
                        {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[-2].ast_val));
    mul_exp->op = '/';
    (yyval.ast_val) = mul_exp;
}
#line 1957 "parser.cpp"
    break;

  case 63: /* MulExp: MulExp '%' UnaryExp  */
#line 461 "parser.y"
                        {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[-2].ast_val));
    mul_exp->op = '%';
    (yyval.ast_val) = mul_exp;
}
#line 1970 "parser.cpp"
    break;

  case 64: /* AddExp: MulExp  */
#line 470 "parser.y"
                {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::MULEXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = add_exp;
}
#line 1981 "parser.cpp"
    break;

  case 65: /* AddExp: AddExp '+' MulExp  */
#line 475 "parser.y"
                      {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::ADD_MUL_EXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[0].ast_val));
    add_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[-2].ast_val));
    add_exp->op = '+';
    (yyval.ast_val) = add_exp;
}
#line 1994 "parser.cpp"
    break;

  case 66: /* AddExp: AddExp '-' MulExp  */
#line 482 "parser.y"
                      {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::ADD_MUL_EXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[0].ast_val));
    add_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[-2].ast_val));
    add_exp->op = '-';
    (yyval.ast_val) = add_exp;
}
#line 2007 "parser.cpp"
    break;

  case 67: /* RelExp: AddExp  */
#line 491 "parser.y"
                {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::ADDEXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
}
#line 2018 "parser.cpp"
    break;

  case 68: /* RelExp: RelExp '<' AddExp  */
#line 496 "parser.y"
                      {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '<';
    rel_exp->op[1] = 0;
    (yyval.ast_val) = rel_exp;
}
#line 2032 "parser.cpp"
    break;

  case 69: /* RelExp: RelExp '>' AddExp  */
#line 504 "parser.y"
                      {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '>';
    rel_exp->op[1] = 0;
    (yyval.ast_val) = rel_exp;
}
#line 2046 "parser.cpp"
    break;

  case 70: /* RelExp: RelExp LESS_EQ AddExp  */
#line 512 "parser.y"
                          {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '<';
    rel_exp->op[1] = '=';
    (yyval.ast_val) = rel_exp;
}
#line 2060 "parser.cpp"
    break;

  case 71: /* RelExp: RelExp GREAT_EQ AddExp  */
#line 520 "parser.y"
                           {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '>';
    rel_exp->op[1] = '=';
    (yyval.ast_val) = rel_exp;
}
#line 2074 "parser.cpp"
    break;

  case 72: /* EqExp: RelExp  */
#line 530 "parser.y"
               {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::RELEXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = eq_exp;
}
#line 2085 "parser.cpp"
    break;

  case 73: /* EqExp: EqExp EQUAL RelExp  */
#line 535 "parser.y"
                      {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::EQ_REL_EXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[0].ast_val));
    eq_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[-2].ast_val));
    eq_exp->op[0] = '=';
    eq_exp->op[1] = '=';
    (yyval.ast_val) = eq_exp;
}
#line 2099 "parser.cpp"
    break;

  case 74: /* EqExp: EqExp NOT_EQUAL RelExp  */
#line 543 "parser.y"
                          {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::EQ_REL_EXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[0].ast_val));
    eq_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[-2].ast_val));
    eq_exp->op[0] = '!';
    eq_exp->op[1] = '=';
    (yyval.ast_val) = eq_exp;
}
#line 2113 "parser.cpp"
    break;

  case 75: /* LAndExp: EqExp  */
#line 553 "parser.y"
                {
    auto l_and_exp = new LAndExp();
    l_and_exp->tag = LAndExp::EQEXP;
    l_and_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = l_and_exp;
}
#line 2124 "parser.cpp"
    break;

  case 76: /* LAndExp: LAndExp AND EqExp  */
#line 558 "parser.y"
                      {
    auto l_and_exp = new LAndExp();
    l_and_exp->tag = LAndExp::LAND_EQ_EXP;
    l_and_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[0].ast_val));
    l_and_exp->landexp = unique_ptr<LAndExp>((LAndExp*) (yyvsp[-2].ast_val));
    (yyval.ast_val) = l_and_exp;
}
#line 2136 "parser.cpp"
    break;

  case 77: /* LOrExp: LAndExp  */
#line 566 "parser.y"
                 {
    auto l_or_exp = new LOrExp();
    l_or_exp->tag = LOrExp::LANDEXP;
    l_or_exp->landexp = unique_ptr<LAndExp>((LAndExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = l_or_exp;
}
#line 2147 "parser.cpp"
    break;

  case 78: /* LOrExp: LOrExp OR LAndExp  */
#line 571 "parser.y"
                      {
    auto l_or_exp = new LOrExp();
    l_or_exp->tag = LOrExp::LOR_LAND_EXP;
    l_or_exp->landexp = unique_ptr<LAndExp>((LAndExp*) (yyvsp[0].ast_val));
    l_or_exp->lorexp = unique_ptr<LOrExp>((LOrExp*) (yyvsp[-2].ast_val));
    (yyval.ast_val) = l_or_exp;
}
#line 2159 "parser.cpp"
    break;


#line 2163 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (ast, YY_("syntax error"));
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
                      yytoken, &yylval, ast);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 579 "parser.y"


void yyerror(unique_ptr<AST> &ast, const char *s) {
    cerr << "error: " << s << endl;
}


