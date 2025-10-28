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
#line 1 "sintatico.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* Declaração das funções que o Bison precisará */
    int yylex(); // A função do analisador léxico (gerada pelo Flex)
    void yyerror(const char *s); // A função para reportar erros
    int contador_erros_lexicos = 0;
    extern FILE *yyin;
    extern int yylineno;
    extern char *yytext;
    extern int yydebug; 
    

#line 87 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_PROGRAM = 3,              /* TOKEN_PROGRAM  */
  YYSYMBOL_TOKEN_VAR = 4,                  /* TOKEN_VAR  */
  YYSYMBOL_TOKEN_PROCEDURE = 5,            /* TOKEN_PROCEDURE  */
  YYSYMBOL_TOKEN_FUNCTION = 6,             /* TOKEN_FUNCTION  */
  YYSYMBOL_TOKEN_BEGIN = 7,                /* TOKEN_BEGIN  */
  YYSYMBOL_TOKEN_END = 8,                  /* TOKEN_END  */
  YYSYMBOL_TOKEN_FALSE = 9,                /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_TRUE = 10,                /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_IF = 11,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_THEN = 12,                /* TOKEN_THEN  */
  YYSYMBOL_TOKEN_ELSE = 13,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 14,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 15,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_READ = 16,                /* TOKEN_READ  */
  YYSYMBOL_TOKEN_WRITE = 17,               /* TOKEN_WRITE  */
  YYSYMBOL_TOKEN_AND = 18,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 19,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 20,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_DIV = 21,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_INTEGER = 22,             /* TOKEN_INTEGER  */
  YYSYMBOL_TOKEN_BOOLEAN = 23,             /* TOKEN_BOOLEAN  */
  YYSYMBOL_TOKEN_SOMA = 24,                /* TOKEN_SOMA  */
  YYSYMBOL_TOKEN_SUBT = 25,                /* TOKEN_SUBT  */
  YYSYMBOL_TOKEN_MULT = 26,                /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_IGUAL = 27,               /* TOKEN_IGUAL  */
  YYSYMBOL_TOKEN_FECHAPAR = 28,            /* TOKEN_FECHAPAR  */
  YYSYMBOL_TOKEN_ABREPAR = 29,             /* TOKEN_ABREPAR  */
  YYSYMBOL_TOKEN_PONTOVIRG = 30,           /* TOKEN_PONTOVIRG  */
  YYSYMBOL_TOKEN_VIRG = 31,                /* TOKEN_VIRG  */
  YYSYMBOL_TOKEN_PONTO = 32,               /* TOKEN_PONTO  */
  YYSYMBOL_TOKEN_DIF = 33,                 /* TOKEN_DIF  */
  YYSYMBOL_TOKEN_MAIOR = 34,               /* TOKEN_MAIOR  */
  YYSYMBOL_TOKEN_MENOR = 35,               /* TOKEN_MENOR  */
  YYSYMBOL_TOKEN_MAIORIGUAL = 36,          /* TOKEN_MAIORIGUAL  */
  YYSYMBOL_TOKEN_MENORIGUAL = 37,          /* TOKEN_MENORIGUAL  */
  YYSYMBOL_TOKEN_ATRIB = 38,               /* TOKEN_ATRIB  */
  YYSYMBOL_TOKEN_DOISP = 39,               /* TOKEN_DOISP  */
  YYSYMBOL_ID = 40,                        /* ID  */
  YYSYMBOL_NUMERO = 41,                    /* NUMERO  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_root = 43,                      /* root  */
  YYSYMBOL_resto = 44,                     /* resto  */
  YYSYMBOL_declaracao_variaveis = 45,      /* declaracao_variaveis  */
  YYSYMBOL_lista_variaveis = 46,           /* lista_variaveis  */
  YYSYMBOL_outro_tipo_variaveis = 47,      /* outro_tipo_variaveis  */
  YYSYMBOL_tipo = 48,                      /* tipo  */
  YYSYMBOL_declaracao_subprogramas = 49,   /* declaracao_subprogramas  */
  YYSYMBOL_resto_funcao = 50,              /* resto_funcao  */
  YYSYMBOL_retorno_funcao = 51,            /* retorno_funcao  */
  YYSYMBOL_comando_begin_geral = 52,       /* comando_begin_geral  */
  YYSYMBOL_comando_begin = 53,             /* comando_begin  */
  YYSYMBOL_corpo = 54,                     /* corpo  */
  YYSYMBOL_mais_corpo = 55,                /* mais_corpo  */
  YYSYMBOL_funcao = 56,                    /* funcao  */
  YYSYMBOL_quantidade_variaveis = 57,      /* quantidade_variaveis  */
  YYSYMBOL_quantidade_itens_escrita = 58,  /* quantidade_itens_escrita  */
  YYSYMBOL_mais_itens_escrita = 59,        /* mais_itens_escrita  */
  YYSYMBOL_mais_variaveis = 60,            /* mais_variaveis  */
  YYSYMBOL_expressao = 61,                 /* expressao  */
  YYSYMBOL_termo = 62,                     /* termo  */
  YYSYMBOL_lista_parametros = 63,          /* lista_parametros  */
  YYSYMBOL_resto_parametros = 64,          /* resto_parametros  */
  YYSYMBOL_calculo = 65,                   /* calculo  */
  YYSYMBOL_seq_calculo = 66,               /* seq_calculo  */
  YYSYMBOL_operador = 67,                  /* operador  */
  YYSYMBOL_condicional = 68,               /* condicional  */
  YYSYMBOL_expressao_condicional = 69,     /* expressao_condicional  */
  YYSYMBOL_comparacao = 70,                /* comparacao  */
  YYSYMBOL_mais_comparacoes = 71,          /* mais_comparacoes  */
  YYSYMBOL_loop = 72                       /* loop  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    42,    47,    49,    53,    57,    59,    64,
      65,    68,    70,    73,    79,    82,    84,    88,    89,    93,
      94,    97,    99,   100,   101,   102,   103,   105,   107,   108,
     109,   110,   111,   116,   117,   118,   122,   126,   127,   130,
     132,   133,   136,   138,   142,   143,   147,   148,   149,   150,
     151,   152,   155,   157,   160,   162,   166,   169,   171,   174,
     175,   176,   177,   188,   190,   197,   199,   202,   205,   206,
     210,   211,   212,   213,   214,   215,   224,   226,   227,   228,
     229,   233
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_PROGRAM",
  "TOKEN_VAR", "TOKEN_PROCEDURE", "TOKEN_FUNCTION", "TOKEN_BEGIN",
  "TOKEN_END", "TOKEN_FALSE", "TOKEN_TRUE", "TOKEN_IF", "TOKEN_THEN",
  "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_DO", "TOKEN_READ", "TOKEN_WRITE",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT", "TOKEN_DIV", "TOKEN_INTEGER",
  "TOKEN_BOOLEAN", "TOKEN_SOMA", "TOKEN_SUBT", "TOKEN_MULT", "TOKEN_IGUAL",
  "TOKEN_FECHAPAR", "TOKEN_ABREPAR", "TOKEN_PONTOVIRG", "TOKEN_VIRG",
  "TOKEN_PONTO", "TOKEN_DIF", "TOKEN_MAIOR", "TOKEN_MENOR",
  "TOKEN_MAIORIGUAL", "TOKEN_MENORIGUAL", "TOKEN_ATRIB", "TOKEN_DOISP",
  "ID", "NUMERO", "$accept", "root", "resto", "declaracao_variaveis",
  "lista_variaveis", "outro_tipo_variaveis", "tipo",
  "declaracao_subprogramas", "resto_funcao", "retorno_funcao",
  "comando_begin_geral", "comando_begin", "corpo", "mais_corpo", "funcao",
  "quantidade_variaveis", "quantidade_itens_escrita", "mais_itens_escrita",
  "mais_variaveis", "expressao", "termo", "lista_parametros",
  "resto_parametros", "calculo", "seq_calculo", "operador", "condicional",
  "expressao_condicional", "comparacao", "mais_comparacoes", "loop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   -24,    20,    11,  -104,    34,    16,  -104,    28,    14,
    -104,    22,    25,    25,    61,    32,  -104,    13,    51,    48,
      48,    86,  -104,    14,  -104,  -104,    64,    16,    13,    66,
      71,    86,    33,    30,    62,    79,    69,    73,    30,    -8,
    -104,    87,     1,    87,    87,    89,    87,    87,  -104,    16,
      83,  -104,    34,    34,     7,    45,    45,    94,    33,    95,
      -9,   116,   151,    -9,    16,     8,  -104,  -104,   101,    98,
      33,    86,  -104,   108,   135,  -104,  -104,    98,  -104,  -104,
    -104,   105,    13,   141,   141,  -104,   144,    96,   122,  -104,
    -104,    33,   134,   128,  -104,  -104,  -104,  -104,  -104,  -104,
      30,   141,  -104,  -104,  -104,  -104,  -104,    30,    30,   129,
     133,   133,   145,  -104,   143,   150,  -104,  -104,    87,    87,
      87,    87,    87,  -104,   121,   152,    13,   153,   149,   154,
    -104,   125,  -104,   125,  -104,   155,    45,    45,    87,   151,
     167,  -104,    43,  -104,  -104,  -104,   146,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   157,  -104,  -104,  -104,
      33,  -104,  -104,    45,  -104,  -104,   172,  -104,   141,   133,
     133,   143,    16,   160,  -104,   141,    87,  -104,  -104,  -104,
    -104,    45,    87,  -104,  -104,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     2,    11,    42,
       5,     0,     0,     0,     0,     0,    36,     0,     0,    15,
      15,    21,     3,    42,     9,    10,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    27,     0,    27,    27,     0,    27,    27,    43,     7,
       0,    16,     4,     4,     0,    76,    76,     0,     0,    47,
       0,     0,    57,     0,     0,     0,    50,    49,     0,    52,
       0,     0,    26,     0,     0,    22,    23,    52,    24,    25,
       6,     0,     0,     0,     0,    19,     0,     0,     0,    69,
      68,     0,    57,     0,    75,    70,    71,    73,    72,    74,
       0,     0,    62,    59,    60,    61,    56,     0,     0,     0,
      39,    39,     0,    46,    54,     0,    44,    45,    27,    27,
      27,    27,    27,    17,     0,     0,     0,     0,     0,     0,
      20,     0,    77,     0,    79,     0,    76,    76,    27,    57,
       0,    33,     0,    37,    38,    34,     0,    53,    51,    32,
      28,    29,    30,    31,    18,    35,     0,    14,    13,    12,
       0,    78,    80,    76,    66,    65,    63,    58,     0,    39,
      39,    54,     7,     0,    67,     0,    27,    40,    41,    55,
       8,    76,    27,    81,    66,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,    46,  -104,    17,   -22,  -104,   177,   171,
    -104,   -61,   161,   -43,   123,     5,  -104,  -103,   170,   124,
     -19,   119,    26,   -26,    59,  -104,   130,   -41,   136,   -51,
     131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,     8,    10,    80,    26,    14,    19,    29,
      22,    41,    42,    72,    43,    81,   112,   143,    16,    44,
      60,   115,   147,    68,   106,   107,    46,    61,   100,    89,
      47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,    76,    45,    78,    79,    90,    51,    63,   144,    73,
     118,    11,    45,     1,    62,    85,     3,    93,    94,    62,
       4,    69,   128,   129,    95,    96,    97,    98,    99,   117,
      70,    74,    50,    12,    13,    24,    25,    86,     6,    92,
     138,     5,    55,    56,   116,    15,   132,   134,   110,   111,
     135,    92,    45,    57,    36,    37,     9,    36,    37,    38,
     127,    17,    58,    87,    88,    18,   177,   178,    21,   109,
      59,    40,    23,    59,    40,   149,   150,   151,   152,   153,
      27,   137,   140,   169,   170,   164,   165,    28,   139,    62,
     161,    64,   162,    31,    49,   166,    52,    32,    83,    84,
      33,    53,    34,    35,   156,    55,    56,   176,    65,    66,
      36,    37,   174,    67,   182,    38,   131,    71,    77,   173,
      36,    37,    82,    91,    69,    58,    39,    40,   101,   113,
     184,    55,    56,   183,    55,    56,    59,    40,   114,   185,
     123,    92,   133,   124,   126,    57,    36,    37,    31,    36,
      37,    58,   130,   154,   160,   102,   136,   141,   103,   104,
     105,    94,    59,    40,   142,    59,    40,    95,    96,    97,
      98,    99,   102,   145,   146,   103,   104,   105,   148,   158,
     155,   157,   168,   163,   159,   175,   171,   172,   181,   180,
      20,    30,    54,    48,   119,   120,   125,   179,   167,   108,
       0,   121,   122
};

static const yytype_int16 yycheck[] =
{
      43,    44,    21,    46,    47,    56,    28,    33,   111,     8,
      71,     6,    31,     3,    33,     8,    40,    58,    27,    38,
       0,    29,    83,    84,    33,    34,    35,    36,    37,    70,
      38,    30,    27,     5,     6,    22,    23,    30,     4,    58,
     101,    30,     9,    10,    70,    31,    87,    88,    40,    41,
      91,    70,    71,    20,    24,    25,    40,    24,    25,    29,
      82,    39,    29,    18,    19,    40,   169,   170,     7,    64,
      40,    41,    40,    40,    41,   118,   119,   120,   121,   122,
      29,   100,   108,    40,    41,   136,   137,    39,   107,   108,
     131,    29,   133,     7,    30,   138,    30,    11,    52,    53,
      14,    30,    16,    17,   126,     9,    10,   168,    29,    40,
      24,    25,   163,    40,   175,    29,    20,    30,    29,   160,
      24,    25,    39,    29,    29,    29,    40,    41,    12,    28,
     181,     9,    10,   176,     9,    10,    40,    41,    40,   182,
      32,   160,    20,     8,    39,    20,    24,    25,     7,    24,
      25,    29,     8,    32,    29,    21,    28,    28,    24,    25,
      26,    27,    40,    41,    31,    40,    41,    33,    34,    35,
      36,    37,    21,    28,    31,    24,    25,    26,    28,    30,
      28,    28,    15,    28,    30,    13,    40,    30,    28,   172,
      13,    20,    31,    23,    71,    71,    77,   171,   139,    63,
      -1,    71,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    40,     0,    30,     4,    44,    45,    40,
      46,    57,     5,     6,    49,    31,    60,    39,    40,    50,
      50,     7,    52,    40,    22,    23,    48,    29,    39,    51,
      51,     7,    11,    14,    16,    17,    24,    25,    29,    40,
      41,    53,    54,    56,    61,    62,    68,    72,    60,    30,
      57,    48,    30,    30,    54,     9,    10,    20,    29,    40,
      62,    69,    62,    65,    29,    29,    40,    40,    65,    29,
      38,    30,    55,     8,    30,    55,    55,    29,    55,    55,
      47,    57,    39,    45,    45,     8,    30,    18,    19,    71,
      71,    29,    62,    69,    27,    33,    34,    35,    36,    37,
      70,    12,    21,    24,    25,    26,    66,    67,    70,    57,
      40,    41,    58,    28,    40,    63,    65,    69,    53,    56,
      61,    68,    72,    32,     8,    63,    39,    48,    53,    53,
       8,    20,    69,    20,    69,    69,    28,    62,    53,    62,
      65,    28,    31,    59,    59,    28,    31,    64,    28,    55,
      55,    55,    55,    55,    32,    28,    48,    28,    30,    30,
      29,    69,    69,    28,    71,    71,    55,    66,    15,    40,
      41,    40,    30,    69,    71,    13,    53,    59,    59,    64,
      47,    28,    53,    55,    71,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    47,    47,    48,
      48,    49,    49,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    57,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     0,     2,     5,     0,     5,     1,
       1,     0,     7,     7,     6,     0,     2,     4,     5,     3,
       4,     0,     2,     2,     2,     2,     2,     0,     3,     3,
       3,     3,     3,     4,     4,     4,     2,     2,     2,     0,
       3,     3,     0,     3,     3,     3,     3,     1,     1,     2,
       2,     4,     0,     2,     0,     3,     2,     0,     3,     1,
       1,     1,     1,     5,     8,     4,     4,     5,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     2,     3,     2,
       3,     7
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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

#line 1273 "sintatico.tab.c"

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
      yyerror (YY_("syntax error"));
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 236 "sintatico.y"



    int main(int argc, char **argv) {
        
        
        if (argc < 2) {
            fprintf(stderr, "Erro: Forneça um nome de arquivo.\n");
            fprintf(stderr, "Uso: %s nome_do_arquivo.txt\n", argv[0]);
            return 1;
        }

        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Não foi possível abrir o arquivo %s\n", argv[1]);
            return 1;
        }
        
        /* apagar daqui até  depois do rewind pra retirar essa léxica anterior. */
        printf("- Iniciando Fase 1: Análise Léxica -\n");
        
        
        while (yylex() != 0);
        
        printf("- Análise Léxica finalizada. Quantidade de erros: %d -\n", contador_erros_lexicos);

        if (contador_erros_lexicos > 0) {
            printf("\nCompilação abortada devido a erros léxicos.\n");
            fclose(yyin);
            return 1; /* Termina o programa com erro */
        }
        
        rewind(yyin); 

        
        /* resetar o contador de linhas */
        yylineno = 1;
        
        printf("\n--- Iniciando Fase 2: Análise Sintática ---\n");
        yydebug = 1; 
        
        int resultado_parse = yyparse(); 
    
        if (resultado_parse == 0) {
            printf("\n--- Análise Sintática finalizada com sucesso. ---\n");
        } else {
            printf("\n--- Análise Sintática falhou. ---\n");
        }
    

        // yyparse(); 
        
        fclose(yyin);
        
        
        return 0;
    }

    void yyerror(const char *s) {

        fprintf(stderr, "\nErro Sintático na linha %d: %s\n", yylineno, s);

        fprintf(stderr, "    Token inesperado: '%s'\n", yytext);
    }
