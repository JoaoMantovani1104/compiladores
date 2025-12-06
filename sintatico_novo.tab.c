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
    void inicializar_tipos_primitivos(); // Inicializa tipos primitivos na tabela
    void inserir_simbolo_com_categoria(char *nome, char *tipo, CategoriaSimbolo categoria);
    void verificar_lista_identificadores_read(TreeNode* lista_ids);
    void verificar_lista_expressoes_write(TreeNode* lista_expr);
    void abrir_escopo(); // Abre um novo escopo
    void fechar_escopo(); // Fecha o escopo atual
    void adicionar_erro_semantico(const char *mensagem);
    void adicionar_erro_sintatico(const char *mensagem);
    void limpar_erros_lexicos();
    void limpar_erros_sintaticos();
    void limpar_erros_semanticos();
    int contar_erros_lexicos();
    int contar_erros_sintaticos();
    int contar_erros_semanticos();
    void exibir_erros_lexicos();
    void exibir_erros_sintaticos();
    void exibir_erros_semanticos();
    extern int contador_erros_lexicos;
    extern FILE *yyin;
    extern int yylineno;
    extern char *yytext;
    extern int yydebug;
    

#line 105 "sintatico_novo.tab.c"

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
  YYSYMBOL_declaracao_funcao_cabecalho = 58, /* declaracao_funcao_cabecalho  */
  YYSYMBOL_parametros_formais_opcional = 59, /* parametros_formais_opcional  */
  YYSYMBOL_parametros_formais = 60,        /* parametros_formais  */
  YYSYMBOL_declaracao_parametros_lista = 61, /* declaracao_parametros_lista  */
  YYSYMBOL_declaracao_parametros = 62,     /* declaracao_parametros  */
  YYSYMBOL_comando_composto = 63,          /* comando_composto  */
  YYSYMBOL_comando_lista = 64,             /* comando_lista  */
  YYSYMBOL_comando = 65,                   /* comando  */
  YYSYMBOL_atribuicao = 66,                /* atribuicao  */
  YYSYMBOL_chamada_procedimento = 67,      /* chamada_procedimento  */
  YYSYMBOL_condicional = 68,               /* condicional  */
  YYSYMBOL_repeticao = 69,                 /* repeticao  */
  YYSYMBOL_leitura = 70,                   /* leitura  */
  YYSYMBOL_escrita = 71,                   /* escrita  */
  YYSYMBOL_lista_expressoes = 72,          /* lista_expressoes  */
  YYSYMBOL_lista_expressoes_opcional = 73, /* lista_expressoes_opcional  */
  YYSYMBOL_expressao = 74,                 /* expressao  */
  YYSYMBOL_relacao = 75,                   /* relacao  */
  YYSYMBOL_expressao_simples = 76,         /* expressao_simples  */
  YYSYMBOL_op_aditivo = 77,                /* op_aditivo  */
  YYSYMBOL_termo = 78,                     /* termo  */
  YYSYMBOL_op_multiplicativo = 79,         /* op_multiplicativo  */
  YYSYMBOL_fator = 80,                     /* fator  */
  YYSYMBOL_logico = 81                     /* logico  */
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
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

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
       0,    81,    81,    89,    99,   110,   111,   115,   116,   120,
     127,   128,   136,   144,   156,   157,   165,   166,   170,   175,
     182,   183,   187,   212,   225,   248,   253,   260,   270,   271,
     279,   288,   295,   296,   304,   305,   306,   307,   308,   309,
     310,   314,   365,   384,   394,   407,   419,   427,   435,   436,
     444,   445,   449,   450,   458,   459,   460,   461,   462,   463,
     467,   468,   483,   484,   485,   489,   490,   497,   498,   499,
     503,   508,   522,   524,   526,   528,   534,   542,   543
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
  "declaracao_funcao_cabecalho", "parametros_formais_opcional",
  "parametros_formais", "declaracao_parametros_lista",
  "declaracao_parametros", "comando_composto", "comando_lista", "comando",
  "atribuicao", "chamada_procedimento", "condicional", "repeticao",
  "leitura", "escrita", "lista_expressoes", "lista_expressoes_opcional",
  "expressao", "relacao", "expressao_simples", "op_aditivo", "termo",
  "op_multiplicativo", "fator", "logico", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -23,    23,    -5,   -78,    31,     0,    13,    28,   -78,
     -78,    21,    16,   -78,    24,    26,    51,    28,    33,   -78,
     -78,    32,    34,   -78,    25,    32,   -78,     2,   -78,    37,
     -78,     0,    36,   -78,    38,     0,   -78,   -78,   -78,    44,
      12,    12,    47,    48,   -18,   -78,    -2,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,    40,   -16,   -78,    25,   -78,
      50,    31,   -78,   -78,    12,    12,    12,    52,   -78,    70,
      35,    18,   -78,   -78,    68,     0,    12,    12,    12,   -78,
       2,    25,   -78,     0,    54,   -78,   -78,    51,   -78,   -78,
      57,    12,     2,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,    12,    12,   -78,   -78,   -78,    12,     2,    58,
      15,   -78,    56,    60,   -78,   -78,   -78,   -78,    31,   -78,
     -78,    62,    78,     5,    18,   -78,   -78,   -78,   -78,    12,
     -78,   -78,   -78,     2,   -78,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     7,     6,
      14,     0,     0,     2,     0,     0,     0,     8,     0,    20,
      21,    25,    13,    10,     0,    25,    24,     0,     3,     0,
      18,     0,     0,    26,     0,     9,    17,    16,    12,     0,
       0,     0,     0,     0,     0,    40,     0,    32,    34,    35,
      36,    37,    38,    39,    19,     0,     0,    28,     0,    15,
       0,     5,    77,    78,     0,     0,     0,    70,    72,     0,
      52,    60,    65,    73,     0,     0,     0,    50,     0,    31,
       0,     0,    27,     0,     0,    11,    22,     0,    75,    76,
       0,    50,     0,    64,    62,    63,    54,    55,    58,    56,
      59,    57,     0,     0,    69,    68,    67,     0,     0,     0,
       0,    48,    51,     0,    41,    33,    30,    29,     5,     4,
      74,     0,    43,    53,    61,    66,    45,    46,    47,     0,
      42,    23,    71,     0,    49,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -25,    87,   -78,   -78,   -78,    59,   -26,
     -78,   -54,   -78,    79,   -78,   -78,   -78,    72,   -78,   -78,
      17,   -14,   -78,   -77,   -78,   -78,   -78,   -78,   -78,   -78,
      19,     8,   -40,   -78,    -4,   -78,    -1,   -78,   -57,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    86,    87,    16,     9,    35,    11,    12,
      22,    38,    17,    18,    19,    20,    21,    32,    33,    56,
      57,    45,    46,    47,    48,    49,    50,    51,    52,    53,
     112,   113,   111,   102,    70,   103,    71,   107,    72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    74,    28,   115,    84,    55,    79,    88,    89,    27,
       1,    77,    82,    40,    83,   122,    41,     3,    42,    43,
      78,    62,    63,     4,    93,     5,    90,   116,    80,    94,
      95,   126,    64,    14,    15,     6,   104,    65,   114,   105,
      10,    66,    44,   128,   106,    13,   129,    36,    37,   109,
     125,    23,    67,    68,    93,    24,   135,    55,    27,    94,
      95,    31,    96,    30,    25,    34,    26,    54,    97,    98,
      99,   100,   101,   119,    61,    58,    75,    76,    59,    81,
      85,    91,    92,   108,   118,   120,   127,   129,   130,   134,
     132,   133,     8,   131,    60,   110,    29,    39,   123,   121,
     117,     0,   124
};

static const yytype_int16 yycheck[] =
{
      40,    41,    16,    80,    58,    31,     8,    64,    65,     7,
       3,    29,    28,    11,    30,    92,    14,    40,    16,    17,
      38,     9,    10,     0,    19,    30,    66,    81,    30,    24,
      25,   108,    20,     5,     6,     4,    18,    25,    78,    21,
      40,    29,    40,    28,    26,    32,    31,    22,    23,    75,
     107,    30,    40,    41,    19,    39,   133,    83,     7,    24,
      25,    29,    27,    30,    40,    31,    40,    30,    33,    34,
      35,    36,    37,    87,    30,    39,    29,    29,    40,    39,
      30,    29,    12,    15,    30,    28,    28,    31,    28,   129,
      28,    13,     5,   118,    35,    76,    17,    25,   102,    91,
      83,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    40,     0,    30,     4,    44,    46,    48,
      40,    50,    51,    32,     5,     6,    47,    54,    55,    56,
      57,    58,    52,    30,    39,    40,    40,     7,    63,    55,
      30,    29,    59,    60,    31,    49,    22,    23,    53,    59,
      11,    14,    16,    17,    40,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    30,    51,    61,    62,    39,    40,
      50,    30,     9,    10,    20,    25,    29,    40,    41,    74,
      76,    78,    80,    81,    74,    29,    29,    29,    38,     8,
      30,    39,    28,    30,    53,    30,    45,    46,    80,    80,
      74,    29,    12,    19,    24,    25,    27,    33,    34,    35,
      36,    37,    75,    77,    18,    21,    26,    79,    15,    51,
      72,    74,    72,    73,    74,    65,    53,    62,    30,    63,
      28,    73,    65,    76,    78,    80,    65,    28,    28,    31,
      28,    45,    28,    13,    74,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    59,    59,    60,    61,    61,
      62,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    68,    68,    69,    70,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     1,     0,     1,     4,
       0,     3,     3,     2,     0,     3,     1,     1,     2,     3,
       1,     1,     5,     6,     2,     0,     1,     3,     1,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     6,     4,     4,     4,     1,     3,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     4,     1,     1,     3,     2,     2,     1,     1
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
#line 82 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_programa((yyvsp[-3].sval), (yyvsp[-1].no_ast));
        savedTree = (yyval.no_ast);
    }
#line 1273 "sintatico_novo.tab.c"
    break;

  case 3: /* bloco: secao_declaracao_variaveis_opcional secao_declaracao_subrotinas_opcional comando_composto  */
#line 92 "sintatico_novo.y"
    {
        TreeNode* decls = novo_no_lista((yyvsp[-2].no_ast), (yyvsp[-1].no_ast));
        (yyval.no_ast) = novo_no_lista(decls, (yyvsp[0].no_ast));
    }
#line 1282 "sintatico_novo.tab.c"
    break;

  case 4: /* bloco_subrot: secao_declaracao_variaveis_opcional comando_composto  */
#line 101 "sintatico_novo.y"
    {
        /* Junta as variáveis locais ($1) com o corpo ($2) */
        (yyval.no_ast) = novo_no_lista((yyvsp[-1].no_ast), (yyvsp[0].no_ast));
        /* Fechar escopo da subrotina ao finalizar o bloco */
        fechar_escopo();
    }
#line 1293 "sintatico_novo.tab.c"
    break;

  case 5: /* secao_declaracao_variaveis_opcional: %empty  */
#line 110 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1299 "sintatico_novo.tab.c"
    break;

  case 6: /* secao_declaracao_variaveis_opcional: secao_declaracao_variaveis  */
#line 111 "sintatico_novo.y"
                                 { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1305 "sintatico_novo.tab.c"
    break;

  case 7: /* secao_declaracao_subrotinas_opcional: %empty  */
#line 115 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1311 "sintatico_novo.tab.c"
    break;

  case 8: /* secao_declaracao_subrotinas_opcional: secao_declaracao_subrotinas  */
#line 116 "sintatico_novo.y"
                                  { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1317 "sintatico_novo.tab.c"
    break;

  case 9: /* secao_declaracao_variaveis: TOKEN_VAR declaracao_variaveis TOKEN_PONTOVIRG lista_declaracao_variaveis_opcional  */
#line 121 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_lista((yyvsp[-2].no_ast), (yyvsp[0].no_ast));
    }
#line 1325 "sintatico_novo.tab.c"
    break;

  case 10: /* lista_declaracao_variaveis_opcional: %empty  */
#line 127 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1331 "sintatico_novo.tab.c"
    break;

  case 11: /* lista_declaracao_variaveis_opcional: lista_declaracao_variaveis_opcional declaracao_variaveis TOKEN_PONTOVIRG  */
#line 129 "sintatico_novo.y"
    {
        /* recursão à esquerda para criar lista */
        (yyval.no_ast) = novo_no_lista((yyvsp[-1].no_ast), (yyvsp[-2].no_ast));
    }
#line 1340 "sintatico_novo.tab.c"
    break;

  case 12: /* declaracao_variaveis: lista_identificadores TOKEN_DOISP tipo  */
#line 137 "sintatico_novo.y"
    {
        processar_declaracao_vars((yyvsp[-2].no_ast), (yyvsp[0].sval));  /* enviar IDs e tipo */
        (yyval.no_ast) = (yyvsp[-2].no_ast); /* retonar os ids para visualização*/
    }
#line 1349 "sintatico_novo.tab.c"
    break;

  case 13: /* lista_identificadores: ID lista_identificadores_resto_opcional  */
#line 145 "sintatico_novo.y"
    {
        TreeNode* no_id = novo_no_id((yyvsp[-1].sval));
        if ((yyvsp[0].no_ast) == NULL) {
            (yyval.no_ast) = no_id;
        } else {
            (yyval.no_ast) = novo_no_lista(no_id, (yyvsp[0].no_ast));
        }
    }
#line 1362 "sintatico_novo.tab.c"
    break;

  case 14: /* lista_identificadores_resto_opcional: %empty  */
#line 156 "sintatico_novo.y"
          {(yyval.no_ast) = NULL;}
#line 1368 "sintatico_novo.tab.c"
    break;

  case 15: /* lista_identificadores_resto_opcional: lista_identificadores_resto_opcional TOKEN_VIRG ID  */
#line 158 "sintatico_novo.y"
    {
        TreeNode* no_id = novo_no_id((yyvsp[0].sval));
        (yyval.no_ast) = novo_no_lista(no_id, (yyvsp[-2].no_ast));
    }
#line 1377 "sintatico_novo.tab.c"
    break;

  case 16: /* tipo: TOKEN_BOOLEAN  */
#line 165 "sintatico_novo.y"
                  { (yyval.sval) = strdup("boolean"); }
#line 1383 "sintatico_novo.tab.c"
    break;

  case 17: /* tipo: TOKEN_INTEGER  */
#line 166 "sintatico_novo.y"
                    { (yyval.sval) = strdup("integer"); }
#line 1389 "sintatico_novo.tab.c"
    break;

  case 18: /* secao_declaracao_subrotinas: declaracao_subrotina TOKEN_PONTOVIRG  */
#line 171 "sintatico_novo.y"
    {
        (yyval.no_ast) = (yyvsp[-1].no_ast); /* Caso base: uma subrotina */

    }
#line 1398 "sintatico_novo.tab.c"
    break;

  case 19: /* secao_declaracao_subrotinas: secao_declaracao_subrotinas declaracao_subrotina TOKEN_PONTOVIRG  */
#line 176 "sintatico_novo.y"
    {
        /* Lista de subrotinas */
        (yyval.no_ast) = novo_no_lista((yyvsp[-1].no_ast), (yyvsp[-2].no_ast));
    }
#line 1407 "sintatico_novo.tab.c"
    break;

  case 22: /* declaracao_procedimento: TOKEN_PROCEDURE ID parametros_formais_opcional TOKEN_PONTOVIRG bloco_subrot  */
#line 188 "sintatico_novo.y"
    {
        Simbolo* s = buscar_simbolo((yyvsp[-3].sval));
        if (s != NULL) {
            if (s->categoria == CATEGORIA_TYPE) {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Nao e possivel redeclarar o tipo primitivo '%s' como procedure.\n", yylineno, (yyvsp[-3].sval));
                adicionar_erro_semantico(buffer);
            } else {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Redeclaracao da procedure '%s'. Ela ja foi declarada anteriormente.\n", yylineno, (yyvsp[-3].sval));
                adicionar_erro_semantico(buffer);
            }
        } else {
            inserir_simbolo_com_categoria((yyvsp[-3].sval), "procedure", CATEGORIA_PROCEDURE);
        }
        /* Escopo já foi aberto em parametros_formais_opcional (se houver parâmetros) */
        /* Se não houver parâmetros, abrir escopo aqui */
        /* O escopo será fechado ao finalizar bloco_subrot */
        /* nas procedure não tem tipo de retorno (NULL) e o corpo é $5 */
        (yyval.no_ast) = novo_no_subrotina((yyvsp[-3].sval), (yyvsp[-2].no_ast), NULL, (yyvsp[0].no_ast));
    }
#line 1433 "sintatico_novo.tab.c"
    break;

  case 23: /* declaracao_funcao: declaracao_funcao_cabecalho parametros_formais_opcional TOKEN_DOISP tipo TOKEN_PONTOVIRG bloco_subrot  */
#line 213 "sintatico_novo.y"
    {
        /* Function já foi inserida na tabela na regra intermediária declaracao_funcao_cabecalho */
        /* Escopo já foi aberto em parametros_formais_opcional (se houver parâmetros) */
        /* Se não houver parâmetros, abrir escopo aqui */
        /* O escopo será fechado ao finalizar bloco_subrot */
        /* function tem seu tipo ($4) e o corpo é $6 */
        (yyval.no_ast) = novo_no_subrotina((yyvsp[-5].sval), (yyvsp[-4].no_ast), (yyvsp[-2].sval), (yyvsp[0].no_ast));
        free((yyvsp[-5].sval)); // Liberar string alocada em declaracao_funcao_cabecalho
    }
#line 1447 "sintatico_novo.tab.c"
    break;

  case 24: /* declaracao_funcao_cabecalho: TOKEN_FUNCTION ID  */
#line 226 "sintatico_novo.y"
    {
        /* Inserir function na tabela IMEDIATAMENTE após ler o nome,
           antes de processar parâmetros e corpo (parser bottom-up) */
        Simbolo* s = buscar_simbolo((yyvsp[0].sval));
        if (s != NULL) {
            if (s->categoria == CATEGORIA_TYPE) {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Nao e possivel redeclarar o tipo primitivo '%s' como function.\n", yylineno, (yyvsp[0].sval));
                adicionar_erro_semantico(buffer);
            } else if (s->categoria != CATEGORIA_FUNCTION) {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Redeclaracao da function '%s'. Ela ja foi declarada anteriormente.\n", yylineno, (yyvsp[0].sval));
                adicionar_erro_semantico(buffer);
            }
        } else {
            inserir_simbolo_com_categoria((yyvsp[0].sval), "function", CATEGORIA_FUNCTION);
        }
        (yyval.sval) = strdup((yyvsp[0].sval)); // Retornar nome da function como string
    }
#line 1471 "sintatico_novo.tab.c"
    break;

  case 25: /* parametros_formais_opcional: %empty  */
#line 248 "sintatico_novo.y"
          {
        /* Se não há parâmetros, ainda precisamos abrir escopo para variáveis locais */
        abrir_escopo();
        (yyval.no_ast) = NULL;
    }
#line 1481 "sintatico_novo.tab.c"
    break;

  case 26: /* parametros_formais_opcional: parametros_formais  */
#line 253 "sintatico_novo.y"
                         {
        /* Escopo já foi aberto em parametros_formais quando processamos os parâmetros */
        (yyval.no_ast) = (yyvsp[0].no_ast);
    }
#line 1490 "sintatico_novo.tab.c"
    break;

  case 27: /* parametros_formais: TOKEN_ABREPAR declaracao_parametros_lista TOKEN_FECHAPAR  */
#line 261 "sintatico_novo.y"
    {
        /* Abrir escopo quando começamos a processar parâmetros */
        /* Isso garante que os parâmetros e variáveis locais fiquem no escopo da subrotina */
        abrir_escopo();
        (yyval.no_ast) = (yyvsp[-1].no_ast); /* passar a lista que foi criada */
    }
#line 1501 "sintatico_novo.tab.c"
    break;

  case 28: /* declaracao_parametros_lista: declaracao_parametros  */
#line 270 "sintatico_novo.y"
                          { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1507 "sintatico_novo.tab.c"
    break;

  case 29: /* declaracao_parametros_lista: declaracao_parametros_lista TOKEN_PONTOVIRG declaracao_parametros  */
#line 272 "sintatico_novo.y"
    {
        /* nova lista de declarações de parâmetros */
        (yyval.no_ast) = novo_no_lista((yyvsp[0].no_ast), (yyvsp[-2].no_ast));
    }
#line 1516 "sintatico_novo.tab.c"
    break;

  case 30: /* declaracao_parametros: lista_identificadores TOKEN_DOISP tipo  */
#line 280 "sintatico_novo.y"
    {
        /* processar parâmetros: permite redeclaração entre diferentes subrotinas */
        processar_declaracao_params((yyvsp[-2].no_ast), (yyvsp[0].sval));
        (yyval.no_ast) = (yyvsp[-2].no_ast);
    }
#line 1526 "sintatico_novo.tab.c"
    break;

  case 31: /* comando_composto: TOKEN_BEGIN comando_lista TOKEN_END  */
#line 289 "sintatico_novo.y"
    {
        (yyval.no_ast) = (yyvsp[-1].no_ast); /* o valor é a própria lista de comandos */
    }
#line 1534 "sintatico_novo.tab.c"
    break;

  case 32: /* comando_lista: comando  */
#line 295 "sintatico_novo.y"
            { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1540 "sintatico_novo.tab.c"
    break;

  case 33: /* comando_lista: comando_lista TOKEN_PONTOVIRG comando  */
#line 297 "sintatico_novo.y"
    {
        /* criar a  lista encadeada de comandos */
        (yyval.no_ast) = novo_no_lista((yyvsp[-2].no_ast), (yyvsp[0].no_ast)); // Atenção: pode precisar ajustar a ordem dependendo da sua função lista
    }
#line 1549 "sintatico_novo.tab.c"
    break;

  case 34: /* comando: atribuicao  */
#line 304 "sintatico_novo.y"
               { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1555 "sintatico_novo.tab.c"
    break;

  case 35: /* comando: chamada_procedimento  */
#line 305 "sintatico_novo.y"
                           { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1561 "sintatico_novo.tab.c"
    break;

  case 36: /* comando: condicional  */
#line 306 "sintatico_novo.y"
                  { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1567 "sintatico_novo.tab.c"
    break;

  case 37: /* comando: repeticao  */
#line 307 "sintatico_novo.y"
                { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1573 "sintatico_novo.tab.c"
    break;

  case 38: /* comando: leitura  */
#line 308 "sintatico_novo.y"
              { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1579 "sintatico_novo.tab.c"
    break;

  case 39: /* comando: escrita  */
#line 309 "sintatico_novo.y"
              { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1585 "sintatico_novo.tab.c"
    break;

  case 40: /* comando: comando_composto  */
#line 310 "sintatico_novo.y"
                       { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1591 "sintatico_novo.tab.c"
    break;

  case 41: /* atribuicao: ID TOKEN_ATRIB expressao  */
#line 315 "sintatico_novo.y"
    {
        Simbolo *s = buscar_simbolo((yyvsp[-2].sval));
        TreeNode* no_id = novo_no_id((yyvsp[-2].sval));
        TreeNode* no_expr = (yyvsp[0].no_ast);

        // Verificar se é atribuição de retorno de função
        // Se o símbolo não está na tabela, pode ser porque ainda não foi inserido (parser bottom-up)
        // Nesse caso, verificamos se é uma function verificando todas as functions declaradas
        int eh_function = 0;
        if (s != NULL && s->categoria == CATEGORIA_FUNCTION) {
            eh_function = 1;
        } else if (s == NULL) {
            // Pode ser uma function que ainda não foi inserida na tabela
            // Por enquanto, assumimos que se não está na tabela e não é variável, pode ser function
            // Isso é uma heurística simples - uma solução completa requeriria gerenciamento de escopos
            eh_function = 0; // Não podemos assumir sem mais contexto
        }

        if (s == NULL && !eh_function) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-2].sval));
             adicionar_erro_semantico(buffer);
        } else if (s != NULL && s->categoria == CATEGORIA_FUNCTION) {
            // Atribuição de retorno de função: permitir sem erro de "não declarada"
            // Não fazer nada, apenas permitir
        } else if (s != NULL && s->categoria != CATEGORIA_VARIABLE) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Tentativa de atribuir valor a '%s' que nao e uma variavel.\n", yylineno, (yyvsp[-2].sval));
            adicionar_erro_semantico(buffer);
        }

        // Verificar tipos apenas se não for atribuição de retorno de função
        if (s != NULL && s->categoria != CATEGORIA_FUNCTION) {
            if (no_id->tipo_dado != EXP_ERRO && no_expr->tipo_dado != EXP_ERRO) {
                if (no_id->tipo_dado != no_expr->tipo_dado) {
                    char buffer[512];
                    snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Atribuicao invalida. Variavel '%s' eh do tipo %s, mas recebeu %s.\n",
                            yylineno, (yyvsp[-2].sval),
                            (no_id->tipo_dado == EXP_INTEGER ? "INTEGER" : "BOOLEAN"),
                            (no_expr->tipo_dado == EXP_INTEGER ? "INTEGER" : "BOOLEAN"));
                    adicionar_erro_semantico(buffer);
                }
            }
        }

        (yyval.no_ast) = novo_no_atribuicao(no_id, no_expr);
    }
#line 1643 "sintatico_novo.tab.c"
    break;

  case 42: /* chamada_procedimento: ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR  */
#line 366 "sintatico_novo.y"
    {
        Simbolo* s = buscar_simbolo((yyvsp[-3].sval));
        if (s == NULL) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Procedimento '%s' nao declarado.\n", yylineno, (yyvsp[-3].sval));
            adicionar_erro_semantico(buffer);
        } else if (s->categoria != CATEGORIA_PROCEDURE && s->categoria != CATEGORIA_FUNCTION) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): '%s' nao e uma procedure ou function.\n", yylineno, (yyvsp[-3].sval));
            adicionar_erro_semantico(buffer);
        }

        /* criar o nó */
        (yyval.no_ast) = novo_no_chamada( novo_no_id((yyvsp[-3].sval)), (yyvsp[-1].no_ast) );
    }
#line 1663 "sintatico_novo.tab.c"
    break;

  case 43: /* condicional: TOKEN_IF expressao TOKEN_THEN comando  */
#line 385 "sintatico_novo.y"
    {
        if ((yyvsp[-2].no_ast)->tipo_dado != EXP_BOOLEAN && (yyvsp[-2].no_ast)->tipo_dado != EXP_ERRO) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): A condicao do 'IF' deve ser booleana.\n", yylineno);
             adicionar_erro_semantico(buffer);
        }

        (yyval.no_ast) = novo_no_condicional((yyvsp[-2].no_ast), (yyvsp[0].no_ast), NULL);
    }
#line 1677 "sintatico_novo.tab.c"
    break;

  case 44: /* condicional: TOKEN_IF expressao TOKEN_THEN comando TOKEN_ELSE comando  */
#line 395 "sintatico_novo.y"
    {
        if ((yyvsp[-4].no_ast)->tipo_dado != EXP_BOOLEAN && (yyvsp[-4].no_ast)->tipo_dado != EXP_ERRO) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): A condicao do 'IF' deve ser booleana.\n", yylineno);
             adicionar_erro_semantico(buffer);
        }

        (yyval.no_ast) = novo_no_condicional((yyvsp[-4].no_ast), (yyvsp[-2].no_ast), (yyvsp[0].no_ast));
    }
#line 1691 "sintatico_novo.tab.c"
    break;

  case 45: /* repeticao: TOKEN_WHILE expressao TOKEN_DO comando  */
#line 408 "sintatico_novo.y"
    {
        if ((yyvsp[-2].no_ast)->tipo_dado != EXP_BOOLEAN && (yyvsp[-2].no_ast)->tipo_dado != EXP_ERRO) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): A condicao do 'WHILE' deve ser booleana.\n", yylineno);
             adicionar_erro_semantico(buffer);
        }
        (yyval.no_ast) = novo_no_while((yyvsp[-2].no_ast), (yyvsp[0].no_ast));
    }
#line 1704 "sintatico_novo.tab.c"
    break;

  case 46: /* leitura: TOKEN_READ TOKEN_ABREPAR lista_identificadores TOKEN_FECHAPAR  */
#line 420 "sintatico_novo.y"
    {
        verificar_lista_identificadores_read((yyvsp[-1].no_ast));
        (yyval.no_ast) = novo_no_io(TIPO_LEITURA, (yyvsp[-1].no_ast));
    }
#line 1713 "sintatico_novo.tab.c"
    break;

  case 47: /* escrita: TOKEN_WRITE TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR  */
#line 428 "sintatico_novo.y"
    {
        verificar_lista_expressoes_write((yyvsp[-1].no_ast));
        (yyval.no_ast) = novo_no_io(TIPO_ESCRITA, (yyvsp[-1].no_ast));
    }
#line 1722 "sintatico_novo.tab.c"
    break;

  case 48: /* lista_expressoes: expressao  */
#line 435 "sintatico_novo.y"
              { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1728 "sintatico_novo.tab.c"
    break;

  case 49: /* lista_expressoes: lista_expressoes TOKEN_VIRG expressao  */
#line 437 "sintatico_novo.y"
    {
        /* no caso recursivo, cria a lista encadeada */
        (yyval.no_ast) = novo_no_lista((yyvsp[0].no_ast), (yyvsp[-2].no_ast)); // Ou ($1, $3) dependendo da ordem que preferir
    }
#line 1737 "sintatico_novo.tab.c"
    break;

  case 50: /* lista_expressoes_opcional: %empty  */
#line 444 "sintatico_novo.y"
          { (yyval.no_ast) = NULL; }
#line 1743 "sintatico_novo.tab.c"
    break;

  case 51: /* lista_expressoes_opcional: lista_expressoes  */
#line 445 "sintatico_novo.y"
                       { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1749 "sintatico_novo.tab.c"
    break;

  case 52: /* expressao: expressao_simples  */
#line 449 "sintatico_novo.y"
                      { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1755 "sintatico_novo.tab.c"
    break;

  case 53: /* expressao: expressao_simples relacao expressao_simples  */
#line 451 "sintatico_novo.y"
    {
        /* relacao retorna o TOKEN (int) usa novo_no_operacao */
        (yyval.no_ast) = novo_no_operacao((yyvsp[-2].no_ast), (yyvsp[-1].ival), (yyvsp[0].no_ast));
    }
#line 1764 "sintatico_novo.tab.c"
    break;

  case 54: /* relacao: TOKEN_IGUAL  */
#line 458 "sintatico_novo.y"
                { (yyval.ival) = TOKEN_IGUAL; }
#line 1770 "sintatico_novo.tab.c"
    break;

  case 55: /* relacao: TOKEN_DIF  */
#line 459 "sintatico_novo.y"
                { (yyval.ival) = TOKEN_DIF; }
#line 1776 "sintatico_novo.tab.c"
    break;

  case 56: /* relacao: TOKEN_MENOR  */
#line 460 "sintatico_novo.y"
                  { (yyval.ival) = TOKEN_MENOR; }
#line 1782 "sintatico_novo.tab.c"
    break;

  case 57: /* relacao: TOKEN_MENORIGUAL  */
#line 461 "sintatico_novo.y"
                       {(yyval.ival) = TOKEN_MENORIGUAL;}
#line 1788 "sintatico_novo.tab.c"
    break;

  case 58: /* relacao: TOKEN_MAIOR  */
#line 462 "sintatico_novo.y"
                  {(yyval.ival) = TOKEN_MAIOR;}
#line 1794 "sintatico_novo.tab.c"
    break;

  case 59: /* relacao: TOKEN_MAIORIGUAL  */
#line 463 "sintatico_novo.y"
                       {(yyval.ival) = TOKEN_MAIORIGUAL;}
#line 1800 "sintatico_novo.tab.c"
    break;

  case 60: /* expressao_simples: termo  */
#line 467 "sintatico_novo.y"
          { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1806 "sintatico_novo.tab.c"
    break;

  case 61: /* expressao_simples: expressao_simples op_aditivo termo  */
#line 469 "sintatico_novo.y"
    {
        /* Verificar se $1 é NULL (não deveria acontecer, mas pode ocorrer em casos de erro) */
        if ((yyvsp[-2].no_ast) == NULL) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Operando esquerdo invalido na expressao.\n", yylineno);
            adicionar_erro_semantico(buffer);
            (yyval.no_ast) = (yyvsp[0].no_ast); /* Retornar apenas o operando direito como fallback */
        } else {
            (yyval.no_ast) = novo_no_operacao((yyvsp[-2].no_ast), (yyvsp[-1].ival), (yyvsp[0].no_ast));
        }
    }
#line 1822 "sintatico_novo.tab.c"
    break;

  case 62: /* op_aditivo: TOKEN_SOMA  */
#line 483 "sintatico_novo.y"
               { (yyval.ival) = TOKEN_SOMA; }
#line 1828 "sintatico_novo.tab.c"
    break;

  case 63: /* op_aditivo: TOKEN_SUBT  */
#line 484 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_SUBT; }
#line 1834 "sintatico_novo.tab.c"
    break;

  case 64: /* op_aditivo: TOKEN_OR  */
#line 485 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_OR; }
#line 1840 "sintatico_novo.tab.c"
    break;

  case 65: /* termo: fator  */
#line 489 "sintatico_novo.y"
          { (yyval.no_ast) = (yyvsp[0].no_ast); }
#line 1846 "sintatico_novo.tab.c"
    break;

  case 66: /* termo: termo op_multiplicativo fator  */
#line 491 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_operacao((yyvsp[-2].no_ast), (yyvsp[-1].ival), (yyvsp[0].no_ast));
    }
#line 1854 "sintatico_novo.tab.c"
    break;

  case 67: /* op_multiplicativo: TOKEN_MULT  */
#line 497 "sintatico_novo.y"
               { (yyval.ival) = TOKEN_MULT; }
#line 1860 "sintatico_novo.tab.c"
    break;

  case 68: /* op_multiplicativo: TOKEN_DIV  */
#line 498 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_DIV; }
#line 1866 "sintatico_novo.tab.c"
    break;

  case 69: /* op_multiplicativo: TOKEN_AND  */
#line 499 "sintatico_novo.y"
                 { (yyval.ival) = TOKEN_AND; }
#line 1872 "sintatico_novo.tab.c"
    break;

  case 70: /* fator: ID  */
#line 504 "sintatico_novo.y"
    {
        (yyval.no_ast) = novo_no_id((yyvsp[0].sval));
    }
#line 1880 "sintatico_novo.tab.c"
    break;

  case 71: /* fator: ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR  */
#line 509 "sintatico_novo.y"
    {
        Simbolo* s = buscar_simbolo((yyvsp[-3].sval));
        if (s == NULL) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Function '%s' nao declarada.\n", yylineno, (yyvsp[-3].sval));
            adicionar_erro_semantico(buffer);
        } else if (s->categoria != CATEGORIA_FUNCTION && s->categoria != CATEGORIA_PROCEDURE) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): '%s' nao e uma function ou procedure.\n", yylineno, (yyvsp[-3].sval));
            adicionar_erro_semantico(buffer);
        }
        (yyval.no_ast) = novo_no_chamada( novo_no_id((yyvsp[-3].sval)), (yyvsp[-1].no_ast) );
    }
#line 1898 "sintatico_novo.tab.c"
    break;

  case 72: /* fator: NUMERO  */
#line 522 "sintatico_novo.y"
             { (yyval.no_ast) = novo_no_num((yyvsp[0].sval)); }
#line 1904 "sintatico_novo.tab.c"
    break;

  case 74: /* fator: TOKEN_ABREPAR expressao TOKEN_FECHAPAR  */
#line 526 "sintatico_novo.y"
                                             { (yyval.no_ast) = (yyvsp[-1].no_ast); }
#line 1910 "sintatico_novo.tab.c"
    break;

  case 75: /* fator: TOKEN_NOT fator  */
#line 529 "sintatico_novo.y"
    {
        /* operação unária: nó de operação com filho esquerda NULL (ou o contrário) */
        (yyval.no_ast) = novo_no_operacao(NULL, TOKEN_NOT, (yyvsp[0].no_ast));
    }
#line 1919 "sintatico_novo.tab.c"
    break;

  case 76: /* fator: TOKEN_SUBT fator  */
#line 535 "sintatico_novo.y"
    {
        /* menos unário (ex: -5). tratar como operação unária */
        (yyval.no_ast) = novo_no_operacao(NULL, TOKEN_SUBT, (yyvsp[0].no_ast));
    }
#line 1928 "sintatico_novo.tab.c"
    break;

  case 77: /* logico: TOKEN_FALSE  */
#line 542 "sintatico_novo.y"
                { (yyval.no_ast) = novo_no_bool_literal("false"); }
#line 1934 "sintatico_novo.tab.c"
    break;

  case 78: /* logico: TOKEN_TRUE  */
#line 543 "sintatico_novo.y"
                 { (yyval.no_ast) = novo_no_bool_literal("true"); }
#line 1940 "sintatico_novo.tab.c"
    break;


#line 1944 "sintatico_novo.tab.c"

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

#line 546 "sintatico_novo.y"


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

        printf("Iniciei a analise lexica\n");

        while (yylex() != 0);

        int num_erros_lexicos = contar_erros_lexicos();
        printf("Obtive %d erros lexicos e foram:\n", num_erros_lexicos);
        if (num_erros_lexicos > 0) {
            exibir_erros_lexicos();
        }
        printf("Finalizei a analise lexica\n");

        if (num_erros_lexicos > 0) {
            limpar_erros_lexicos();
            fclose(yyin);
            return 1; /* Termina o programa com erro */
        }

        rewind(yyin);


        /* resetar o contador de linhas */
        yylineno = 1;

        printf("Iniciei a analise sintatica\n");
        inicializar_tipos_primitivos();
        yydebug = 0;

        int num_erros_sintaticos = contar_erros_sintaticos();
        printf("Obtive %d erros sintaticos e foram:\n", num_erros_sintaticos);
        if (num_erros_sintaticos > 0) {
            exibir_erros_sintaticos();
        }
        printf("Finalizei a analise sintatica\n");

        printf("Iniciei a analise semantica\n");
        int num_erros_semanticos = contar_erros_semanticos();
        printf("Obtive %d erros semanticos e foram:\n", num_erros_semanticos);
        if (num_erros_semanticos > 0) {
            exibir_erros_semanticos();
        }
        printf("Finalizei a analise semantica\n");

        if (savedTree != NULL) {
            printf("\n--- ARVORE SINTATICA ABSTRATA ---\n");
            imprimir_arvore(savedTree, 0);
            printf("---------------------------------\n");
        }

        // yyparse();

        fclose(yyin);


        return 0;
    }

    void yyerror(const char *s) {
        char buffer[512];
        snprintf(buffer, sizeof(buffer), "Erro Sintatico na linha %d: %s. Token inesperado: '%s'\n", yylineno, s, yytext);
        adicionar_erro_sintatico(buffer);
    }
