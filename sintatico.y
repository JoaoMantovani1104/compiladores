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

    %start root

    %%

    root:
        TOKEN_PROGRAM ID TOKEN_PONTOVIRG
        resto
        ;

    resto:
        declaracao_variaveis
        declaracao_subprogramas
        comando_begin_geral
        ;

    declaracao_variaveis:
        /* */
        | TOKEN_VAR lista_variaveis
        ;

    lista_variaveis:
        quantidade_variaveis TOKEN_DOISP tipo TOKEN_PONTOVIRG
        outro_tipo_variaveis  
        ;

    outro_tipo_variaveis:
        /* */
        | quantidade_variaveis TOKEN_DOISP tipo TOKEN_PONTOVIRG
        outro_tipo_variaveis
        ;

    tipo:
        TOKEN_INTEGER
        | TOKEN_BOOLEAN
        ;

    declaracao_subprogramas:
        /*  */
        | TOKEN_FUNCTION resto_funcao retorno_funcao TOKEN_PONTOVIRG 
        declaracao_variaveis
        comando_begin TOKEN_PONTOVIRG
        | TOKEN_PROCEDURE resto_funcao retorno_funcao TOKEN_PONTOVIRG 
        declaracao_variaveis
        comando_begin TOKEN_PONTOVIRG
        ;

    resto_funcao:
        ID TOKEN_ABREPAR quantidade_variaveis TOKEN_DOISP tipo TOKEN_FECHAPAR
        ;

    retorno_funcao:
        /* */
        | TOKEN_DOISP tipo
        ;

    comando_begin_geral:
        TOKEN_BEGIN corpo TOKEN_END TOKEN_PONTO
        | TOKEN_BEGIN corpo TOKEN_PONTOVIRG TOKEN_END TOKEN_PONTO
        ;

    comando_begin:
        TOKEN_BEGIN corpo TOKEN_END
        | TOKEN_BEGIN corpo TOKEN_PONTOVIRG TOKEN_END
        ;

    corpo:
        /* */
        | funcao mais_corpo
        | expressao mais_corpo
        | condicional mais_corpo 
        | loop mais_corpo
        | comando_begin mais_corpo

    mais_corpo:
        /* */
        | TOKEN_PONTOVIRG funcao mais_corpo
        | TOKEN_PONTOVIRG expressao mais_corpo
        | TOKEN_PONTOVIRG condicional mais_corpo 
        | TOKEN_PONTOVIRG loop mais_corpo
        | TOKEN_PONTOVIRG comando_begin mais_corpo



    funcao:
        TOKEN_READ TOKEN_ABREPAR quantidade_variaveis TOKEN_FECHAPAR
        | TOKEN_WRITE TOKEN_ABREPAR quantidade_itens_escrita TOKEN_FECHAPAR
        | termo TOKEN_ABREPAR lista_parametros TOKEN_FECHAPAR  
        ;

    quantidade_variaveis:
        ID mais_variaveis
        ;

    quantidade_itens_escrita:
        ID mais_itens_escrita
        | NUMERO mais_itens_escrita
        ;

    mais_itens_escrita:
        /* */
        | TOKEN_VIRG ID mais_itens_escrita
        | TOKEN_VIRG NUMERO mais_itens_escrita
        ;

    mais_variaveis:
        /* */
        | TOKEN_VIRG ID mais_variaveis
        ;

    expressao:
        ID TOKEN_ATRIB calculo
        | ID TOKEN_ATRIB expressao_condicional
        ;

    termo:
        TOKEN_ABREPAR calculo TOKEN_FECHAPAR  
        | ID
        | NUMERO
        | TOKEN_SUBT ID
        | TOKEN_SOMA ID
        | ID TOKEN_ABREPAR lista_parametros TOKEN_FECHAPAR  
        ;

    lista_parametros:
        /* */
        | ID resto_parametros
        ;

    resto_parametros:
        /* */
        | TOKEN_VIRG ID resto_parametros
        ;

    calculo:
        termo seq_calculo 
        ;

    seq_calculo:
        /* */
        | operador termo seq_calculo 
        ;
    operador:
        TOKEN_SOMA
        | TOKEN_SUBT
        | TOKEN_MULT
        | TOKEN_DIV
        ;

    /*
    resto_calculo:
        ID seq_calculo
        | NUMERO seq_calculo
        ;
    */

    condicional: 
        TOKEN_IF expressao_condicional TOKEN_THEN
        comando_begin mais_corpo
        | TOKEN_IF expressao_condicional TOKEN_THEN
        comando_begin mais_corpo
        TOKEN_ELSE comando_begin mais_corpo
        ;
        

    expressao_condicional:
        termo comparacao termo mais_comparacoes
    
        | TOKEN_ABREPAR expressao_condicional TOKEN_FECHAPAR mais_comparacoes
    
    
        | TOKEN_NOT TOKEN_ABREPAR expressao_condicional TOKEN_FECHAPAR mais_comparacoes
    
    
        | TOKEN_TRUE mais_comparacoes
        | TOKEN_FALSE mais_comparacoes
        ;

    comparacao:
        TOKEN_DIF
        | TOKEN_MAIOR
        | TOKEN_MAIORIGUAL
        | TOKEN_MENOR
        | TOKEN_MENORIGUAL
        | TOKEN_IGUAL
        ;

    /*valor:
        ID
        | NUMERO
        ;
    */

    mais_comparacoes:
        /* */
        | TOKEN_AND expressao_condicional
        | TOKEN_AND TOKEN_NOT expressao_condicional
        | TOKEN_OR expressao_condicional
        | TOKEN_OR TOKEN_NOT expressao_condicional
        ;

    loop:
        TOKEN_WHILE calculo comparacao calculo TOKEN_DO
        comando_begin mais_corpo

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