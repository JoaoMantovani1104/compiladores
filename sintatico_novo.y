    %{
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
    %}

    %union {
        char *sval; 
        int ival;  
        struct TreeNode *no_ast;
    }

    %token TOKEN_PROGRAM TOKEN_VAR TOKEN_PROCEDURE TOKEN_FUNCTION TOKEN_BEGIN TOKEN_END
    %token TOKEN_FALSE TOKEN_TRUE TOKEN_IF TOKEN_THEN TOKEN_ELSE TOKEN_WHILE TOKEN_DO TOKEN_READ TOKEN_WRITE
    %token TOKEN_AND TOKEN_OR TOKEN_NOT TOKEN_DIV TOKEN_INTEGER TOKEN_BOOLEAN
    %token TOKEN_SOMA TOKEN_SUBT TOKEN_MULT TOKEN_IGUAL TOKEN_FECHAPAR TOKEN_ABREPAR TOKEN_PONTOVIRG TOKEN_VIRG TOKEN_PONTO
    %token TOKEN_DIF TOKEN_MAIOR TOKEN_MENOR TOKEN_MAIORIGUAL TOKEN_MENORIGUAL TOKEN_ATRIB TOKEN_DOISP

    %token <sval> ID
    %token <sval> NUMERO
    %type <sval> tipo
    %type <no_ast> programa bloco bloco_subrot
    %type <no_ast> secao_declaracao_variaveis_opcional secao_declaracao_variaveis lista_declaracao_variaveis_opcional declaracao_variaveis
    %type <no_ast> lista_identificadores lista_identificadores_resto_opcional
    %type <no_ast> comando_composto comando_lista comando
    %type <no_ast> atribuicao condicional repeticao leitura escrita chamada_procedimento
    %type <no_ast> expressao expressao_simples termo fator
    %type <no_ast> lista_expressoes lista_expressoes_opcional
    %type <no_ast> declaracao_subrotina declaracao_procedimento declaracao_funcao
    %type <no_ast> secao_declaracao_subrotinas secao_declaracao_subrotinas_opcional
    %type <no_ast> parametros_formais parametros_formais_opcional
    %type <no_ast> declaracao_parametros_lista declaracao_parametros
    %type <ival> op_aditivo op_multiplicativo relacao /* Retornam o token (int) */
    %type <no_ast> logico

    %debug 

    %start programa

    %%

programa:
    TOKEN_PROGRAM ID TOKEN_PONTOVIRG bloco TOKEN_PONTO
    {
        $$ = novo_no_programa($2, $4);
        savedTree = $$;
    }
    ;

bloco:
    secao_declaracao_variaveis_opcional
    secao_declaracao_subrotinas_opcional
    comando_composto
    {
        TreeNode* decls = novo_no_lista($1, $2);
        $$ = novo_no_lista(decls, $3);
    }
    ;

bloco_subrot:   
    secao_declaracao_variaveis_opcional
    comando_composto
    {
        /* Junta as variáveis locais ($1) com o corpo ($2) */
        $$ = novo_no_lista($1, $2);
    }
    ;

secao_declaracao_variaveis_opcional:
    /* */ { $$ = NULL; }
    | secao_declaracao_variaveis { $$ = $1; }
    ;

secao_declaracao_subrotinas_opcional:
    /* */ { $$ = NULL; }
    | secao_declaracao_subrotinas { $$ = $1; }
    ;

secao_declaracao_variaveis:
    TOKEN_VAR declaracao_variaveis TOKEN_PONTOVIRG lista_declaracao_variaveis_opcional
    {
        $$ = novo_no_lista($2, $4);
    }
    ;

lista_declaracao_variaveis_opcional:
    /* */ { $$ = NULL; }
    | lista_declaracao_variaveis_opcional declaracao_variaveis TOKEN_PONTOVIRG
    {
        /* recursão à esquerda para criar lista */
        $$ = novo_no_lista($2, $1);
    }
    ;

declaracao_variaveis:
    lista_identificadores TOKEN_DOISP tipo
    {
        processar_declaracao_vars($1, $3);  /* enviar IDs e tipo */
        $$ = $1; /* retonar os ids para visualização*/
    }
    ;

lista_identificadores:
    ID lista_identificadores_resto_opcional
    {
        TreeNode* no_id = novo_no_id($1);
        if ($2 == NULL) {
            $$ = no_id;
        } else {
            $$ = novo_no_lista(no_id, $2);
        }
    }
    ;

lista_identificadores_resto_opcional:
    /* */ {$$ = NULL;}
    | lista_identificadores_resto_opcional TOKEN_VIRG ID
    {
        TreeNode* no_id = novo_no_id($3);
        $$ = novo_no_lista(no_id, $1);
    }
    ;

tipo:
    TOKEN_BOOLEAN { $$ = strdup("boolean"); }
    | TOKEN_INTEGER { $$ = strdup("integer"); }
    ;

secao_declaracao_subrotinas:
    declaracao_subrotina TOKEN_PONTOVIRG 
    { 
        $$ = $1; /* Caso base: uma subrotina */
            
    }
    | secao_declaracao_subrotinas declaracao_subrotina TOKEN_PONTOVIRG
    {
        /* Lista de subrotinas */
        $$ = novo_no_lista($2, $1);
    }
    ;
declaracao_subrotina:
    declaracao_procedimento
    | declaracao_funcao
    ;

declaracao_procedimento:
    TOKEN_PROCEDURE ID parametros_formais_opcional TOKEN_PONTOVIRG bloco_subrot
    {
        inserir_simbolo($2, "procedure");
        /* nas procedure não tem tipo de retorno (NULL) e o corpo é $5 */
        $$ = novo_no_subrotina($2, $3, NULL, $5);
    }
    ;

declaracao_funcao:
    TOKEN_FUNCTION ID parametros_formais_opcional TOKEN_DOISP tipo TOKEN_PONTOVIRG bloco_subrot
    {
        inserir_simbolo($2, "function");
        /* function tem seu tipo ($5) e o corpo é $7 */
        $$ = novo_no_subrotina($2, $3, $5, $7);
    }
    ;

parametros_formais_opcional:
    /* */ { $$ = NULL; }
    | parametros_formais { $$ = $1; }
    ;

parametros_formais:
    TOKEN_ABREPAR declaracao_parametros_lista TOKEN_FECHAPAR
    {
        $$ = $2; /* passar a lista que foi criada */
    }
    ;

declaracao_parametros_lista:
    declaracao_parametros { $$ = $1; }
    | declaracao_parametros_lista TOKEN_PONTOVIRG declaracao_parametros
    {
        /* nova lista de declarações de parâmetros */
        $$ = novo_no_lista($3, $1);
    }
    ;

declaracao_parametros:
    lista_identificadores TOKEN_DOISP tipo
    {
        /* mesma lógica de variáveis: processa o tipo e retorna a lista de IDs */
        processar_declaracao_vars($1, $3); 
        $$ = $1; 
    }
    ;

comando_composto:
    TOKEN_BEGIN comando_lista TOKEN_END
    {
        $$ = $2; /* o valor é a própria lista de comandos */
    }
    ;

comando_lista:
    comando { $$ = $1; }
    | comando_lista TOKEN_PONTOVIRG comando
    {
        /* criar a  lista encadeada de comandos */
        $$ = novo_no_lista($1, $3); // Atenção: pode precisar ajustar a ordem dependendo da sua função lista
    }
    ;

comando:
    atribuicao { $$ = $1; }
    | chamada_procedimento { $$ = $1; }
    | condicional { $$ = $1; }
    | repeticao { $$ = $1; }
    | leitura { $$ = $1; }
    | escrita { $$ = $1; }
    | comando_composto { $$ = $1; }
    ;

atribuicao:
    ID TOKEN_ATRIB expressao
    {
        if (buscar_simbolo($1) == NULL) {
             printf("Erro semântico: Variavel '%s' nao declarada.\n", $1);
             // exit(1); ou yyerror
        }
        $$ = novo_no_atribuicao(novo_no_id($1), $3);
    }
    ;

chamada_procedimento:
    ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR
    {
        /* verificar se foi declarado */
        if (buscar_simbolo($1) == NULL) printf("Erro: Procedimento '%s' nao declarado\n", $1);
        
        /* criar o nó */
        $$ = novo_no_chamada( novo_no_id($1), $3 );
    }
    ;

condicional:
    TOKEN_IF expressao TOKEN_THEN comando
    {
        $$ = novo_no_condicional($2, $4, NULL);
    }
    | TOKEN_IF expressao TOKEN_THEN comando TOKEN_ELSE comando
    {
        $$ = novo_no_condicional($2, $4, $6);
    }
    ;

repeticao:
    TOKEN_WHILE expressao TOKEN_DO comando
    {
        $$ = novo_no_while($2, $4);
    }
    ;

leitura:
    TOKEN_READ TOKEN_ABREPAR lista_identificadores TOKEN_FECHAPAR
    {
        $$ = novo_no_io(TIPO_LEITURA, $3);
    }
    ;

escrita:
    TOKEN_WRITE TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR
    {
        $$ = novo_no_io(TIPO_ESCRITA, $3);
    }
    ;

lista_expressoes:
    expressao { $$ = $1; }
    | lista_expressoes TOKEN_VIRG expressao
    {
        /* no caso recursivo, cria a lista encadeada */
        $$ = novo_no_lista($3, $1); // Ou ($1, $3) dependendo da ordem que preferir
    }
    ;

lista_expressoes_opcional:
    /* */ { $$ = NULL; }
    | lista_expressoes { $$ = $1; }
    ;

expressao:
    expressao_simples { $$ = $1; }
    | expressao_simples relacao expressao_simples
    {
        /* relacao retorna o TOKEN (int) usa novo_no_operacao */
        $$ = novo_no_operacao($1, $2, $3); 
    }
    ;

relacao:
    TOKEN_IGUAL { $$ = TOKEN_IGUAL; }
    | TOKEN_DIF { $$ = TOKEN_DIF; }
    | TOKEN_MENOR { $$ = TOKEN_MENOR; }
    | TOKEN_MENORIGUAL {$$ = TOKEN_MENORIGUAL;}
    | TOKEN_MAIOR {$$ = TOKEN_MAIOR;}
    | TOKEN_MAIORIGUAL {$$ = TOKEN_MAIORIGUAL;}
    ;

expressao_simples:
    termo { $$ = $1; }
    | expressao_simples op_aditivo termo
    {
        $$ = novo_no_operacao($1, $2, $3);
    }
    ;

op_aditivo:
    TOKEN_SOMA { $$ = TOKEN_SOMA; }
    | TOKEN_SUBT { $$ = TOKEN_SUBT; }
    | TOKEN_OR   { $$ = TOKEN_OR; }
    ;

termo:
    fator { $$ = $1; }
    | termo op_multiplicativo fator
    {
        $$ = novo_no_operacao($1, $2, $3);
    }
    ;

op_multiplicativo:
    TOKEN_MULT { $$ = TOKEN_MULT; }
    | TOKEN_DIV  { $$ = TOKEN_DIV; }
    | TOKEN_AND  { $$ = TOKEN_AND; }
    ;

fator:
    ID 
    { 
        if(buscar_simbolo($1) == NULL) printf("Erro: "%s" nao declarado\n", $1);
        $$ = novo_no_id($1); 
    }

    | ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR /* chamada funcao */
    {
        if (buscar_simbolo($1) == NULL) printf("Erro: Func '%s' nao declarada\n", $1);
        $$ = novo_no_chamada( novo_no_id($1), $3 );
    }
    | NUMERO { $$ = novo_no_num($1); }

    | logico
    
    | TOKEN_ABREPAR expressao TOKEN_FECHAPAR { $$ = $2; }
    
    | TOKEN_NOT fator
    {
        /* operação unária: nó de operação com filho esquerda NULL (ou o contrário) */
        $$ = novo_no_operacao(NULL, TOKEN_NOT, $2);
    }
    
    | TOKEN_SUBT fator
    {
        /* menos unário (ex: -5). tratar como operação unária */
        $$ = novo_no_operacao(NULL, TOKEN_SUBT, $2);
    }
    ;

logico:
    TOKEN_FALSE { $$ = novo_no_bool_literal("false"); }
    | TOKEN_TRUE { $$ = novo_no_bool_literal("true"); }
    ;

%%

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