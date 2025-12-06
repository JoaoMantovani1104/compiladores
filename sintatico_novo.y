    %{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"

    /* declaração das funções do Bison */
    int yylex(); // função do analisador léxico (gerada pelo Flex)
    void yyerror(const char *s); // função de report de erros
    void inicializar_tipos_primitivos(); // inicializar tipos primitivos na tabela
    void inserir_simbolo_com_categoria(char *nome, char *tipo, CategoriaSimbolo categoria);
    void verificar_lista_identificadores_read(TreeNode* lista_ids);
    void verificar_lista_expressoes_write(TreeNode* lista_expr);
    void abrir_escopo(); // abrir um novo escopo
    void fechar_escopo(); // fechar o escopo atual
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
    %type <sval> declaracao_funcao_cabecalho
    %type <no_ast> secao_declaracao_subrotinas secao_declaracao_subrotinas_opcional
    %type <no_ast> parametros_formais parametros_formais_opcional
    %type <no_ast> declaracao_parametros_lista declaracao_parametros
    %type <ival> op_aditivo op_multiplicativo relacao /* retornam o token (int) */
    %type <no_ast> logico

    /* precedência de operadores - menos unário precisa ter precedência mais alta que binário */
    %right TOKEN_NOT  /* operador unário not */
    %left TOKEN_OR
    %left TOKEN_AND
    %left TOKEN_SOMA TOKEN_SUBT  
    %left TOKEN_MULT TOKEN_DIV   
    %nonassoc TOKEN_MENOR TOKEN_MENORIGUAL TOKEN_MAIOR TOKEN_MAIORIGUAL
    %nonassoc TOKEN_IGUAL TOKEN_DIF
    /* detalhe que o TOKEN_SUBT unário é tratado na regra fator: TOKEN_SUBT fator e tem precedência mais alta */

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
        /* juntar as variáveis locais ($1) com o corpo ($2) */
        $$ = novo_no_lista($1, $2);
        /* fechar escopo da subrotina ao finalizar o bloco */
        fechar_escopo();
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
        $$ = $1; /* caso base eh de uma subrotina */

    }
    | secao_declaracao_subrotinas declaracao_subrotina TOKEN_PONTOVIRG
    {
        /* lista de subrotinas */
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
        Simbolo* s = buscar_simbolo($2);
        if (s != NULL) {
            if (s->categoria == CATEGORIA_TYPE) {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Nao e possivel redeclarar o tipo primitivo '%s' como procedure.\n", yylineno, $2);
                adicionar_erro_semantico(buffer);
            } else {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Redeclaracao da procedure '%s'. Ela ja foi declarada anteriormente.\n", yylineno, $2);
                adicionar_erro_semantico(buffer);
            }
        } else {
            inserir_simbolo_com_categoria($2, "procedure", CATEGORIA_PROCEDURE);
        }
        
        $$ = novo_no_subrotina($2, $3, NULL, $5);
    }
    ;

declaracao_funcao:
    declaracao_funcao_cabecalho parametros_formais_opcional TOKEN_DOISP tipo TOKEN_PONTOVIRG bloco_subrot
    {
        
        $$ = novo_no_subrotina($1, $2, $4, $6);
        free($1); // Liberar string alocada em declaracao_funcao_cabecalho
    }
    ;

declaracao_funcao_cabecalho:
    TOKEN_FUNCTION ID
    {
        /* inserir function na tabela após ler o nome,
           antes de processar parâmetros e corpo */
        Simbolo* s = buscar_simbolo($2);
        if (s != NULL) {
            if (s->categoria == CATEGORIA_TYPE) {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Nao e possivel redeclarar o tipo primitivo '%s' como function.\n", yylineno, $2);
                adicionar_erro_semantico(buffer);
            } else if (s->categoria != CATEGORIA_FUNCTION) {
                char buffer[512];
                snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Redeclaracao da function '%s'. Ela ja foi declarada anteriormente.\n", yylineno, $2);
                adicionar_erro_semantico(buffer);
            }
        } else {
            inserir_simbolo_com_categoria($2, "function", CATEGORIA_FUNCTION);
        }
        $$ = strdup($2); // retornar nome da function como string
    }
    ;

parametros_formais_opcional:
    /* */ {
        /* se não há parâmetros, ainda abrir escopo para variáveis locais */
        abrir_escopo();
        $$ = NULL;
    }
    | parametros_formais {
        /* o escopo já foi aberto em parametros_formais quando houve o processamento dos parâmetros */
        $$ = $1;
    }
    ;

parametros_formais:
    TOKEN_ABREPAR declaracao_parametros_lista TOKEN_FECHAPAR
    {
        /* abrir escopo quando começar a processar parâmetros */
        abrir_escopo();
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
        /* processar parâmetros: permitir redeclaração entre diferentes subrotinas */
        processar_declaracao_params($1, $3);
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
        /* criação da lista encadeada de comandos */
        $$ = novo_no_lista($1, $3); 
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
        Simbolo *s = buscar_simbolo($1);
        TreeNode* no_id = novo_no_id($1);
        TreeNode* no_expr = $3;

        // é preciso verificar se é atribuição de retorno de função
        // se o símbolo não está na tabela, pode ser porque ainda não foi inserido, 
        // então verifica-se se é uma function verificando todas as functions declaradas
        int eh_function = 0;
        if (s != NULL && s->categoria == CATEGORIA_FUNCTION) {
            eh_function = 1;
        } else if (s == NULL) {
            
            eh_function = 0; 
        }

        if (s == NULL && !eh_function) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Variavel '%s' nao declarada.\n", yylineno, $1);
             adicionar_erro_semantico(buffer);
        } else if (s != NULL && s->categoria == CATEGORIA_FUNCTION) {
            // atribuição de retorno de função: permitir sem erro de não declaração
            // apenas permitir
        } else if (s != NULL && s->categoria != CATEGORIA_VARIABLE) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Tentativa de atribuir valor a '%s' que nao e uma variavel.\n", yylineno, $1);
            adicionar_erro_semantico(buffer);
        }

        // verificar tipos apenas se não for atribuição de retorno de função
        if (s != NULL && s->categoria != CATEGORIA_FUNCTION) {
            if (no_id->tipo_dado != EXP_ERRO && no_expr->tipo_dado != EXP_ERRO) {
                if (no_id->tipo_dado != no_expr->tipo_dado) {
                    char buffer[512];
                    snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Atribuicao invalida. Variavel '%s' eh do tipo %s, mas recebeu %s.\n",
                            yylineno, $1,
                            (no_id->tipo_dado == EXP_INTEGER ? "INTEGER" : "BOOLEAN"),
                            (no_expr->tipo_dado == EXP_INTEGER ? "INTEGER" : "BOOLEAN"));
                    adicionar_erro_semantico(buffer);
                }
            }
        }

        $$ = novo_no_atribuicao(no_id, no_expr);
    }
    ;

chamada_procedimento:
    ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR
    {
        Simbolo* s = buscar_simbolo($1);
        if (s == NULL) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Procedimento '%s' nao declarado.\n", yylineno, $1);
            adicionar_erro_semantico(buffer);
        } else if (s->categoria != CATEGORIA_PROCEDURE && s->categoria != CATEGORIA_FUNCTION) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): '%s' nao e uma procedure ou function.\n", yylineno, $1);
            adicionar_erro_semantico(buffer);
        }

        /* criar o nó */
        $$ = novo_no_chamada( novo_no_id($1), $3 );
    }
    ;

condicional:
    TOKEN_IF expressao TOKEN_THEN comando
    {
        if ($2->tipo_dado != EXP_BOOLEAN && $2->tipo_dado != EXP_ERRO) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): A condicao do 'IF' deve ser booleana.\n", yylineno);
             adicionar_erro_semantico(buffer);
        }

        $$ = novo_no_condicional($2, $4, NULL);
    }
    | TOKEN_IF expressao TOKEN_THEN comando TOKEN_ELSE comando
    {
        if ($2->tipo_dado != EXP_BOOLEAN && $2->tipo_dado != EXP_ERRO) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): A condicao do 'IF' deve ser booleana.\n", yylineno);
             adicionar_erro_semantico(buffer);
        }

        $$ = novo_no_condicional($2, $4, $6);
    }
    ;

repeticao:
    TOKEN_WHILE expressao TOKEN_DO comando
    {
        if ($2->tipo_dado != EXP_BOOLEAN && $2->tipo_dado != EXP_ERRO) {
             char buffer[512];
             snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): A condicao do 'WHILE' deve ser booleana.\n", yylineno);
             adicionar_erro_semantico(buffer);
        }
        $$ = novo_no_while($2, $4);
    }
    ;

leitura:
    TOKEN_READ TOKEN_ABREPAR lista_identificadores TOKEN_FECHAPAR
    {
        verificar_lista_identificadores_read($3);
        $$ = novo_no_io(TIPO_LEITURA, $3);
    }
    ;

escrita:
    TOKEN_WRITE TOKEN_ABREPAR lista_expressoes TOKEN_FECHAPAR
    {
        verificar_lista_expressoes_write($3);
        $$ = novo_no_io(TIPO_ESCRITA, $3);
    }
    ;

lista_expressoes:
    expressao { $$ = $1; }
    | lista_expressoes TOKEN_VIRG expressao
    {
        /* no caso recursivo, criar a lista encadeada */
        $$ = novo_no_lista($3, $1); 
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
        /* relacao retorna o TOKEN (int) */
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
        /* verificar se $1 é NULL (não deveria acontecer) */
        if ($1 == NULL) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Operando esquerdo invalido na expressao.\n", yylineno);
            adicionar_erro_semantico(buffer);
            $$ = $3; /* retornar o operando direito como fallback */
        } else {
            $$ = novo_no_operacao($1, $2, $3);
        }
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
        $$ = novo_no_id($1);
    }

    | ID TOKEN_ABREPAR lista_expressoes_opcional TOKEN_FECHAPAR /* chamada funcao */
    {
        Simbolo* s = buscar_simbolo($1);
        if (s == NULL) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): Function '%s' nao declarada.\n", yylineno, $1);
            adicionar_erro_semantico(buffer);
        } else if (s->categoria != CATEGORIA_FUNCTION && s->categoria != CATEGORIA_PROCEDURE) {
            char buffer[512];
            snprintf(buffer, sizeof(buffer), "ERRO SEMANTICO (Linha %d): '%s' nao e uma function ou procedure.\n", yylineno, $1);
            adicionar_erro_semantico(buffer);
        }
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
        /* menos unário (ex: -5) -> tratar como operação unária */
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

        printf("Iniciou-se a analise lexica\n");

        while (yylex() != 0);

        int num_erros_lexicos = contar_erros_lexicos();
        printf("Houveram %d erros lexicos e foram:\n", num_erros_lexicos);
        if (num_erros_lexicos > 0) {
            exibir_erros_lexicos();
        }
        printf("Finalizada a analise lexica\n");

        if (num_erros_lexicos > 0) {
            limpar_erros_lexicos();
            fclose(yyin);
            return 1; /* terminar o programa com erro */
        }

        rewind(yyin);


        /* resetar o contador de linhas */
        yylineno = 1;

        printf("Iniciou-se a analise sintatica\n");
        inicializar_tipos_primitivos();
        yydebug = 0;

        int num_erros_sintaticos = contar_erros_sintaticos();
        printf("Houveram %d erros sintaticos e foram:\n", num_erros_sintaticos);
        if (num_erros_sintaticos > 0) {
            exibir_erros_sintaticos();
        }
        printf("Finalizada a analise sintatica\n");

        printf("Iniciou-se a analise semantica\n");
        int num_erros_semanticos = contar_erros_semanticos();
        printf("Houveram %d erros semanticos e foram:\n", num_erros_semanticos);
        if (num_erros_semanticos > 0) {
            exibir_erros_semanticos();
        }
        printf("Finalizada a analise semantica\n");

        if (savedTree != NULL) {
            printf("\n --- ARVORE SINTATICA ABSTRATA ---\n");
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