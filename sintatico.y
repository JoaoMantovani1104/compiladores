%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaração das funções que o Bison precisará */
int yylex(); // A função do analisador léxico (gerada pelo Flex)
void yyerror(const char *s); // A função para reportar erros
%}

%union {
    char *sval; 
    int ival;  
}

%token TOKEN_PROGRAM TOKEN_VAR TOKEN_PROCEDURE TOKEN_FUNCTION TOKEN_BEGIN TOKEN_END
%token TOKEN_FALSE TOKEN_TRUE TOKEN_IF TOKEN_THEN TOKEN_ELSE TOKEN_WHILE TOKEN_DO TOKEN_READ TOKEN_WRITE
%token TOKEN_AND TOKEN_OR TOKEN_NOT TOKEN_DIV TOKEN_INTEGER TOKEN_BOOLEAN
%token TOKEN_SOMA TOKEN_SUBT TOKEN_MULT TOKEN_IGUAL TOKEN_FECHAPAR TOKEN_ABREPAR TOKEN_PONTOVIRG TOKEN_VIRG TOKEN_PONTO
%token TOKEN_DIF TOKEN_MAIOR TOKEN_MENOR TOKEN_MAIORIGUAL TOKEN_MENORIGUAL TOKEN_ATRIB TOKEN_DOISP

%token <sval> ID
%token <sval> NUMERO

%start root

%%

root:
    TOKEN_PROGRAM ID TOKEN_PONTOVIRG
    resto

resto:
    declaracao_variaveis
    declaracao_subprogramas
    comando_composto

declaracao_variaveis:
    /* */
    | TOKEN_VAR lista_variaveis
    ;

lista_variaveis:
    ID TOKEN_DOISP tipo TOKEN_PONTOVIRG
    | lista_variaveis ID TOKEN_DOISP tipo TOKEN_PONTOVIRG
    ;

tipo:
    TOKEN_INTEGER
    | TOKEN_BOOLEAN
    ;

declaracao_subprogramas:
/* adicionar procedures e functions */

comando_composto:
    TOKEN_BEGIN corpo TOKEN_END TOKEN_PONTOVIRG
    ;
