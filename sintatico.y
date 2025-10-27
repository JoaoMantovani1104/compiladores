%{
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
    ;

resto:
    declaracao_variaveis
    declaracao_subprogramas
    comando_composto
    ;

declaracao_variaveis:
    /* */
    | TOKEN_VAR lista_variaveis
    ;

lista_variaveis:
    ID quantidade_variaveis TOKEN_DOISP tipo TOKEN_PONTOVIRG
    lista_variaveis 
    ;

tipo:
    TOKEN_INTEGER
    | TOKEN_BOOLEAN
    ;

declaracao_subprogramas:
/* adicionar procedures e functions */

comando_composto:
    TOKEN_BEGIN corpo TOKEN_END TOKEN_PONTO
    ;

corpo:
    /* */
    | funcao corpo
    | expressao corpo
    | condicional corpo 
    | loop corpo
    | begin_escopo corpo

funcao:
    TOKEN_READ TOKEN_ABREPAR quantidade_variaveis TOKEN_FECHAPAR
    | TOKEN_WRITE TOKEN_ABREPAR quantidade_variaveis TOKEN_FECHAPAR
    ;

quantidade_variaveis:
    ID mais_variaveis
    ;

mais_variaveis:
    /* */
    TOKEN_VIRG ID mais_variaveis
    ;

expressao:
    ID TOKEN_ATRIB calculo TOKEN_PONTOVIRG
    ;

calculo:
    TOKEN_ABREPAR calculo TOKEN_FECHAPAR
    | ID seq_calculo 
    | NUMERO seq_calculo
    ;

seq_calculo:
    /* */
    | operador resto_calculo
    ;

operador:
    TOKEN_SOMA
    | TOKEN_SUBT
    | TOKEN_MULT
    | TOKEN_DIV
    ;

resto_calculo:

condicional: 
    TOKEN_IF expressao_condicional TOKEN_THEN
    ;
    

expressao_condicional:
    valor comparacao valor mais_comparacoes
    ;

comparacao:

valor:
    ID
    | NUMERO
    ;

mais_comparacoes:
    /* */
    TOKEN_AND expressao_condicional
    | TOKEN_OR expressao_condicional
    ;

loop:

begin_escopo:

%%


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
    
    
    yyparse(); 
    
    fclose(yyin);
    
    
    return 0;
}

void yyerror(const char *s) {

    fprintf(stderr, "\nErro Sintático na linha %d: %s\n", yylineno, s);

    fprintf(stderr, "    Token inesperado: '%s'\n", yytext);
}