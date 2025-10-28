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
    extern int yydebug; 
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

    %debug 

    %start programa

    %%

programa:
    TOKEN_PROGRAM ID TOKEN_PONTOVIRG bloco TOKEN_PONTO
    ;

bloco:
    secao_declaracao_variaveis_opcional
    secao_declaracao_subrotinas_opcional
    comando_composto
    ;

bloco_subrot:   
    secao_declaracao_variaveis_opcional
    comando_composto
    ;

secao_declaracao_variaveis_opcional:
    /* */
    | secao_declaracao_variaveis
    ;

secao_declaracao_subrotinas_opcional:
    /* */
    | secao_declaracao_subrotinas
    ;

secao_declaracao_variaveis:
    TOKEN_VAR declaracao_variaveis TOKEN_PONTOVIRG lista_declaracao_variaveis_opcional
    ;

lista_declaracao_variaveis_opcional:
    /* */
    | lista_declaracao_variaveis_opcional declaracao_variaveis TOKEN_PONTOVIRG
    ;

declaracao_variaveis:
    lista_identificadores TOKEN_DOISP tipo
    ;

lista_identificadores:
    ID lista_identificadores_resto_opcional
    ;

lista_identificadores_resto_opcional:
    /* */
    | lista_identificadores_resto_opcional TOKEN_VIRG ID
    ;

tipo:
    TOKEN_BOOLEAN
    | TOKEN_INTEGER
    ;

secao_declaracao_subrotinas:
    /* */
    | secao_declaracao_subrotinas declaracao_subrotina TOKEN_PONTOVIRG
    ;

declaracao_subrotina:
    declaracao_procedimento
    | declaracao_funcao
    ;

declaracao_procedimento:
    TOKEN_PROCEDURE ID parametros_formais_opcional TOKEN_PONTOVIRG bloco_subrot
    ;

declaracao_funcao:
    TOKEN_FUNCTION ID parametros_formais_opcional TOKEN_DOISP tipo TOKEN_PONTOVIRG bloco_subrot
    ;

parametros_formais_opcional:
    /* */
    | parametros_formais
    ;

parametros_formais:
    TOKEN_ABREPAR declaracao_parametros_lista TOKEN_FECHAPAR
    ;

declaracao_parametros_lista:
    declaracao_parametros
    | declaracao_parametros_lista TOKEN_PONTOVIRG declaracao_parametros
    ;

declaracao_parametros:
    lista_identificadores TOKEN_DOISP tipo
    ;

comando_composto:
    TOKEN_BEGIN comando_lista TOKEN_END
    ;

comando_lista:
    comando
    | comando_lista TOKEN_PONTOVIRG comando
    ;

comando:
    atribuicao
    | chamada_procedimento
    | condicional
    | repeticao
    | leitura
    | escrita
    | comando_composto
    ;

atribuicao:
    ID TOKEN_ATRIB expressao
    ;

chamada_procedimento:
    ID
    | ID TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR
    ;

condicional:
    TOKEN_IF expressao TOKEN_THEN comando
    | TOKEN_IF expressao TOKEN_THEN comando TOKEN_ELSE comando
    ;

repeticao:
    TOKEN_WHILE expressao TOKEN_DO comando
    ;

leitura:
    TOKEN_READ TOKEN_ABREPAR lista_identificadores TOKEN_FECHAPAR
    ;

escrita:
    TOKEN_WRITE TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR
    ;

lista_expressoes:
    expressao
    | lista_expressoes TOKEN_VIRG expressao
    ;

expressao:
    expressao_simples
    | expressao_simples relacao expressao_simples
    ;

relacao:
    TOKEN_IGUAL
    | TOKEN_DIF
    | TOKEN_MENOR
    | TOKEN_MENORIGUAL
    | TOKEN_MAIOR
    | TOKEN_MAIORIGUAL
    ;

expressao_simples:
    termo
    | expressao_simples op_aditivo termo
    ;

op_aditivo:
    TOKEN_SOMA
    | TOKEN_SUBT
    | TOKEN_OR
    ;

termo:
    fator
    | termo op_multiplicativo fator
    ;

op_multiplicativo:
    TOKEN_MULT
    | TOKEN_DIV
    | TOKEN_AND
    ;

fator:
    ID
    | ID TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR

    | NUMERO

    | logico
    
    | TOKEN_ABREPAR expressao TOKEN_FECHAPAR
    
    | TOKEN_NOT fator
    
    | TOKEN_SUBT fator
    ;

logico:
    TOKEN_FALSE
    | TOKEN_TRUE
    ;

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