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
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

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
     106,   111,   117,   126,   134,   139,   145,   151,   157,   164,
     183,   193,   201,   206,   212,   221,   230,   238,   243,   248,
     255,   261,   266,   271,   277,   284,   290,   294,   298,   302,
     309,   315,   320,   333,   341,   346,   351,   356,   363,   369,
     374,   379,   385,   393,   397,   401,   407,   418,   426,   431,
     436,   443,   450,   459,   464,   471,   480,   485,   493,   501,
     509,   519,   524,   532,   542,   547,   555,   560
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

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    -8,    36,    56,    20,  -133,  -133,  -133,    26,    11,
      25,  -133,  -133,  -133,    99,    63,    14,  -133,    65,    73,
      15,   -10,  -133,    99,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,    99,    32,   -12,    -5,    50,    80,    81,
      61,    77,    69,    78,    84,    45,    11,  -133,    69,    82,
      99,    44,    86,  -133,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    75,    96,    28,
    -133,    69,   109,  -133,  -133,  -133,    69,   101,  -133,   102,
     100,  -133,  -133,  -133,  -133,    32,    32,   -12,   -12,   -12,
     -12,    -5,    -5,    50,    80,  -133,   103,    65,    91,   106,
     107,   113,   114,  -133,  -133,   108,    28,  -133,   115,   116,
    -133,    84,  -133,   117,    99,  -133,  -133,    75,  -133,   119,
      99,    99,  -133,  -133,  -133,  -133,  -133,    99,  -133,    99,
    -133,   102,  -133,  -133,   111,   118,   121,   122,  -133,    72,
      72,  -133,   117,   138,  -133,  -133,    72,  -133
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     5,     7,     6,    14,    10,
       0,     1,     3,     4,     0,     0,     0,    12,     0,     0,
       0,    41,    48,     0,    53,    54,    55,    11,    15,    46,
      49,    47,    59,     0,    63,    66,    71,    74,    76,    40,
       0,     0,     0,     0,    22,    14,    10,     8,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    23,    27,
      16,     0,     0,    20,     9,    17,     0,     0,    50,    58,
       0,    45,    60,    61,    62,    64,    65,    69,    70,    67,
      68,    72,    73,    75,    77,    13,     0,     0,     0,     0,
       0,     0,     0,    28,    32,     0,    27,    29,     0,    46,
      18,    22,    19,    44,     0,    56,    51,    14,    38,     0,
       0,     0,    36,    37,    25,    26,    31,     0,    21,     0,
      42,    58,    24,    39,     0,     0,     0,     0,    57,     0,
       0,    30,    44,    33,    35,    43,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,    12,  -133,    97,   127,   -65,  -133,   143,
     128,    38,    79,   -37,    46,  -133,  -132,   -14,   -68,     8,
    -133,  -133,   -27,  -133,  -133,    22,    19,   -38,    17,    89,
      90,  -133
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,   103,     6,    19,     9,    17,    27,     7,
      43,    73,    44,   104,   105,   106,   107,   108,    29,   130,
      30,    31,    32,    33,    80,   115,    34,    35,    36,    37,
      38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,   109,    95,    59,    60,    70,    53,   143,   144,    52,
       8,    75,     5,    50,   147,    51,    12,    57,    58,    41,
      41,    87,    88,    89,    90,     1,     2,    82,    83,    84,
      61,    62,    18,    97,   110,    98,    77,    79,   109,   112,
      42,    48,    99,   100,   101,   102,    21,    22,    14,    15,
      20,    16,   132,    23,    10,    69,    11,    24,    25,    26,
      63,    64,    21,    22,    54,    55,    56,    14,    15,    23,
      78,   109,   109,    24,    25,    26,    85,    86,   109,    98,
      91,    92,    40,    45,   119,    67,    99,   100,   101,   102,
      21,    22,    65,    47,    66,    68,    69,    23,    15,    69,
     131,    24,    25,    26,    71,    72,   134,   135,    76,    21,
      22,   118,    81,   136,    41,   137,    23,    21,    22,    96,
      24,    25,    26,   114,    23,   113,   116,   117,    24,    25,
      26,   120,   121,   122,   123,   126,   124,   139,   127,   133,
     129,   141,   146,    74,   140,    46,   142,    13,    49,   128,
     145,   111,   125,   138,    93,     0,    94
};

static const yytype_int16 yycheck[] =
{
      14,    69,    67,     8,     9,    42,    33,   139,   140,    23,
      18,    48,     0,    23,   146,    25,     4,    29,    30,     5,
       5,    59,    60,    61,    62,     5,     6,    54,    55,    56,
      35,    36,    21,     5,    71,     7,    50,    51,   106,    76,
      26,    26,    14,    15,    16,    17,    18,    19,    22,    23,
      25,    25,   117,    25,    18,    27,     0,    29,    30,    31,
      10,    11,    18,    19,    32,    33,    34,    22,    23,    25,
      26,   139,   140,    29,    30,    31,    57,    58,   146,     7,
      63,    64,    19,    18,    98,    24,    14,    15,    16,    17,
      18,    19,    12,    20,    13,    18,    27,    25,    23,    27,
     114,    29,    30,    31,    26,    21,   120,   121,    26,    18,
      19,    20,    26,   127,     5,   129,    25,    18,    19,    23,
      29,    30,    31,    21,    25,    24,    26,    24,    29,    30,
      31,    25,    25,    20,    20,    20,    28,    26,    22,    20,
      23,    20,     4,    46,    26,    18,    24,     4,    20,   111,
     142,    72,   106,   131,    65,    -1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    38,    39,    40,    41,    46,    18,    43,
      18,     0,    40,    46,    22,    23,    25,    44,    21,    42,
      25,    18,    19,    25,    29,    30,    31,    45,    54,    55,
      57,    58,    59,    60,    63,    64,    65,    66,    67,    68,
      19,     5,    26,    47,    49,    18,    43,    20,    26,    47,
      23,    25,    54,    59,    32,    33,    34,    29,    30,     8,
       9,    35,    36,    10,    11,    12,    13,    24,    18,    27,
      50,    26,    21,    48,    42,    50,    26,    54,    26,    54,
      61,    26,    59,    59,    59,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    67,    44,    23,     5,     7,    14,
      15,    16,    17,    40,    50,    51,    52,    53,    54,    55,
      50,    49,    50,    24,    21,    62,    26,    24,    20,    54,
      25,    25,    20,    20,    28,    51,    20,    22,    48,    23,
      56,    54,    44,    20,    54,    54,    54,    54,    62,    26,
      26,    20,    24,    53,    53,    56,     4,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    40,    41,    42,
      42,    43,    43,    44,    44,    45,    46,    46,    46,    46,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    58,    59,
      59,    59,    59,    60,    60,    60,    61,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      65,    66,    66,    66,    67,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     4,     3,
       0,     3,     2,     4,     0,     1,     5,     5,     6,     6,
       2,     3,     0,     2,     5,     3,     2,     0,     1,     1,
       4,     2,     1,     5,     7,     5,     2,     2,     2,     3,
       1,     1,     5,     4,     0,     3,     1,     1,     1,     1,
       3,     4,     2,     1,     1,     1,     2,     3,     0,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3
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
#line 1241 "parser.cpp"
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
#line 1258 "parser.cpp"
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
#line 1275 "parser.cpp"
    break;

  case 5: /* GlobalDef: Decl  */
#line 65 "parser.y"
         {
    auto comp_unit = new CompUnit();
    comp_unit->decls.emplace_back((Decl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = comp_unit;
}
#line 1285 "parser.cpp"
    break;

  case 6: /* GlobalDef: FuncDef  */
#line 69 "parser.y"
            {
    auto comp_unit = new CompUnit();
    comp_unit->funcdefs.emplace_back((FuncDef*) (yyvsp[0].ast_val));
    (yyval.ast_val) = comp_unit;
}
#line 1295 "parser.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 81 "parser.y"
               {
    auto decl = new Decl();
    decl->vardecl = unique_ptr<VarDecl>((VarDecl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = decl;
}
#line 1305 "parser.cpp"
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
#line 1320 "parser.cpp"
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
#line 1334 "parser.cpp"
    break;

  case 10: /* VarDefList: %empty  */
#line 106 "parser.y"
           {
    auto var_def_list = new VarDecl();
    (yyval.ast_val) = var_def_list;
}
#line 1343 "parser.cpp"
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
#line 1355 "parser.cpp"
    break;

  case 12: /* VarDef: IDENT IntConstList  */
#line 117 "parser.y"
                       {
    auto var_def = new VarDef();
    var_def->tag = VarDef::ARRAY;
    var_def->ident = *unique_ptr<string>((yyvsp[-1].str_val));
    var_def->int_consts = unique_ptr<IntConstList>((IntConstList*) (yyvsp[0].ast_val));
    (yyval.ast_val) = var_def;
}
#line 1367 "parser.cpp"
    break;

  case 13: /* IntConstList: '[' INT_CONST ']' IntConstList  */
#line 126 "parser.y"
                                              {
    auto int_const_list = new IntConstList();
    auto int_const_list_it = unique_ptr<IntConstList>((IntConstList*) (yyvsp[0].ast_val));
    int_const_list->list.emplace_back((int) (yyvsp[-2].int_val));
    for(int i = 0; i < int_const_list_it->list.size(); ++i){
        int_const_list->list.emplace_back(int_const_list_it->list[i]);
    }
    (yyval.ast_val) = int_const_list;
}
#line 1381 "parser.cpp"
    break;

  case 14: /* IntConstList: %empty  */
#line 134 "parser.y"
           {
    auto int_const_list = new IntConstList();
    (yyval.ast_val) = int_const_list;
}
#line 1390 "parser.cpp"
    break;

  case 15: /* InitVal: Exp  */
#line 139 "parser.y"
              {
    auto init_val = new InitVal();
    init_val->exp = unique_ptr<Exp>((Exp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = init_val;
}
#line 1400 "parser.cpp"
    break;

  case 16: /* FuncDef: INT IDENT '(' ')' Block  */
#line 145 "parser.y"
                                  {
    auto func_def = new FuncDef();
    func_def->functype = (string)"int";
    func_def->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1412 "parser.cpp"
    break;

  case 17: /* FuncDef: VOID IDENT '(' ')' Block  */
#line 151 "parser.y"
                             {
    auto func_def = new FuncDef();
    func_def->functype = (string)"void";
    func_def->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1424 "parser.cpp"
    break;

  case 18: /* FuncDef: INT IDENT '(' FuncFParams ')' Block  */
#line 157 "parser.y"
                                        {
    auto func_def = new FuncDef();
    func_def->functype = (string)"int";
    func_def->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    func_def->funcfparams = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[-2].ast_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1437 "parser.cpp"
    break;

  case 19: /* FuncDef: VOID IDENT '(' FuncFParams ')' Block  */
#line 164 "parser.y"
                                         {
    auto func_def = new FuncDef();
    func_def->functype = (string)"void";
    func_def->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    func_def->funcfparams = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[-2].ast_val));
    func_def->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_def;
}
#line 1450 "parser.cpp"
    break;

  case 20: /* FuncFParams: FuncFParam FuncFParamList  */
#line 183 "parser.y"
                                        {
    auto func_f_params = new FuncFParams();
    auto func_f_param_list = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[0].ast_val));
    func_f_params->funcfparams.emplace_back((FuncFParam*) (yyvsp[-1].ast_val));
    for(auto &it : func_f_param_list->funcfparams){
        func_f_params->funcfparams.emplace_back(it.release());
    }
    (yyval.ast_val) = func_f_params;
}
#line 1464 "parser.cpp"
    break;

  case 21: /* FuncFParamList: ',' FuncFParam FuncFParamList  */
#line 193 "parser.y"
                                               {
    auto func_f_param_list = new FuncFParams();
    auto func_f_param_list_it = unique_ptr<FuncFParams>((FuncFParams*) (yyvsp[0].ast_val));
    func_f_param_list->funcfparams.emplace_back((FuncFParam*) (yyvsp[-1].ast_val));
    for(auto &it : func_f_param_list_it->funcfparams){
        func_f_param_list->funcfparams.emplace_back(it.release());
    }
    (yyval.ast_val) = func_f_param_list;
}
#line 1478 "parser.cpp"
    break;

  case 22: /* FuncFParamList: %empty  */
#line 201 "parser.y"
           {
    auto func_f_param_list = new FuncFParams();
    (yyval.ast_val) = func_f_param_list;
}
#line 1487 "parser.cpp"
    break;

  case 23: /* FuncFParam: INT IDENT  */
#line 206 "parser.y"
                       {
    auto func_f_param = new FuncFParam();
    func_f_param->tag = FuncFParam::VARIABLE;
    func_f_param->btype = (string)"int";
    func_f_param->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = func_f_param;
}
#line 1499 "parser.cpp"
    break;

  case 24: /* FuncFParam: INT IDENT '[' ']' IntConstList  */
#line 212 "parser.y"
                                   {
    auto func_f_param = new FuncFParam();
    func_f_param->tag = FuncFParam::ARRAY;
    func_f_param->btype = (string)"int";
    func_f_param->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    func_f_param->int_consts = unique_ptr<IntConstList>((IntConstList*) (yyvsp[0].ast_val));
    (yyval.ast_val) = func_f_param;    
}
#line 1512 "parser.cpp"
    break;

  case 25: /* Block: '{' BlockItemList '}'  */
#line 221 "parser.y"
                              {
    auto block = new Block();
    auto block_item_list = unique_ptr<Block>((Block*) (yyvsp[-1].ast_val));
    for(auto &it : block_item_list->blockitems){
        block->blockitems.emplace_back(it.release());
    }    
    (yyval.ast_val) = block;
}
#line 1525 "parser.cpp"
    break;

  case 26: /* BlockItemList: BlockItem BlockItemList  */
#line 230 "parser.y"
                                        {
    auto block_item_list = new Block();
    auto block_item_list_it = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    block_item_list->blockitems.emplace_back((BlockItem*) (yyvsp[-1].ast_val));
    for(auto &it : block_item_list_it->blockitems){
        block_item_list->blockitems.emplace_back(it.release());
    }
    (yyval.ast_val) = block_item_list;
}
#line 1539 "parser.cpp"
    break;

  case 27: /* BlockItemList: %empty  */
#line 238 "parser.y"
           {
    auto block_item_list = new Block();
    (yyval.ast_val) = block_item_list;
}
#line 1548 "parser.cpp"
    break;

  case 28: /* BlockItem: Decl  */
#line 243 "parser.y"
                 {
    auto block_item = new BlockItem();
    block_item->tag = BlockItem::DECL;
    block_item->decl = unique_ptr<Decl>((Decl*) (yyvsp[0].ast_val));
    (yyval.ast_val) = block_item; 
}
#line 1559 "parser.cpp"
    break;

  case 29: /* BlockItem: Stmt  */
#line 248 "parser.y"
         {
    auto block_item = new BlockItem();
    block_item->tag = BlockItem::STMT;
    block_item->stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));
    (yyval.ast_val) = block_item; 
}
#line 1570 "parser.cpp"
    break;

  case 30: /* Stmt: LVal '=' Exp ';'  */
#line 255 "parser.y"
                       {
    auto stmt = new Stmt();
    stmt->tag = Stmt::ASSIGN;
    stmt->lval = unique_ptr<LVal>((LVal*) (yyvsp[-3].ast_val));
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1582 "parser.cpp"
    break;

  case 31: /* Stmt: Exp ';'  */
#line 261 "parser.y"
            {
    auto stmt = new Stmt();
    stmt->tag = Stmt::EXP;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1593 "parser.cpp"
    break;

  case 32: /* Stmt: Block  */
#line 266 "parser.y"
          {
    auto stmt = new Stmt();
    stmt->tag = Stmt::BLOCK;
    stmt->block = unique_ptr<Block>((Block*) (yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1604 "parser.cpp"
    break;

  case 33: /* Stmt: IF '(' Exp ')' Stmt  */
#line 271 "parser.y"
                                              {
    auto stmt = new Stmt();
    stmt->tag = Stmt::IF;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-2].ast_val));
    stmt->if_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1616 "parser.cpp"
    break;

  case 34: /* Stmt: IF '(' Exp ')' Stmt ELSE Stmt  */
#line 277 "parser.y"
                                  {
    auto stmt = new Stmt();
    stmt->tag = Stmt::IF;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-4].ast_val));
    stmt->if_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[-2].ast_val));
    stmt->else_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));    
    (yyval.ast_val) = stmt;    
}
#line 1629 "parser.cpp"
    break;

  case 35: /* Stmt: WHILE '(' Exp ')' Stmt  */
#line 284 "parser.y"
                           {
    auto stmt = new Stmt();
    stmt->tag = Stmt::WHILE;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-2].ast_val));
    stmt->while_stmt = unique_ptr<Stmt>((Stmt*) (yyvsp[0].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1641 "parser.cpp"
    break;

  case 36: /* Stmt: BREAK ';'  */
#line 290 "parser.y"
              {
    auto stmt = new Stmt();
    stmt->tag = Stmt::BREAK;
    (yyval.ast_val) = stmt;
}
#line 1651 "parser.cpp"
    break;

  case 37: /* Stmt: CONTINUE ';'  */
#line 294 "parser.y"
                 {
    auto stmt = new Stmt();
    stmt->tag = Stmt::CONTINUE;
    (yyval.ast_val) = stmt;
}
#line 1661 "parser.cpp"
    break;

  case 38: /* Stmt: RETURN ';'  */
#line 298 "parser.y"
               {
    auto stmt = new Stmt();
    stmt->tag = Stmt::RETURN;
    (yyval.ast_val) = stmt;
}
#line 1671 "parser.cpp"
    break;

  case 39: /* Stmt: RETURN Exp ';'  */
#line 302 "parser.y"
                   {
    auto stmt = new Stmt();
    stmt->tag = Stmt::RETURN;
    stmt->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = stmt;
}
#line 1682 "parser.cpp"
    break;

  case 40: /* Exp: LOrExp  */
#line 309 "parser.y"
             {
    auto exp = new Exp();
    exp->lorexp = unique_ptr<LOrExp>((LOrExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = exp;
}
#line 1692 "parser.cpp"
    break;

  case 41: /* LVal: IDENT  */
#line 315 "parser.y"
             {
    auto lval = new LVal();
    lval->tag = LVal::VARIABLE;
    lval->ident = *unique_ptr<string>((yyvsp[0].str_val));
    (yyval.ast_val) = lval;
}
#line 1703 "parser.cpp"
    break;

  case 42: /* LVal: IDENT '[' Exp ']' ExpList  */
#line 320 "parser.y"
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
#line 1719 "parser.cpp"
    break;

  case 43: /* ExpList: '[' Exp ']' ExpList  */
#line 333 "parser.y"
                              {
    auto exp_list = new LVal();
    auto exp_list_it = unique_ptr<LVal>((LVal*) (yyvsp[0].ast_val));
    exp_list->exps.emplace_back((Exp*) (yyvsp[-2].ast_val));
    for(auto &it: exp_list_it->exps){
        exp_list->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = exp_list;
}
#line 1733 "parser.cpp"
    break;

  case 44: /* ExpList: %empty  */
#line 341 "parser.y"
           {
    auto exp_list = new LVal();
    (yyval.ast_val) = exp_list;
}
#line 1742 "parser.cpp"
    break;

  case 45: /* PrimaryExp: '(' Exp ')'  */
#line 346 "parser.y"
                        {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::EXP;
    primary_exp->exp = unique_ptr<Exp>((Exp*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = primary_exp;
}
#line 1753 "parser.cpp"
    break;

  case 46: /* PrimaryExp: LVal  */
#line 351 "parser.y"
         {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::LVAL;
    primary_exp->lval = unique_ptr<LVal>((LVal*) (yyvsp[0].ast_val));
    (yyval.ast_val) = primary_exp;
}
#line 1764 "parser.cpp"
    break;

  case 47: /* PrimaryExp: Number  */
#line 356 "parser.y"
           {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::NUMBER;
    primary_exp->number = unique_ptr<Number>((Number*) (yyvsp[0].ast_val));
    (yyval.ast_val) = primary_exp;
}
#line 1775 "parser.cpp"
    break;

  case 48: /* Number: INT_CONST  */
#line 363 "parser.y"
                   {
    auto number = new Number();
    number->num = (int) (yyvsp[0].int_val);
    (yyval.ast_val) = number;
}
#line 1785 "parser.cpp"
    break;

  case 49: /* UnaryExp: PrimaryExp  */
#line 369 "parser.y"
                      {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::PRIMARY_EXP;
    unary_exp->primaryexp = unique_ptr<PrimaryExp>((PrimaryExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = unary_exp;
}
#line 1796 "parser.cpp"
    break;

  case 50: /* UnaryExp: IDENT '(' ')'  */
#line 374 "parser.y"
                  {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::FUNC;
    unary_exp->ident = *unique_ptr<string>((yyvsp[-2].str_val));
    (yyval.ast_val) = unary_exp;
}
#line 1807 "parser.cpp"
    break;

  case 51: /* UnaryExp: IDENT '(' FuncRParams ')'  */
#line 379 "parser.y"
                              {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::FUNC;
    unary_exp->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    unary_exp->funcrparams = unique_ptr<FuncRParams>((FuncRParams*) (yyvsp[-1].ast_val));
    (yyval.ast_val) = unary_exp;
}
#line 1819 "parser.cpp"
    break;

  case 52: /* UnaryExp: UnaryOp UnaryExp  */
#line 385 "parser.y"
                     {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::OP_EXP;
    unary_exp->unaryop = unique_ptr<UnaryOp>((UnaryOp*) (yyvsp[-1].ast_val));
    unary_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = unary_exp;
}
#line 1831 "parser.cpp"
    break;

  case 53: /* UnaryOp: '+'  */
#line 393 "parser.y"
              {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '+';
    (yyval.ast_val) = unary_op;
}
#line 1841 "parser.cpp"
    break;

  case 54: /* UnaryOp: '-'  */
#line 397 "parser.y"
        {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '-';
    (yyval.ast_val) = unary_op;
}
#line 1851 "parser.cpp"
    break;

  case 55: /* UnaryOp: '!'  */
#line 401 "parser.y"
        {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '!';
    (yyval.ast_val) = unary_op;
}
#line 1861 "parser.cpp"
    break;

  case 56: /* FuncRParams: Exp ExpIter  */
#line 407 "parser.y"
                         {
    auto func_r_params = new FuncRParams();
    auto exp_iter = unique_ptr<FuncRParams>((FuncRParams*) (yyvsp[0].ast_val));
    func_r_params->exps.emplace_back((Exp*) (yyvsp[-1].ast_val));
    for(auto &it : exp_iter->exps){
        func_r_params->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = func_r_params;
}
#line 1875 "parser.cpp"
    break;

  case 57: /* ExpIter: ',' Exp ExpIter  */
#line 418 "parser.y"
                         {
    auto exp_iter = new FuncRParams();
    auto exp_iter_it = unique_ptr<FuncRParams>((FuncRParams*) (yyvsp[0].ast_val));
    exp_iter->exps.emplace_back((Exp*) (yyvsp[-1].ast_val));
    for(auto &it : exp_iter_it->exps){
        exp_iter->exps.emplace_back(it.release());
    }
    (yyval.ast_val) = exp_iter;
}
#line 1889 "parser.cpp"
    break;

  case 58: /* ExpIter: %empty  */
#line 426 "parser.y"
           {
    auto exp_iter = new FuncRParams();
    (yyval.ast_val) = exp_iter;
}
#line 1898 "parser.cpp"
    break;

  case 59: /* MulExp: UnaryExp  */
#line 431 "parser.y"
                  {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = mul_exp;
}
#line 1909 "parser.cpp"
    break;

  case 60: /* MulExp: MulExp '*' UnaryExp  */
#line 436 "parser.y"
                        {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
        mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[-2].ast_val));
    mul_exp->op = '*';
    (yyval.ast_val) = mul_exp;
}
#line 1922 "parser.cpp"
    break;

  case 61: /* MulExp: MulExp '/' UnaryExp  */
#line 443 "parser.y"
                        {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
        mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[-2].ast_val));
    mul_exp->op = '/';
    (yyval.ast_val) = mul_exp;
}
#line 1935 "parser.cpp"
    break;

  case 62: /* MulExp: MulExp '%' UnaryExp  */
#line 450 "parser.y"
                        {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
        mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) (yyvsp[0].ast_val));
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[-2].ast_val));
    mul_exp->op = '%';
    (yyval.ast_val) = mul_exp;
}
#line 1948 "parser.cpp"
    break;

  case 63: /* AddExp: MulExp  */
#line 459 "parser.y"
                {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::MULEXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = add_exp;
}
#line 1959 "parser.cpp"
    break;

  case 64: /* AddExp: AddExp '+' MulExp  */
#line 464 "parser.y"
                      {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::ADD_MUL_EXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[0].ast_val));
    add_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[-2].ast_val));
    add_exp->op = '+';
    (yyval.ast_val) = add_exp;
}
#line 1972 "parser.cpp"
    break;

  case 65: /* AddExp: AddExp '-' MulExp  */
#line 471 "parser.y"
                      {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::ADD_MUL_EXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) (yyvsp[0].ast_val));
    add_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[-2].ast_val));
    add_exp->op = '-';
    (yyval.ast_val) = add_exp;
}
#line 1985 "parser.cpp"
    break;

  case 66: /* RelExp: AddExp  */
#line 480 "parser.y"
                {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::ADDEXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = rel_exp;
}
#line 1996 "parser.cpp"
    break;

  case 67: /* RelExp: RelExp '<' AddExp  */
#line 485 "parser.y"
                      {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '<';
    rel_exp->op[1] = 0;
    (yyval.ast_val) = rel_exp;
}
#line 2010 "parser.cpp"
    break;

  case 68: /* RelExp: RelExp '>' AddExp  */
#line 493 "parser.y"
                      {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '>';
    rel_exp->op[1] = 0;
    (yyval.ast_val) = rel_exp;
}
#line 2024 "parser.cpp"
    break;

  case 69: /* RelExp: RelExp LESS_EQ AddExp  */
#line 501 "parser.y"
                          {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '<';
    rel_exp->op[1] = '=';
    (yyval.ast_val) = rel_exp;
}
#line 2038 "parser.cpp"
    break;

  case 70: /* RelExp: RelExp GREAT_EQ AddExp  */
#line 509 "parser.y"
                           {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) (yyvsp[0].ast_val));
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    rel_exp->op[0] = '>';
    rel_exp->op[1] = '=';
    (yyval.ast_val) = rel_exp;
}
#line 2052 "parser.cpp"
    break;

  case 71: /* EqExp: RelExp  */
#line 519 "parser.y"
               {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::RELEXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = eq_exp;
}
#line 2063 "parser.cpp"
    break;

  case 72: /* EqExp: EqExp EQUAL RelExp  */
#line 524 "parser.y"
                      {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::EQ_REL_EXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    eq_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[0].ast_val));
    eq_exp->op[0] = '=';
    eq_exp->op[1] = '=';
    (yyval.ast_val) = eq_exp;
}
#line 2077 "parser.cpp"
    break;

  case 73: /* EqExp: EqExp NOT_EQUAL RelExp  */
#line 532 "parser.y"
                          {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::EQ_REL_EXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) (yyvsp[-2].ast_val));
    eq_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[0].ast_val));
    eq_exp->op[0] = '!';
    eq_exp->op[1] = '=';
    (yyval.ast_val) = eq_exp;
}
#line 2091 "parser.cpp"
    break;

  case 74: /* LAndExp: EqExp  */
#line 542 "parser.y"
                {
    auto l_and_exp = new LAndExp();
    l_and_exp->tag = LAndExp::EQEXP;
    l_and_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = l_and_exp;
}
#line 2102 "parser.cpp"
    break;

  case 75: /* LAndExp: LAndExp AND EqExp  */
#line 547 "parser.y"
                      {
    auto l_and_exp = new LAndExp();
    l_and_exp->tag = LAndExp::LAND_EQ_EXP;
    l_and_exp->eqexp = unique_ptr<EqExp>((EqExp*) (yyvsp[0].ast_val));
    l_and_exp->landexp = unique_ptr<LAndExp>((LAndExp*) (yyvsp[-2].ast_val));
    (yyval.ast_val) = l_and_exp;
}
#line 2114 "parser.cpp"
    break;

  case 76: /* LOrExp: LAndExp  */
#line 555 "parser.y"
                 {
    auto l_or_exp = new LOrExp();
    l_or_exp->tag = LOrExp::LANDEXP;
    l_or_exp->landexp = unique_ptr<LAndExp>((LAndExp*) (yyvsp[0].ast_val));
    (yyval.ast_val) = l_or_exp;
}
#line 2125 "parser.cpp"
    break;

  case 77: /* LOrExp: LOrExp OR LAndExp  */
#line 560 "parser.y"
                      {
    auto l_or_exp = new LOrExp();
    l_or_exp->tag = LOrExp::LOR_LAND_EXP;
    l_or_exp->landexp = unique_ptr<LAndExp>((LAndExp*) (yyvsp[0].ast_val));
    l_or_exp->lorexp = unique_ptr<LOrExp>((LOrExp*) (yyvsp[-2].ast_val));
    (yyval.ast_val) = l_or_exp;
}
#line 2137 "parser.cpp"
    break;


#line 2141 "parser.cpp"

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

#line 568 "parser.y"


void yyerror(unique_ptr<AST> &ast, const char *s) {
    cerr << "error: " << s << endl;
}


