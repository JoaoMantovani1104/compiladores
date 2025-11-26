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
#line 1 "sintatico_novo.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"

    /* Declaração das funções que o Bison precisará */
    int yylex(); // A função do analisador léxico (gerada pelo Flex)
    void yyerror(const char *s); // A função para reportar erros
    int contador_erros_lexicos = 0;
    extern FILE *yyin;
    extern int yylineno;
    extern char *yytext;
    extern int yydebug; 
    

#line 88 "sintatico_novo.tab.c"

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

#include "sintatico_novo.tab.h"
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
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_bloco = 44,                     /* bloco  */
  YYSYMBOL_bloco_subrot = 45,              /* bloco_subrot  */
  YYSYMBOL_secao_declaracao_variaveis_opcional = 46, /* secao_declaracao_variaveis_opcional  */
  YYSYMBOL_secao_declaracao_subrotinas_opcional = 47, /* secao_declaracao_subrotinas_opcional  */
  YYSYMBOL_secao_declaracao_variaveis = 48, /* secao_declaracao_variaveis  */
  YYSYMBOL_lista_declaracao_variaveis_opcional = 49, /* lista_declaracao_variaveis_opcional  */
  YYSYMBOL_declaracao_variaveis = 50,      /* declaracao_variaveis  */
  YYSYMBOL_lista_identificadores = 51,     /* lista_identificadores  */
  YYSYMBOL_lista_identificadores_resto_opcional = 52, /* lista_identificadores_resto_opcional  */
  YYSYMBOL_tipo = 53,                      /* tipo  */
  YYSYMBOL_secao_declaracao_subrotinas = 54, /* secao_declaracao_subrotinas  */
  YYSYMBOL_declaracao_subrotina = 55,      /* declaracao_subrotina  */
  YYSYMBOL_declaracao_procedimento = 56,   /* declaracao_procedimento  */
  YYSYMBOL_declaracao_funcao = 57,         /* declaracao_funcao  */
  YYSYMBOL_parametros_formais_opcional = 58, /* parametros_formais_opcional  */
  YYSYMBOL_parametros_formais = 59,        /* parametros_formais  */
  YYSYMBOL_declaracao_parametros_lista = 60, /* declaracao_parametros_lista  */
  YYSYMBOL_declaracao_parametros = 61,     /* declaracao_parametros  */
  YYSYMBOL_comando_composto = 62,          /* comando_composto  */
  YYSYMBOL_comando_lista = 63,             /* comando_lista  */
  YYSYMBOL_comando = 64,                   /* comando  */
  YYSYMBOL_atribuicao = 65,                /* atribuicao  */
  YYSYMBOL_chamada_procedimento = 66,      /* chamada_procedimento  */
  YYSYMBOL_condicional = 67,               /* condicional  */
  YYSYMBOL_repeticao = 68,                 /* repeticao  */
  YYSYMBOL_leitura = 69,                   /* leitura  */
  YYSYMBOL_escrita = 70,                   /* escrita  */
  YYSYMBOL_lista_expressoes = 71,          /* lista_expressoes  */
  YYSYMBOL_lista_expressoes_opcional = 72, /* lista_expressoes_opcional  */
  YYSYMBOL_expressao = 73,                 /* expressao  */
  YYSYMBOL_relacao = 74,                   /* relacao  */
  YYSYMBOL_expressao_simples = 75,         /* expressao_simples  */
  YYSYMBOL_op_aditivo = 76,                /* op_aditivo  */
  YYSYMBOL_termo = 77,                     /* termo  */
  YYSYMBOL_op_multiplicativo = 78,         /* op_multiplicativo  */
  YYSYMBOL_fator = 79,                     /* fator  */
  YYSYMBOL_logico = 80                     /* logico  */
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
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

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
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    61,    71,    80,    81,    85,    86,    90,
      97,    98,   106,   114,   126,   127,   135,   136,   140,   145,
     152,   153,   157,   166,   175,   176,   180,   187,   188,   196,
     205,   212,   213,   221,   222,   223,   224,   225,   226,   227,
     231,   258,   269,   278,   289,   299,   306,   313,   314,   322,
     323,   327,   328,   336,   337,   338,   339,   340,   341,   345,
     346,   353,   354,   355,   359,   360,   367,   368,   369,   373,
     379,   384,   386,   388,   390,   396,   404,   405
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
  "ID", "NUMERO", "$accept", "programa", "bloco", "bloco_subrot",
  "secao_declaracao_variaveis_opcional",
  "secao_declaracao_subrotinas_opcional", "secao_declaracao_variaveis",
  "lista_declaracao_variaveis_opcional", "declaracao_variaveis",
  "lista_identificadores", "lista_identificadores_resto_opcional", "tipo",
  "secao_declaracao_subrotinas", "declaracao_subrotina",
  "declaracao_procedimento", "declaracao_funcao",
  "parametros_formais_opcional", "parametros_formais",
  "declaracao_parametros_lista", "declaracao_parametros",
  "comando_composto", "comando_lista", "comando", "atribuicao",
  "chamada_procedimento", "condicional", "repeticao", "leitura", "escrita",
  "lista_expressoes", "lista_expressoes_opcional", "expressao", "relacao",
  "expressao_simples", "op_aditivo", "termo", "op_multiplicativo", "fator",
  "logico", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,   -17,    27,     4,   -77,    33,     5,    15,    53,   -77,
     -77,    23,    21,   -77,    22,    28,    54,    53,    39,   -77,
     -77,    41,   -77,   -10,    44,    44,     0,   -77,    40,   -77,
      34,     5,   -77,   -77,   -77,     5,    45,   -77,    37,    10,
      10,    48,    49,   -20,   -77,     2,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,    50,    42,    16,   -77,    33,
     -10,   -77,   -77,    10,    10,    10,    55,   -77,    67,    30,
       7,   -77,   -77,    68,     5,    10,    10,    10,   -77,     0,
     -77,   -10,   -77,     5,   -77,    54,    52,   -77,   -77,    57,
      10,     0,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,    10,    10,   -77,   -77,   -77,    10,     0,    58,    -7,
     -77,    56,    60,   -77,   -77,   -77,   -77,   -77,    33,   -77,
      62,    78,    17,     7,   -77,   -77,   -77,   -77,    10,   -77,
     -77,   -77,     0,   -77,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     7,     6,
      14,     0,     0,     2,     0,     0,     0,     8,     0,    20,
      21,    13,    10,     0,    24,    24,     0,     3,     0,    18,
       0,     9,    17,    16,    12,     0,     0,    25,     0,     0,
       0,     0,     0,     0,    39,     0,    31,    33,    34,    35,
      36,    37,    38,    19,    15,     0,     0,     0,    27,     5,
       0,    76,    77,     0,     0,     0,    69,    71,     0,    51,
      59,    64,    72,     0,     0,     0,    49,     0,    30,     0,
      11,     0,    26,     0,    22,     0,     0,    74,    75,     0,
      49,     0,    63,    61,    62,    53,    54,    57,    55,    58,
      56,     0,     0,    68,    67,    66,     0,     0,     0,     0,
      47,    50,     0,    40,    32,    29,    28,     4,     5,    73,
       0,    42,    52,    60,    65,    44,    45,    46,     0,    41,
      23,    70,     0,    48,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   -26,    88,   -77,   -77,   -77,    63,   -31,
     -77,   -52,   -77,    79,   -77,   -77,    70,   -77,   -77,    14,
     -14,   -77,   -76,   -77,   -77,   -77,   -77,   -77,   -77,    24,
       8,   -39,   -77,    -1,   -77,     1,   -77,   -58,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    84,    85,    16,     9,    31,    11,    12,
      21,    34,    17,    18,    19,    20,    36,    37,    57,    58,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   111,
     112,   110,   101,    69,   102,    70,   106,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    73,    27,   114,    56,    87,    88,    26,    86,    76,
      78,    39,    32,    33,    40,   121,    41,    42,    77,    61,
      62,   127,     1,     3,   128,   103,    89,     4,   104,   115,
      63,   125,    79,   105,     5,    64,    92,     6,   113,    65,
      43,    93,    94,   108,    82,    10,    83,    13,   124,    92,
      66,    67,    56,    22,    93,    94,   134,    95,    14,    15,
      23,    26,    24,    96,    97,    98,    99,   100,    25,    29,
      53,   117,    30,    35,    54,    59,    60,    74,    75,    91,
      80,    81,   118,   107,    90,   119,   126,   128,   129,   133,
     131,   132,   130,     8,    55,    38,    28,   116,   120,   109,
     122,     0,     0,   123
};

static const yytype_int16 yycheck[] =
{
      39,    40,    16,    79,    35,    63,    64,     7,    60,    29,
       8,    11,    22,    23,    14,    91,    16,    17,    38,     9,
      10,    28,     3,    40,    31,    18,    65,     0,    21,    81,
      20,   107,    30,    26,    30,    25,    19,     4,    77,    29,
      40,    24,    25,    74,    28,    40,    30,    32,   106,    19,
      40,    41,    83,    30,    24,    25,   132,    27,     5,     6,
      39,     7,    40,    33,    34,    35,    36,    37,    40,    30,
      30,    85,    31,    29,    40,    30,    39,    29,    29,    12,
      30,    39,    30,    15,    29,    28,    28,    31,    28,   128,
      28,    13,   118,     5,    31,    25,    17,    83,    90,    75,
     101,    -1,    -1,   102
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    40,     0,    30,     4,    44,    46,    48,
      40,    50,    51,    32,     5,     6,    47,    54,    55,    56,
      57,    52,    30,    39,    40,    40,     7,    62,    55,    30,
      31,    49,    22,    23,    53,    29,    58,    59,    58,    11,
      14,    16,    17,    40,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    30,    40,    50,    51,    60,    61,    30,
      39,     9,    10,    20,    25,    29,    40,    41,    73,    75,
      77,    79,    80,    73,    29,    29,    29,    38,     8,    30,
      30,    39,    28,    30,    45,    46,    53,    79,    79,    73,
      29,    12,    19,    24,    25,    27,    33,    34,    35,    36,
      37,    74,    76,    18,    21,    26,    78,    15,    51,    71,
      73,    71,    72,    73,    64,    53,    61,    62,    30,    28,
      72,    64,    75,    77,    79,    64,    28,    28,    31,    28,
      45,    28,    13,    73,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    58,    59,    60,    60,    61,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      65,    66,    67,    67,    68,    69,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     1,     0,     1,     4,
       0,     3,     3,     2,     0,     3,     1,     1,     2,     3,
       1,     1,     5,     7,     0,     1,     3,     1,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     4,     6,     4,     4,     4,     1,     3,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     1,     1,     3,     2,     2,     1,     1
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
  case 2: /* programa: TOKEN_PROGRAM ID TOKEN_PONTOVIRG bloco TOKEN_PONTO  */
#line 54 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_programa((yyvsp[-3].sval), (yyvsp[-1].no_ast));
        savedTree = (yyval.no_ast);
    }
#line 1255 "sintatico_novo.tab.c"
    break;

  case 3: /* bloco: secao_declaracao_variaveis_opcional secao_declaracao_subrotinas_opcional comando_composto  */
#line 64 "sintatico_novo.y"
    {
        TreeNode* decls = novo_no_lista((yyvsp[-2].no_ast), (yyvsp[-1].no_ast));
        (yyval.no_ast) = novo_no_lista(decls, (yyvsp[0].no_ast));
    }
#line 1264 "sintatico_novo.tab.c"
    break;

  case 4: /* bloco_subrot: secao_declaracao_variaveis_opcional comando_composto  */
#line 73 "sintatico_novo.y"
    {
        /* Junta as variáveis locais ($1) com o corpo ($2) */
        (yyval.no_ast) = novo_no_lista((yyvsp[-1].no_ast), (yyvsp[0].no_ast));
    }
#line 1273 "sintatico_novo.tab.c"
    break;

  case 5: /* secao_declaracao_variaveis_opcional: %empty  */
#line 80 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1279 "sintatico_novo.tab.c"
    break;

  case 6: /* secao_declaracao_variaveis_opcional: secao_declaracao_variaveis  */
#line 81 "sintatico_novo.y"
                                 { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1285 "sintatico_novo.tab.c"
    break;

  case 7: /* secao_declaracao_subrotinas_opcional: %empty  */
#line 85 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1291 "sintatico_novo.tab.c"
    break;

  case 8: /* secao_declaracao_subrotinas_opcional: secao_declaracao_subrotinas  */
#line 86 "sintatico_novo.y"
                                  { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1297 "sintatico_novo.tab.c"
    break;

  case 9: /* secao_declaracao_variaveis: TOKEN_VAR declaracao_variaveis TOKEN_PONTOVIRG lista_declaracao_variaveis_opcional  */
#line 91 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_lista((yyvsp[-2].no_ast), (yyvsp[0].no_ast));
    }
#line 1305 "sintatico_novo.tab.c"
    break;

  case 10: /* lista_declaracao_variaveis_opcional: %empty  */
#line 97 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1311 "sintatico_novo.tab.c"
    break;

  case 11: /* lista_declaracao_variaveis_opcional: lista_declaracao_variaveis_opcional declaracao_variaveis TOKEN_PONTOVIRG  */
#line 99 "sintatico_novo.y"
    {
        /* recursão à esquerda para criar lista */
        (yyval.no_ast) = novo_no_lista((yyvsp[-1].no_ast), (yyvsp[-2].no_ast));
    }
#line 1320 "sintatico_novo.tab.c"
    break;

  case 12: /* declaracao_variaveis: lista_identificadores TOKEN_DOISP tipo  */
#line 107 "sintatico_novo.y"
    {
        processar_declaracao_vars((yyvsp[-2].no_ast), (yyvsp[0].sval));  /* enviar IDs e tipo */
        (yyval.no_ast) = (yyvsp[-2].no_ast); /* retonar os ids para visualização*/
    }
#line 1329 "sintatico_novo.tab.c"
    break;

  case 13: /* lista_identificadores: ID lista_identificadores_resto_opcional  */
#line 115 "sintatico_novo.y"
    {
        TreeNode* no_id = novo_no_id((yyvsp[-1].sval));
        if ((yyvsp[0].no_ast) == NULL) {
            (yyval.no_ast) = no_id;
        } else {
            (yyval.no_ast) = novo_no_lista(no_id, (yyvsp[0].no_ast));
        }
    }
#line 1342 "sintatico_novo.tab.c"
    break;

  case 14: /* lista_identificadores_resto_opcional: %empty  */
#line 126 "sintatico_novo.y"
          {(yyval.no_ast) = NULL;}
#line 1348 "sintatico_novo.tab.c"
    break;

  case 15: /* lista_identificadores_resto_opcional: lista_identificadores_resto_opcional TOKEN_VIRG ID  */
#line 128 "sintatico_novo.y"
    {
        TreeNode* no_id = novo_no_id((yyvsp[0].sval));
        (yyval.no_ast) = novo_no_lista(no_id, (yyvsp[-2].no_ast));
    }
#line 1357 "sintatico_novo.tab.c"
    break;

  case 16: /* tipo: TOKEN_BOOLEAN  */
#line 135 "sintatico_novo.y"
                  { (yyval.sval) = strdup("boolean"); }
#line 1363 "sintatico_novo.tab.c"
    break;

  case 17: /* tipo: TOKEN_INTEGER  */
#line 136 "sintatico_novo.y"
                    { (yyval.sval) = strdup("integer"); }
#line 1369 "sintatico_novo.tab.c"
    break;

  case 18: /* secao_declaracao_subrotinas: declaracao_subrotina TOKEN_PONTOVIRG  */
#line 141 "sintatico_novo.y"
    { 
        (yyval.no_ast) = (yyvsp[-1].no_ast); /* Caso base: uma subrotina */
            
    }
#line 1378 "sintatico_novo.tab.c"
    break;

  case 19: /* secao_declaracao_subrotinas: secao_declaracao_subrotinas declaracao_subrotina TOKEN_PONTOVIRG  */
#line 146 "sintatico_novo.y"
    {
        /* Lista de subrotinas */
        (yyval.no_ast) = novo_no_lista((yyvsp[-1].no_ast), (yyvsp[-2].no_ast));
    }
#line 1387 "sintatico_novo.tab.c"
    break;

  case 22: /* declaracao_procedimento: TOKEN_PROCEDURE ID parametros_formais_opcional TOKEN_PONTOVIRG bloco_subrot  */
#line 158 "sintatico_novo.y"
    {
        inserir_simbolo((yyvsp[-3].sval), "procedure");
        /* nas procedure não tem tipo de retorno (NULL) e o corpo é $5 */
        (yyval.no_ast) = novo_no_subrotina((yyvsp[-3].sval), (yyvsp[-2].no_ast), NULL, (yyvsp[0].no_ast));
    }
#line 1397 "sintatico_novo.tab.c"
    break;

  case 23: /* declaracao_funcao: TOKEN_FUNCTION ID parametros_formais_opcional TOKEN_DOISP tipo TOKEN_PONTOVIRG bloco_subrot  */
#line 167 "sintatico_novo.y"
    {
        inserir_simbolo((yyvsp[-5].sval), "function");
        /* function tem seu tipo ($5) e o corpo é $7 */
        (yyval.no_ast) = novo_no_subrotina((yyvsp[-5].sval), (yyvsp[-4].no_ast), (yyvsp[-2].sval), (yyvsp[0].no_ast));
    }
#line 1407 "sintatico_novo.tab.c"
    break;

  case 24: /* parametros_formais_opcional: %empty  */
#line 175 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1413 "sintatico_novo.tab.c"
    break;

  case 25: /* parametros_formais_opcional: parametros_formais  */
#line 176 "sintatico_novo.y"
                         { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1419 "sintatico_novo.tab.c"
    break;

  case 26: /* parametros_formais: TOKEN_ABREPAR declaracao_parametros_lista TOKEN_FECHAPAR  */
#line 181 "sintatico_novo.y"
    {
        (yyval.no_ast) = (yyvsp[-1].no_ast); /* passar a lista que foi criada */
    }
#line 1427 "sintatico_novo.tab.c"
    break;

  case 27: /* declaracao_parametros_lista: declaracao_parametros  */
#line 187 "sintatico_novo.y"
                          { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1433 "sintatico_novo.tab.c"
    break;

  case 28: /* declaracao_parametros_lista: declaracao_parametros_lista TOKEN_PONTOVIRG declaracao_parametros  */
#line 189 "sintatico_novo.y"
    {
        /* nova lista de declarações de parâmetros */
        (yyval.no_ast) = novo_no_lista((yyvsp[0].no_ast), (yyvsp[-2].no_ast));
    }
#line 1442 "sintatico_novo.tab.c"
    break;

  case 29: /* declaracao_parametros: lista_identificadores TOKEN_DOISP tipo  */
#line 197 "sintatico_novo.y"
    {
        /* mesma lógica de variáveis: processa o tipo e retorna a lista de IDs */
        processar_declaracao_vars((yyvsp[-2].no_ast), (yyvsp[0].sval)); 
        (yyval.no_ast) = (yyvsp[-2].no_ast); 
    }
#line 1452 "sintatico_novo.tab.c"
    break;

  case 30: /* comando_composto: TOKEN_BEGIN comando_lista TOKEN_END  */
#line 206 "sintatico_novo.y"
    {
        (yyval.no_ast) = (yyvsp[-1].no_ast); /* o valor é a própria lista de comandos */
    }
#line 1460 "sintatico_novo.tab.c"
    break;

  case 31: /* comando_lista: comando  */
#line 212 "sintatico_novo.y"
            { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1466 "sintatico_novo.tab.c"
    break;

  case 32: /* comando_lista: comando_lista TOKEN_PONTOVIRG comando  */
#line 214 "sintatico_novo.y"
    {
        /* criar a  lista encadeada de comandos */
        (yyval.no_ast) = novo_no_lista((yyvsp[-2].no_ast), (yyvsp[0].no_ast)); // Atenção: pode precisar ajustar a ordem dependendo da sua função lista
    }
#line 1475 "sintatico_novo.tab.c"
    break;

  case 33: /* comando: atribuicao  */
#line 221 "sintatico_novo.y"
               { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1481 "sintatico_novo.tab.c"
    break;

  case 34: /* comando: chamada_procedimento  */
#line 222 "sintatico_novo.y"
                           { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1487 "sintatico_novo.tab.c"
    break;

  case 35: /* comando: condicional  */
#line 223 "sintatico_novo.y"
                  { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1493 "sintatico_novo.tab.c"
    break;

  case 36: /* comando: repeticao  */
#line 224 "sintatico_novo.y"
                { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1499 "sintatico_novo.tab.c"
    break;

  case 37: /* comando: leitura  */
#line 225 "sintatico_novo.y"
              { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1505 "sintatico_novo.tab.c"
    break;

  case 38: /* comando: escrita  */
#line 226 "sintatico_novo.y"
              { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1511 "sintatico_novo.tab.c"
    break;

  case 39: /* comando: comando_composto  */
#line 227 "sintatico_novo.y"
                       { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1517 "sintatico_novo.tab.c"
    break;

  case 40: /* atribuicao: ID TOKEN_ATRIB expressao  */
#line 232 "sintatico_novo.y"
    {
        Simbolo *s = buscar_simbolo((yyvsp[-2].sval));
        if (s == NULL) {
             printf("ERRO SEMANTICO: Variavel '%s' nao declarada.\n", (yyvsp[-2].sval));
             /* Tratar erro */
        }
        // $$ = novo_no_atribuicao(novo_no_id($1), $3);
        TreeNode* no_id = novo_no_id((yyvsp[-2].sval)); 
        TreeNode* no_expr = (yyvsp[0].no_ast);           
        
        if (no_id->tipo_dado != EXP_ERRO && no_expr->tipo_dado != EXP_ERRO) {
            if (no_id->tipo_dado != no_expr->tipo_dado) {
                printf("ERRO SEMANTICO (Linha %d): Atribuicao invalida. ", yylineno);
                printf("Variavel '%s' eh do tipo %s, mas recebeu %s.\n", 
                        (yyvsp[-2].sval), 
                        (no_id->tipo_dado == EXP_INTEGER ? "INTEGER" : "BOOLEAN"),
                        (no_expr->tipo_dado == EXP_INTEGER ? "INTEGER" : "BOOLEAN")
                );
            }
        }

        (yyval.no_ast) = novo_no_atribuicao(no_id, no_expr);
    }
#line 1545 "sintatico_novo.tab.c"
    break;

  case 41: /* chamada_procedimento: ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR  */
#line 259 "sintatico_novo.y"
    {
        /* verificar se foi declarado */
        if (buscar_simbolo((yyvsp[-3].sval)) == NULL) printf("Erro: Procedimento '%s' nao declarado\n", (yyvsp[-3].sval));
        
        /* criar o nó */
        (yyval.no_ast) = novo_no_chamada( novo_no_id((yyvsp[-3].sval)), (yyvsp[-1].no_ast) );
    }
#line 1557 "sintatico_novo.tab.c"
    break;

  case 42: /* condicional: TOKEN_IF expressao TOKEN_THEN comando  */
#line 270 "sintatico_novo.y"
    {
        if ((yyvsp[-2].no_ast)->tipo_dado != EXP_BOOLEAN && (yyvsp[-2].no_ast)->tipo_dado != EXP_ERRO) {
             printf("ERRO SEMANTICO (Linha %d): A condicao do 'IF' deve ser booleana.\n", yylineno);
             printf("Tipagem encontrada: INTEGER.\n"); 
        }
        
        (yyval.no_ast) = novo_no_condicional((yyvsp[-2].no_ast), (yyvsp[0].no_ast), NULL);
    }
#line 1570 "sintatico_novo.tab.c"
    break;

  case 43: /* condicional: TOKEN_IF expressao TOKEN_THEN comando TOKEN_ELSE comando  */
#line 279 "sintatico_novo.y"
    {
        if ((yyvsp[-4].no_ast)->tipo_dado != EXP_BOOLEAN && (yyvsp[-4].no_ast)->tipo_dado != EXP_ERRO) {
             printf("ERRO SEMANTICO (Linha %d): A condicao do 'IF' deve ser booleana.\n", yylineno);
        }

        (yyval.no_ast) = novo_no_condicional((yyvsp[-4].no_ast), (yyvsp[-2].no_ast), (yyvsp[0].no_ast));
    }
#line 1582 "sintatico_novo.tab.c"
    break;

  case 44: /* repeticao: TOKEN_WHILE expressao TOKEN_DO comando  */
#line 290 "sintatico_novo.y"
    {
        if ((yyvsp[-2].no_ast)->tipo_dado != EXP_BOOLEAN && (yyvsp[-2].no_ast)->tipo_dado != EXP_ERRO) {
             printf("ERRO SEMANTICO (Linha %d): A condicao do 'WHILE' deve ser booleana.\n", yylineno);
        }
        (yyval.no_ast) = novo_no_while((yyvsp[-2].no_ast), (yyvsp[0].no_ast));
    }
#line 1593 "sintatico_novo.tab.c"
    break;

  case 45: /* leitura: TOKEN_READ TOKEN_ABREPAR lista_identificadores TOKEN_FECHAPAR  */
#line 300 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_io(TIPO_LEITURA, (yyvsp[-1].no_ast));
    }
#line 1601 "sintatico_novo.tab.c"
    break;

  case 46: /* escrita: TOKEN_WRITE TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR  */
#line 307 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_io(TIPO_ESCRITA, (yyvsp[-1].no_ast));
    }
#line 1609 "sintatico_novo.tab.c"
    break;

  case 47: /* lista_expressoes: expressao  */
#line 313 "sintatico_novo.y"
              { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1615 "sintatico_novo.tab.c"
    break;

  case 48: /* lista_expressoes: lista_expressoes TOKEN_VIRG expressao  */
#line 315 "sintatico_novo.y"
    {
        /* no caso recursivo, cria a lista encadeada */
        (yyval.no_ast) = novo_no_lista((yyvsp[0].no_ast), (yyvsp[-2].no_ast)); // Ou ($1, $3) dependendo da ordem que preferir
    }
#line 1624 "sintatico_novo.tab.c"
    break;

  case 49: /* lista_expressoes_opcional: %empty  */
#line 322 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1630 "sintatico_novo.tab.c"
    break;

  case 50: /* lista_expressoes_opcional: lista_expressoes  */
#line 323 "sintatico_novo.y"
                       { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1636 "sintatico_novo.tab.c"
    break;

  case 51: /* expressao: expressao_simples  */
#line 327 "sintatico_novo.y"
                      { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1642 "sintatico_novo.tab.c"
    break;

  case 52: /* expressao: expressao_simples relacao expressao_simples  */
#line 329 "sintatico_novo.y"
    {
        /* relacao retorna o TOKEN (int) usa novo_no_operacao */
        (yyval.no_ast) = novo_no_operacao((yyvsp[-2].no_ast), (yyvsp[-1].ival), (yyvsp[0].no_ast)); 
    }
#line 1651 "sintatico_novo.tab.c"
    break;

  case 53: /* relacao: TOKEN_IGUAL  */
#line 336 "sintatico_novo.y"
                { (yyval.ival) = TOKEN_IGUAL; }
#line 1657 "sintatico_novo.tab.c"
    break;

  case 54: /* relacao: TOKEN_DIF  */
#line 337 "sintatico_novo.y"
                { (yyval.ival) = TOKEN_DIF; }
#line 1663 "sintatico_novo.tab.c"
    break;

  case 55: /* relacao: TOKEN_MENOR  */
#line 338 "sintatico_novo.y"
                  { (yyval.ival) = TOKEN_MENOR; }
#line 1669 "sintatico_novo.tab.c"
    break;

  case 56: /* relacao: TOKEN_MENORIGUAL  */
#line 339 "sintatico_novo.y"
                       {(yyval.ival) = TOKEN_MENORIGUAL;}
#line 1675 "sintatico_novo.tab.c"
    break;

  case 57: /* relacao: TOKEN_MAIOR  */
#line 340 "sintatico_novo.y"
                  {(yyval.ival) = TOKEN_MAIOR;}
#line 1681 "sintatico_novo.tab.c"
    break;

  case 58: /* relacao: TOKEN_MAIORIGUAL  */
#line 341 "sintatico_novo.y"
                       {(yyval.ival) = TOKEN_MAIORIGUAL;}
#line 1687 "sintatico_novo.tab.c"
    break;

  case 59: /* expressao_simples: termo  */
#line 345 "sintatico_novo.y"
          { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1693 "sintatico_novo.tab.c"
    break;

  case 60: /* expressao_simples: expressao_simples op_aditivo termo  */
#line 347 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_operacao((yyvsp[-2].no_ast), (yyvsp[-1].ival), (yyvsp[0].no_ast));
    }
#line 1701 "sintatico_novo.tab.c"
    break;

  case 61: /* op_aditivo: TOKEN_SOMA  */
#line 353 "sintatico_novo.y"
               { (yyval.ival) = TOKEN_SOMA; }
#line 1707 "sintatico_novo.tab.c"
    break;

  case 62: /* op_aditivo: TOKEN_SUBT  */
#line 354 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_SUBT; }
#line 1713 "sintatico_novo.tab.c"
    break;

  case 63: /* op_aditivo: TOKEN_OR  */
#line 355 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_OR; }
#line 1719 "sintatico_novo.tab.c"
    break;

  case 64: /* termo: fator  */
#line 359 "sintatico_novo.y"
          { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1725 "sintatico_novo.tab.c"
    break;

  case 65: /* termo: termo op_multiplicativo fator  */
#line 361 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_operacao((yyvsp[-2].no_ast), (yyvsp[-1].ival), (yyvsp[0].no_ast));
    }
#line 1733 "sintatico_novo.tab.c"
    break;

  case 66: /* op_multiplicativo: TOKEN_MULT  */
#line 367 "sintatico_novo.y"
               { (yyval.ival) = TOKEN_MULT; }
#line 1739 "sintatico_novo.tab.c"
    break;

  case 67: /* op_multiplicativo: TOKEN_DIV  */
#line 368 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_DIV; }
#line 1745 "sintatico_novo.tab.c"
    break;

  case 68: /* op_multiplicativo: TOKEN_AND  */
#line 369 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_AND; }
#line 1751 "sintatico_novo.tab.c"
    break;

  case 69: /* fator: ID  */
#line 374 "sintatico_novo.y"
    { 
        if(buscar_simbolo((yyvsp[0].sval)) == NULL) printf("Erro: '%s' nao declarado\n", (yyvsp[0].sval));
        (yyval.no_ast) = novo_no_id((yyvsp[0].sval)); 
    }
#line 1760 "sintatico_novo.tab.c"
    break;

  case 70: /* fator: ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR  */
#line 380 "sintatico_novo.y"
    {
        if (buscar_simbolo((yyvsp[-3].sval)) == NULL) printf("Erro: Func '%s' nao declarada\n", (yyvsp[-3].sval));
        (yyval.no_ast) = novo_no_chamada( novo_no_id((yyvsp[-3].sval)), (yyvsp[-1].no_ast) );
    }
#line 1769 "sintatico_novo.tab.c"
    break;

  case 71: /* fator: NUMERO  */
#line 384 "sintatico_novo.y"
             { (yyval.no_ast) = novo_no_num((yyvsp[0].sval)); }
#line 1775 "sintatico_novo.tab.c"
    break;

  case 73: /* fator: TOKEN_ABREPAR expressao TOKEN_FECHAPAR  */
#line 388 "sintatico_novo.y"
                                             { (yyval.no_ast) = (yyvsp[-1].no_ast); }
#line 1781 "sintatico_novo.tab.c"
    break;

  case 74: /* fator: TOKEN_NOT fator  */
#line 391 "sintatico_novo.y"
    {
        /* operação unária: nó de operação com filho esquerda NULL (ou o contrário) */
        (yyval.no_ast) = novo_no_operacao(NULL, TOKEN_NOT, (yyvsp[0].no_ast));
    }
#line 1790 "sintatico_novo.tab.c"
    break;

  case 75: /* fator: TOKEN_SUBT fator  */
#line 397 "sintatico_novo.y"
    {
        /* menos unário (ex: -5). tratar como operação unária */
        (yyval.no_ast) = novo_no_operacao(NULL, TOKEN_SUBT, (yyvsp[0].no_ast));
    }
#line 1799 "sintatico_novo.tab.c"
    break;

  case 76: /* logico: TOKEN_FALSE  */
#line 404 "sintatico_novo.y"
                { (yyval.no_ast) = novo_no_bool_literal("false"); }
#line 1805 "sintatico_novo.tab.c"
    break;

  case 77: /* logico: TOKEN_TRUE  */
#line 405 "sintatico_novo.y"
                 { (yyval.no_ast) = novo_no_bool_literal("true"); }
#line 1811 "sintatico_novo.tab.c"
    break;


#line 1815 "sintatico_novo.tab.c"

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

#line 408 "sintatico_novo.y"


    TreeNode *savedTree = NULL;

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
        yydebug = 0; 
        
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
