/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ass3_15CS30006.y" /* yacc.c:339  */

	#include <stdio.h>
	#define YYSTYPE double
	extern int yylex(void);

#line 72 "ass3_15CS30006.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ass3_15CS30006.tab.h".  */
#ifndef YY_YY_ASS3_15CS30006_TAB_H_INCLUDED
# define YY_YY_ASS3_15CS30006_TAB_H_INCLUDED
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
    UNSIGNED = 258,
    BREAK = 259,
    RETURN = 260,
    VOID = 261,
    CASE = 262,
    FLOAT = 263,
    SHORT = 264,
    CHAR = 265,
    FOR = 266,
    SIGNED = 267,
    WHILE = 268,
    GOTO = 269,
    BOOL = 270,
    CONTINUE = 271,
    IF = 272,
    DEFAULT = 273,
    DO = 274,
    INT = 275,
    SWITCH = 276,
    DOUBLE = 277,
    LONG = 278,
    MATRIX = 279,
    OPENBRCSQ = 280,
    CLOSEBRCSQ = 281,
    OPENBRCCIR = 282,
    CLOSEBRCCIR = 283,
    OPENBRCCUR = 284,
    CLOSEBRCCUR = 285,
    DOT = 286,
    POINTSTO = 287,
    PLUSPLUS = 288,
    MINUSMINUS = 289,
    AND = 290,
    STAR = 291,
    PLUS = 292,
    MINUS = 293,
    NEGATE = 294,
    NOT = 295,
    DIVIDE = 296,
    PERCENT = 297,
    LESSLESS = 298,
    GREATGREAT = 299,
    LESS = 300,
    GREAT = 301,
    LESSEQUAL = 302,
    GREATEQUAL = 303,
    EQUALEQUAL = 304,
    NOTEQUAL = 305,
    XOR = 306,
    OR = 307,
    ANDAND = 308,
    OROR = 309,
    QUESTION = 310,
    EQUALS = 311,
    MULTIPLYEQUALS = 312,
    DIVIDEEQUALS = 313,
    MODEQUALS = 314,
    PLUSEQUALS = 315,
    MINUSEQUALS = 316,
    LESSLESSEQUALS = 317,
    GREATGREATEQUALS = 318,
    ANDEQUALS = 319,
    XOREQUALS = 320,
    OREQUALS = 321,
    COMMA = 322,
    HASH = 323,
    DOTINVERTEDCOMMA = 324,
    COLON = 325,
    SEMICOLON = 326,
    IDENTIFIER = 327,
    CONSTANT = 328,
    STRINGLITERAL = 329,
    ELSE = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS3_15CS30006_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "ass3_15CS30006.tab.c" /* yacc.c:358  */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  271

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    16,    16,    17,    18,    19,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    33,    34,    38,    39,    40,
      41,    44,    45,    46,    47,    50,    53,    54,    55,    56,
      60,    61,    62,    66,    67,    68,    72,    73,    74,    75,
      76,    80,    81,    82,    86,    87,    90,    91,    95,    96,
      99,   100,   103,   104,   107,   108,   111,   112,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   129,
     130,   133,   134,   137,   144,   145,   148,   149,   152,   153,
     156,   157,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   174,   175,   178,   179,   180,   181,   182,
     183,   184,   188,   189,   194,   197,   198,   201,   202,   205,
     206,   209,   210,   213,   214,   217,   218,   219,   220,   223,
     226,   227,   230,   231,   239,   240,   241,   242,   243,   244,
     247,   248,   249,   252,   253,   256,   257,   260,   261,   264,
     265,   268,   269,   270,   273,   274,   275,   276,   279,   280,
     281,   282,   283,   287,   288,   291,   292,   295,   296,   299,
     300
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNSIGNED", "BREAK", "RETURN", "VOID",
  "CASE", "FLOAT", "SHORT", "CHAR", "FOR", "SIGNED", "WHILE", "GOTO",
  "BOOL", "CONTINUE", "IF", "DEFAULT", "DO", "INT", "SWITCH", "DOUBLE",
  "LONG", "MATRIX", "OPENBRCSQ", "CLOSEBRCSQ", "OPENBRCCIR", "CLOSEBRCCIR",
  "OPENBRCCUR", "CLOSEBRCCUR", "DOT", "POINTSTO", "PLUSPLUS", "MINUSMINUS",
  "AND", "STAR", "PLUS", "MINUS", "NEGATE", "NOT", "DIVIDE", "PERCENT",
  "LESSLESS", "GREATGREAT", "LESS", "GREAT", "LESSEQUAL", "GREATEQUAL",
  "EQUALEQUAL", "NOTEQUAL", "XOR", "OR", "ANDAND", "OROR", "QUESTION",
  "EQUALS", "MULTIPLYEQUALS", "DIVIDEEQUALS", "MODEQUALS", "PLUSEQUALS",
  "MINUSEQUALS", "LESSLESSEQUALS", "GREATGREATEQUALS", "ANDEQUALS",
  "XOREQUALS", "OREQUALS", "COMMA", "HASH", "DOTINVERTEDCOMMA", "COLON",
  "SEMICOLON", "IDENTIFIER", "CONSTANT", "STRINGLITERAL", "\"then\"",
  "ELSE", "$accept", "primary_expr", "postfix_expr", "argument_expr_list",
  "unary_expr", "unary_operator", "cast_expr", "multiplicative_expr",
  "additive_expr", "shift_expr", "relational_expr", "equality_expr",
  "AND_expr", "exclusiveOR_expr", "inclusiveOR_expr", "logicalAND_expr",
  "logicalOR_expr", "conditional_expr", "assignment_expr",
  "assignment_operator", "expression", "expression_opt", "constant_expr",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "type_specifier", "declarator", "direct_declarator",
  "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "initializer",
  "initializer_row_list", "initializer_row", "designation",
  "designator_list", "designator", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

#define YYPACT_NINF -180

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-180)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     553,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,   -22,   553,   531,  -180,  -180,   -18,   -15,
    -180,  -180,    30,  -180,   116,    88,   -10,  -180,  -180,  -180,
       3,  -180,   -18,  -180,   216,   428,  -180,   -22,  -180,   252,
     399,    24,    88,  -180,  -180,   -19,   -16,   414,   456,    46,
      57,    -8,    34,    62,    21,   372,    68,   456,  -180,   456,
     456,  -180,  -180,  -180,  -180,  -180,    44,  -180,  -180,  -180,
     142,   460,   456,  -180,    52,    80,    89,    64,    18,    85,
      72,    75,    77,    87,  -180,  -180,    31,  -180,  -180,  -180,
    -180,   288,  -180,  -180,  -180,  -180,  -180,   386,  -180,  -180,
    -180,  -180,  -180,  -180,   108,  -180,  -180,   -18,   115,    99,
    -180,    -9,  -180,  -180,    37,  -180,  -180,    98,   330,   456,
     100,  -180,   456,   372,   173,   456,    -4,  -180,  -180,   372,
     456,   441,   117,   120,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   456,  -180,
     456,   456,   456,   456,   456,   456,   456,   456,   456,   456,
     456,   456,   456,   456,   456,   456,   456,   456,   456,   456,
    -180,  -180,  -180,   456,   124,  -180,    -5,   130,   428,     4,
    -180,  -180,  -180,  -180,   553,  -180,   128,  -180,   372,   134,
     131,   456,    10,  -180,    12,  -180,   177,    15,  -180,  -180,
      -6,  -180,    23,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
      52,    52,    80,    80,    89,    89,    89,    89,    64,    64,
      18,    85,    72,    75,    77,    36,  -180,   179,  -180,  -180,
     386,   386,  -180,  -180,  -180,  -180,  -180,  -180,   456,   136,
     372,   372,   456,   372,  -180,  -180,   456,   456,  -180,   130,
    -180,  -180,   137,   456,  -180,   140,    25,  -180,  -180,  -180,
     456,   182,   372,   146,   213,   372,  -180,  -180,   372,  -180,
    -180
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,    82,    87,    84,    83,    90,    92,    85,    88,
      86,    89,   156,     0,    76,     0,   153,   155,     0,   102,
      74,    95,     0,    78,    80,    93,     0,    77,     1,   154,
       0,   103,     0,    75,     0,     0,   159,     0,   157,     0,
       0,     0,    94,    96,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,    21,    22,    23,    24,   139,     2,     3,     4,     6,
      17,    25,     0,    26,    30,    33,    36,    41,    44,    46,
      48,    50,    52,    54,    56,    69,     0,   137,   138,   124,
     125,     0,   135,   126,   127,   128,   129,     0,     2,   111,
      81,   160,   158,    97,     0,   100,   109,   108,     0,   104,
     105,     0,   150,   151,     0,    25,    73,     0,    72,     0,
       0,   149,     0,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,     0,    12,    13,    14,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   134,   136,     0,     0,   115,     0,   113,     0,     0,
     120,    98,   107,    99,     0,   101,     0,   152,     0,    71,
       0,    72,     0,   148,     0,   132,     0,     0,     5,   130,
       0,     8,     0,    15,    10,    11,    57,    27,    28,    29,
      31,    32,    34,    35,    37,    38,    39,    40,    42,    43,
      45,    47,    49,    51,    53,     0,    70,     0,   123,   112,
       0,     0,   116,   119,   121,   106,   110,   131,    72,     0,
       0,     0,     0,     0,     7,     9,     0,     0,   122,   114,
     117,   118,     0,    72,   144,   141,     0,   143,    16,    55,
      72,     0,     0,     0,     0,     0,   142,   145,     0,   147,
     146
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,  -180,    -3,  -180,   -65,    28,    38,    20,
      22,    79,    83,    91,    82,    90,  -180,   -44,   -32,  -180,
     -47,  -179,    86,   -11,     1,  -180,   231,  -180,    -7,   239,
     247,  -180,  -180,    84,  -180,   -13,  -180,    39,    40,  -180,
      94,   -53,  -180,     2,  -180,   186,  -180,  -180,  -180,  -180,
    -180,   255,  -180,  -180
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    69,    70,   202,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   148,
      86,   190,   117,    12,    37,    22,    23,    14,    45,    25,
      26,   108,   109,   110,   111,   175,   176,   177,   178,   179,
     180,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      15,    16,    17,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     114,    13,   124,    99,   116,    18,    24,   149,   104,    18,
     126,    30,   239,    36,    19,    27,    13,    18,    19,   185,
     244,    19,   100,    87,   198,   229,    38,     1,   101,   173,
       2,    43,     3,     4,     5,   174,     6,    35,   240,     7,
     241,   102,   107,   243,     8,   115,     9,    10,    11,    20,
      21,   245,   105,   263,    21,   112,   127,   128,   186,   252,
     233,   169,    21,   169,   120,    99,   230,   161,   162,   115,
     195,   189,   192,   118,   261,   194,   199,   169,   197,   169,
      87,   264,   169,   200,   119,   207,   208,   209,   150,   122,
     246,   123,   169,   151,   152,   125,   106,    32,   169,   203,
     182,    33,   170,   169,   169,   121,   247,   191,   187,   157,
     158,   159,   160,    40,   129,    41,   206,   153,   154,     1,
     163,   225,     2,   164,     3,     4,     5,   165,     6,   116,
     166,     7,   155,   156,   181,   237,     8,   226,     9,    10,
      11,   167,   168,   183,   189,    34,    99,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   232,   184,   130,   188,   131,
     115,   193,    35,   132,   133,   134,   135,   214,   215,   216,
     217,   210,   211,   218,   219,   107,   196,   254,   255,   204,
     257,   189,   205,   212,   213,   256,   228,   231,    99,    99,
     236,   169,   238,   259,   242,   248,   189,   253,   260,   266,
     265,   136,   269,   189,   258,   270,   262,   267,   250,     1,
      46,    47,     2,    48,     3,     4,     5,    49,     6,    50,
      51,     7,    52,    53,    54,    55,     8,    56,     9,    10,
      11,   268,   220,    57,   115,    34,    58,   221,   223,    59,
      60,    61,    62,    63,    64,     1,   222,   224,     2,   227,
       3,     4,     5,    44,     6,    42,    31,     7,   235,   249,
      29,   251,     8,   234,     9,    10,    11,   172,     0,     0,
       0,    34,     0,     0,     0,     0,     0,    65,    66,    67,
      68,     1,    46,    47,     2,    48,     3,     4,     5,    49,
       6,    50,    51,     7,    52,    53,    54,    55,     8,    56,
       9,    10,    11,     0,     0,    57,     0,    34,   171,     0,
       0,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     2,     0,     3,     4,
       5,     0,     6,     0,     0,     7,     0,     0,     0,     0,
       8,     0,     9,    10,    11,     0,     0,    57,     0,    65,
      66,    67,    68,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,    48,
       0,     0,     0,    49,     0,    50,    51,     0,    52,    53,
      54,    55,     0,    56,     0,     0,     0,     0,     0,    57,
       0,    34,    98,    67,    68,    59,    60,    61,    62,    63,
      64,   173,     0,    57,     0,    97,     0,   174,     0,    59,
      60,    61,    62,    63,    64,   103,    57,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,    64,     0,     0,
       0,    57,     0,    65,    66,    67,    68,    59,    60,    61,
      62,    63,    64,     0,     0,    57,     0,    97,    98,    67,
      68,    59,    60,    61,    62,    63,    64,     0,    57,   201,
       0,    98,    67,    68,    59,    60,    61,    62,    63,    64,
       0,     0,     0,    57,     0,   113,    98,    67,    68,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
      98,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    67,    68,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,     0,    98,    67,
      68,    28,     0,     0,     1,     0,     0,     2,     0,     3,
       4,     5,     0,     6,     0,     0,     7,     0,     0,     0,
       0,     8,     0,     9,    10,    11,     1,     0,     0,     2,
       0,     3,     4,     5,     0,     6,     0,     0,     7,     0,
       0,     0,     0,     8,     0,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
      47,     0,    55,    35,    48,    27,    13,    72,    40,    27,
      57,    18,   191,    24,    36,    14,    15,    27,    36,    28,
      26,    36,    35,    34,    28,    30,    24,     3,    39,    25,
       6,    28,     8,     9,    10,    31,    12,    56,    28,    15,
      28,    39,    41,    28,    20,    48,    22,    23,    24,    71,
      72,    28,    28,    28,    72,    71,    59,    60,    67,   238,
      56,    67,    72,    67,    72,    97,    71,    49,    50,    72,
     123,   118,   119,    27,   253,   122,   129,    67,   125,    67,
      91,   260,    67,   130,    27,   150,   151,   152,    36,    27,
      67,    70,    67,    41,    42,    27,    72,    67,    67,   131,
     107,    71,    71,    67,    67,    71,    70,   118,    71,    45,
      46,    47,    48,    25,    70,    27,   148,    37,    38,     3,
      35,   168,     6,    51,     8,     9,    10,    52,    12,   173,
      53,    15,    43,    44,    26,   188,    20,   169,    22,    23,
      24,    54,    55,    28,   191,    29,   178,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   178,    67,    25,    70,    27,
     173,    71,    56,    31,    32,    33,    34,   157,   158,   159,
     160,   153,   154,   161,   162,   184,    13,   240,   241,    72,
     243,   238,    72,   155,   156,   242,    72,    67,   230,   231,
      72,    67,    71,   247,    27,    26,   253,    71,    71,   262,
      28,    69,   265,   260,   246,   268,    76,    71,   231,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    28,   163,    27,   247,    29,    30,   164,   166,    33,
      34,    35,    36,    37,    38,     3,   165,   167,     6,   173,
       8,     9,    10,    32,    12,    26,    19,    15,   184,   230,
      15,   231,    20,   179,    22,    23,    24,    91,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,     6,    -1,     8,     9,
      10,    -1,    12,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    -1,    22,    23,    24,    -1,    -1,    27,    -1,    71,
      72,    73,    74,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    72,    73,    74,    33,    34,    35,    36,    37,
      38,    25,    -1,    27,    -1,    29,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    27,    -1,    71,    72,    73,    74,    33,    34,    35,
      36,    37,    38,    -1,    -1,    27,    -1,    29,    72,    73,
      74,    33,    34,    35,    36,    37,    38,    -1,    27,    28,
      -1,    72,    73,    74,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    27,    -1,    71,    72,    73,    74,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    72,    73,
      74,     0,    -1,    -1,     3,    -1,    -1,     6,    -1,     8,
       9,    10,    -1,    12,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,     3,    -1,    -1,     6,
      -1,     8,     9,    10,    -1,    12,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    -1,    22,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     8,     9,    10,    12,    15,    20,    22,
      23,    24,   100,   101,   104,   127,   128,   129,    27,    36,
      71,    72,   102,   103,   105,   106,   107,   101,     0,   128,
     105,   107,    67,    71,    29,    56,   100,   101,   120,   130,
      25,    27,   106,    28,   103,   105,     4,     5,     7,    11,
      13,    14,    16,    17,    18,    19,    21,    27,    30,    33,
      34,    35,    36,    37,    38,    71,    72,    73,    74,    78,
      79,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    97,   100,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    29,    72,    95,
     112,   100,   120,    26,    95,    28,    72,   101,   108,   109,
     110,   111,    71,    71,    97,    81,    94,    99,    27,    27,
      72,    71,    27,    70,   118,    27,    97,    81,    81,    70,
      25,    27,    31,    32,    33,    34,    69,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    96,    83,
      36,    41,    42,    37,    38,    43,    44,    45,    46,    47,
      48,    49,    50,    35,    51,    52,    53,    54,    55,    67,
      71,    30,   122,    25,    31,   112,   113,   114,   115,   116,
     117,    26,   105,    28,    67,    28,    67,    71,    70,    97,
      98,   100,    97,    71,    97,   118,    13,    97,    28,   118,
      97,    28,    80,    95,    72,    72,    95,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    89,    90,    91,    92,    97,    95,    99,    72,    30,
      71,    67,   112,    56,   117,   110,    72,   118,    71,    98,
      28,    28,    27,    28,    26,    28,    67,    70,    26,   114,
     112,   115,    98,    71,   118,   118,    97,   118,    95,    94,
      71,    98,    76,    28,    98,    28,   118,    71,    28,   118,
     118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    81,
      81,    82,    82,    82,    82,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   107,   107,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   114,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   125,   125,   125,   125,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     2,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     1,     2,     3,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     3,     4,     4,
       3,     4,     1,     2,     1,     1,     3,     2,     1,     1,
       3,     1,     3,     1,     3,     1,     2,     3,     3,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     5,     7,     5,     5,     7,     9,     8,     3,     2,
       2,     2,     3,     1,     2,     1,     1,     3,     4,     1,
       2
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
#line 16 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("primary_expr -> IDENTIFIER\n");}
#line 1558 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 17 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("primary_expr -> CONSTANT\n");}
#line 1564 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 18 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("primary_expr -> STRINGLITERAL\n");}
#line 1570 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 19 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("primary_expr -> ( expression )\n");}
#line 1576 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 22 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> primary_expr\n");}
#line 1582 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 23 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr [ expression ]\n");}
#line 1588 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 24 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr ()\n");}
#line 1594 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 25 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr ( argument_expr_list )\n");}
#line 1600 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 26 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr .IDENTIFIER\n");}
#line 1606 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 27 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr ->IDENTIFIER\n");}
#line 1612 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 28 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr ++\n");}
#line 1618 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 29 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr --\n");}
#line 1624 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 30 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("postfix_expr -> postfix_expr .'\n");}
#line 1630 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 33 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("argument_expr_list -> assignment_expr\n");}
#line 1636 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 34 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("argument_expr_list -> argument_expr_list , assignment_expr\n");}
#line 1642 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 38 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_expr -> postfix_expr\n");}
#line 1648 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 39 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_expr -> ++ unary_expr\n");}
#line 1654 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 40 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_expr -> -- unary_expr\n");}
#line 1660 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 41 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_expr -> unary_operator cast_expr\n");}
#line 1666 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 44 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_operator -> &\n");}
#line 1672 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 45 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_operator -> *\n");}
#line 1678 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 46 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_operator -> +\n");}
#line 1684 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 47 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("unary_operator -> -\n");}
#line 1690 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 50 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("cast_expr -> unary_expr\n");}
#line 1696 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 53 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("multiplicative_expr -> cast_expr\n");}
#line 1702 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 54 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("multiplicative_expr -> multiplicative_expr * cast_expr\n");}
#line 1708 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 55 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("multiplicative_expr -> multiplicative_expr / cast_expr\n");}
#line 1714 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 56 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("multiplicative_expr -> multiplicative_expr %% cast_expr\n");}
#line 1720 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 60 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("additive_expr -> multiplicative_expr\n");}
#line 1726 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 61 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("additive_expr -> additive_expr + multiplicative_expr\n");}
#line 1732 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 62 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("additive_expr -> additive_expr - multiplicative_expr\n");}
#line 1738 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 66 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("shift_expr -> additive_expr\n");}
#line 1744 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 67 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("shift_expr -> shift_expr << additive_expr\n");}
#line 1750 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 68 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("shift_expr -> shift_expr >> additive_expr\n");}
#line 1756 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 72 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("relational_expr -> shift_expr\n");}
#line 1762 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 73 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("relational_expr -> relational_expr < shift_expr\n");}
#line 1768 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 74 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("relational_expr -> relational_expr > shift_expr\n");}
#line 1774 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 75 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("relational_expr -> relational_expr <= shift_expr\n");}
#line 1780 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 76 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("relational_expr -> relational_expr >= shift_expr\n");}
#line 1786 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 80 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("equality_expr -> relational_expr\n");}
#line 1792 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 81 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("equality_expr -> equality_expr == relational_expr\n");}
#line 1798 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 82 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("equality_expr -> equality_expr != relational_expr\n");}
#line 1804 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 86 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("AND_expr -> equality_expr\n");}
#line 1810 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 87 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("AND_expr -> AND_expr & equality_expr\n");}
#line 1816 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 90 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("exclusiveOR_expr -> AND_expr\n");}
#line 1822 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 91 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("exclusiveOR_expr -> exclusiveOR_expr ^ AND_expr \n");}
#line 1828 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 95 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("inclusiveOR_expr -> exclusiveOR_expr\n");}
#line 1834 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 96 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("inclusiveOR_expr -> inclusiveOR_expr | exclusiveOR_expr\n");}
#line 1840 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 99 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("logicalAND_expr -> inclusiveOR_expr\n");}
#line 1846 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 100 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("inclusiveOR_expr -> logicalAND_expr && inclusiveOR_expr\n");}
#line 1852 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 103 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("logicalOR_expr -> logicalAND_expr\n");}
#line 1858 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 104 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("logicalOR_expr -> logicalOR_expr || logicalAND_expr\n");}
#line 1864 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 107 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("conditional_expr -> logicalOR_expr\n");}
#line 1870 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 108 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("conditional_expr -> logicalOR_expr ? expression : conditional_expr \n");}
#line 1876 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 111 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_expr -> conditional_expr\n");}
#line 1882 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 112 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_expr -> unary_expr assignment_operator assignment_expr\n");}
#line 1888 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 116 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> =\n");}
#line 1894 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 117 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> *=\n");}
#line 1900 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 118 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> /=\n");}
#line 1906 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 119 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> %%=\n");}
#line 1912 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 120 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> +=\n");}
#line 1918 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 121 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> -=\n");}
#line 1924 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 122 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> <<=\n");}
#line 1930 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 123 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> >>=\n");}
#line 1936 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 124 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> &=\n");}
#line 1942 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 125 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> ^=\n");}
#line 1948 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 126 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("assignment_operator -> |=\n");}
#line 1954 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 129 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("expression -> assignment_expr\n");}
#line 1960 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 130 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("expression -> expression , assignment_expr\n");}
#line 1966 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 133 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("expression_opt -> expression\n");}
#line 1972 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 134 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("expression_opt -> \n");}
#line 1978 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 137 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("constant_expr -> conditional_expr\n");}
#line 1984 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 144 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declaration -> declaration_specifiers ;\n");}
#line 1990 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 145 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declaration -> declaration_specifiers init_declarator_list ;\n");}
#line 1996 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 148 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_specifier\n");}
#line 2002 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 149 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_specifier declaration_specifiers\n");}
#line 2008 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 152 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("init_declarator_list -> init_declarator\n");}
#line 2014 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 153 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("init_declarator_list -> init_declarator_list , init_declarator	\n");}
#line 2020 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 156 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("init_declarator -> declarator\n");}
#line 2026 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 157 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("init_declarator -> declarator = initializer\n");}
#line 2032 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 160 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> void\n");}
#line 2038 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 161 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> char\n");}
#line 2044 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 162 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> short\n");}
#line 2050 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 163 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> int\n");}
#line 2056 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 164 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> long\n");}
#line 2062 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 165 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> float\n");}
#line 2068 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 166 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> double\n");}
#line 2074 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 167 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> Matrix\n");}
#line 2080 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 168 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> signed\n");}
#line 2086 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 169 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> unsigned\n");}
#line 2092 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 170 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("type_specifier -> bool\n");}
#line 2098 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 174 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declarator -> direct_declarator\n");}
#line 2104 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 175 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declarator -> pointer direct_declarator\n");}
#line 2110 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 178 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> IDENTIFIER\n");}
#line 2116 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 179 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> ( declarator )\n");}
#line 2122 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 180 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> direct_declarator []\n");}
#line 2128 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 181 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> direct_declarator [ assignment_expr ]\n");}
#line 2134 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 182 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> direct_declarator ( parameter_type_list )\n");}
#line 2140 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 183 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> direct_declarator ()\n");}
#line 2146 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 184 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("direct_declarator -> direct_declarator ( identifier_list )\n");}
#line 2152 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 188 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("pointer -> *\n");}
#line 2158 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 189 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("pointer -> * pointer\n");}
#line 2164 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 194 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("parameter_type_list -> parameter_list\n");}
#line 2170 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 197 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("parameter_list -> parameter_declaration\n");}
#line 2176 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 198 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("parameter_list -> parameter_list , parameter_declaration\n");}
#line 2182 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 201 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("parameter_declaration -> declaration_specifiers declarator\n");}
#line 2188 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 202 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("parameter_declaration -> declaration_specifiers\n");}
#line 2194 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 205 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("identifier_list -> IDENTIFIER\n");}
#line 2200 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 206 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("identifier_list -> identifier_list , IDENTIFIER\n");}
#line 2206 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 209 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer -> assignment_expr\n");}
#line 2212 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 210 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer -> { initializer_row_list }\n");}
#line 2218 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 213 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer_row_list -> initializer_row\n");}
#line 2224 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 214 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer_row_list -> initializer_row_list ; initializer_row	\n");}
#line 2230 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 217 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer_row -> initializer\n");}
#line 2236 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 218 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer_row -> designation initializer 	\n");}
#line 2242 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 219 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer_row -> initializer_row , initializer\n");}
#line 2248 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 220 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("initializer_row -> initializer_row , designation\n");}
#line 2254 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 223 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("designation -> designator_list =\n");}
#line 2260 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 226 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("designator_list -> designator\n");}
#line 2266 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 227 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("designator_list -> designator_list designator\n");}
#line 2272 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 230 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("designator -> [ constant_expr ]\n");}
#line 2278 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 231 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("designator -> . IDENTIFIER\n");}
#line 2284 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 239 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("statement -> labeled_statement\n");}
#line 2290 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 240 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("statement -> compound_statement\n");}
#line 2296 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 241 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("statement -> expression_statement\n");}
#line 2302 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 242 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("statement -> selection_statement\n");}
#line 2308 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 243 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("statement -> iteration_statement\n");}
#line 2314 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 244 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("statement -> jump_statement\n");}
#line 2320 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 247 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("labeled_statement -> IDENTIFIER : statement\n");}
#line 2326 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 248 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("labeled_statement -> case constant_expr : statement\n");}
#line 2332 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 249 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("labeled_statement -> default : statement\n");}
#line 2338 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 252 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("compound_statement -> {}\n");}
#line 2344 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 253 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("compound_statement -> { block_item_list }\n");}
#line 2350 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 256 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("block_item_list -> block_item\n");}
#line 2356 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 257 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("block_item_list -> block_item_list block_item\n");}
#line 2362 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 260 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("block_item -> declaration\n");}
#line 2368 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 261 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("block_item -> statement\n");}
#line 2374 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 264 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("expression_statement -> ;\n");}
#line 2380 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 265 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("expression_statement -> expression ;\n");}
#line 2386 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 268 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("selection_statement -> if ( expression ) statement\n");}
#line 2392 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 269 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("selection_statement -> if (expression ) statement else statement\n");}
#line 2398 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 270 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("selection_statement -> switch ( expression ) statement\n");}
#line 2404 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 273 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("iteration_statement -> while ( expression ) statement\n");}
#line 2410 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 274 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("iteration_statement -> do statement while ( expression ) ;\n");}
#line 2416 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 275 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("iteration_statement -> for ( expression ; expression ; expression ) statement\n");}
#line 2422 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 276 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("iteration_statement -> for ( declaration expression ; expression ) statement\n");}
#line 2428 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 279 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("jump_statement -> goto IDENTIFIER ;\n");}
#line 2434 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 280 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("jump_statement -> continue ;\n");}
#line 2440 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 281 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("jump_statement -> break ;\n");}
#line 2446 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 282 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("jump_statement -> return ;\n");}
#line 2452 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 283 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("jump_statement -> return expression ;\n");}
#line 2458 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 287 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("translation_unit -> external_declaration\n");}
#line 2464 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 288 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("translation_unit -> translation_unit external_declaration\n");}
#line 2470 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 291 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("external_declaration -> function_definition\n");}
#line 2476 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 292 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("external_declaration -> declaration\n");}
#line 2482 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 295 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("function_definition -> declaration_specifiers declarator compound_statement");}
#line 2488 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 296 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement");}
#line 2494 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 299 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declaration_list -> declaration");}
#line 2500 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 300 "ass3_15CS30006.y" /* yacc.c:1646  */
    {printf("declaration_list -> declaration_list declaration");}
#line 2506 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
    break;


#line 2510 "ass3_15CS30006.tab.c" /* yacc.c:1646  */
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
#line 303 "ass3_15CS30006.y" /* yacc.c:1906  */




int yyerror(char *s){
  printf("Parser Error : %s\n",s);
  return -1;
}


yywrap()
{
	return 1;
}









			





