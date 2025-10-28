/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_PROGRAM = 258,           /* TOKEN_PROGRAM  */
    TOKEN_VAR = 259,               /* TOKEN_VAR  */
    TOKEN_PROCEDURE = 260,         /* TOKEN_PROCEDURE  */
    TOKEN_FUNCTION = 261,          /* TOKEN_FUNCTION  */
    TOKEN_BEGIN = 262,             /* TOKEN_BEGIN  */
    TOKEN_END = 263,               /* TOKEN_END  */
    TOKEN_FALSE = 264,             /* TOKEN_FALSE  */
    TOKEN_TRUE = 265,              /* TOKEN_TRUE  */
    TOKEN_IF = 266,                /* TOKEN_IF  */
    TOKEN_THEN = 267,              /* TOKEN_THEN  */
    TOKEN_ELSE = 268,              /* TOKEN_ELSE  */
    TOKEN_WHILE = 269,             /* TOKEN_WHILE  */
    TOKEN_DO = 270,                /* TOKEN_DO  */
    TOKEN_READ = 271,              /* TOKEN_READ  */
    TOKEN_WRITE = 272,             /* TOKEN_WRITE  */
    TOKEN_AND = 273,               /* TOKEN_AND  */
    TOKEN_OR = 274,                /* TOKEN_OR  */
    TOKEN_NOT = 275,               /* TOKEN_NOT  */
    TOKEN_DIV = 276,               /* TOKEN_DIV  */
    TOKEN_INTEGER = 277,           /* TOKEN_INTEGER  */
    TOKEN_BOOLEAN = 278,           /* TOKEN_BOOLEAN  */
    TOKEN_SOMA = 279,              /* TOKEN_SOMA  */
    TOKEN_SUBT = 280,              /* TOKEN_SUBT  */
    TOKEN_MULT = 281,              /* TOKEN_MULT  */
    TOKEN_IGUAL = 282,             /* TOKEN_IGUAL  */
    TOKEN_FECHAPAR = 283,          /* TOKEN_FECHAPAR  */
    TOKEN_ABREPAR = 284,           /* TOKEN_ABREPAR  */
    TOKEN_PONTOVIRG = 285,         /* TOKEN_PONTOVIRG  */
    TOKEN_VIRG = 286,              /* TOKEN_VIRG  */
    TOKEN_PONTO = 287,             /* TOKEN_PONTO  */
    TOKEN_DIF = 288,               /* TOKEN_DIF  */
    TOKEN_MAIOR = 289,             /* TOKEN_MAIOR  */
    TOKEN_MENOR = 290,             /* TOKEN_MENOR  */
    TOKEN_MAIORIGUAL = 291,        /* TOKEN_MAIORIGUAL  */
    TOKEN_MENORIGUAL = 292,        /* TOKEN_MENORIGUAL  */
    TOKEN_ATRIB = 293,             /* TOKEN_ATRIB  */
    TOKEN_DOISP = 294,             /* TOKEN_DOISP  */
    ID = 295,                      /* ID  */
    NUMERO = 296                   /* NUMERO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "sintatico.y"

        char *sval; 
        int ival;  
    

#line 111 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
