#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "sintatico_novo.tab.h"

TreeNode* novo_no_id(char *nome_id) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");
    
    no->tipo = TIPO_ID;
    no->valor_s = strdup(nome_id);
    no->operacao = 0; 

    Simbolo* s = buscar_simbolo(nome_id);
    if (s != NULL) {
        no->tipo_dado = string_para_tipo(s->tipo); /* Pega o tipo da tabela! */
    } else {
        no->tipo_dado = EXP_ERRO;
    }
    

    for (int i = 0; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }
    
    return no;
}


TreeNode* novo_no_atribuicao(TreeNode* no_variavel, TreeNode* no_expressao) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");
    
    no->tipo = TIPO_ATRIBUICAO;
    no->valor_s = NULL; 
    no->operacao = 0;

    
    no->filho[0] = no_variavel;   
    no->filho[1] = no_expressao; 
    
    
    for (int i = 2; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }
    
    return no;
}

TreeNode* novo_no_num(char *val) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");
    
    no->tipo = TIPO_NUMERO;
    no->tipo_dado = EXP_INTEGER; 
    no->valor_s = strdup(val);
    no->operacao = 0; 
    for (int i = 0; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }
    
    return no;
}

TreeNode* novo_no_operacao(TreeNode* esq, int op, TreeNode* dir) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");
    
    no->tipo = TIPO_OPERACAO; 
    no->operacao = op; 
    no->valor_s = NULL;
    no->filho[0] = esq;
    no->filho[1] = dir;
    for (int i = 2; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }

    if (esq != NULL) {
        if (esq->tipo_dado == EXP_VOID) {
            printf("ERRO SEMANTICO: Tentativa de usar uma PROCEDURE (sem retorno) em uma expressao.\n");
            no->tipo_dado = EXP_ERRO;
            return no;
        }
    }

    if (dir != NULL) {
        if (dir->tipo_dado == EXP_VOID) {
             printf("ERRO SEMANTICO: Tentativa de usar uma PROCEDURE (sem retorno) em uma expressao.\n");
             no->tipo_dado = EXP_ERRO;
             return no;
        }
    }

    if (op == TOKEN_SOMA || op == TOKEN_SUBT || op == TOKEN_MULT || op == TOKEN_DIV) {
        
        no->tipo_dado = EXP_INTEGER; 
    } 
    else {
        
        no->tipo_dado = EXP_BOOLEAN;
    }
    

    return no;
}

TreeNode* novo_no_lista(TreeNode* no, TreeNode* proximo) {
    TreeNode *n = (TreeNode*) malloc(sizeof(TreeNode));
    if (n == NULL) yyerror("Out of memory");

    n->tipo = TIPO_LISTA;
    n->valor_s = NULL;
    n->operacao = 0;

    n->filho[0] = no;       
    n->filho[1] = proximo;  

    
    for (int i = 2; i < MAXCHILDREN; i++) {
        n->filho[i] = NULL;
    }
    return n;
}

TreeNode* novo_no_condicional(TreeNode* cond, TreeNode* then_bloco, TreeNode* else_bloco) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");
    
    no->tipo = TIPO_CONDICIONAL; 
    no->valor_s = NULL;
    no->operacao = 0;
    
    
    no->filho[0] = cond;       
    no->filho[1] = then_bloco; 
    no->filho[2] = else_bloco; 
    
    
    for (int i = 3; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }
    
    return no;
}

TreeNode* novo_no_while(TreeNode* condicao, TreeNode* corpo) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    no->tipo = TIPO_WHILE;
    no->valor_s = NULL;
    no->operacao = 0;
    
    no->filho[0] = condicao;
    no->filho[1] = corpo;
    
    for (int i = 2; i < MAXCHILDREN; i++) no->filho[i] = NULL;
    return no;
}


TreeNode* novo_no_programa(char* nome_prog, TreeNode* corpo) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    no->tipo = TIPO_PROGRAMA;
    no->valor_s = strdup(nome_prog);
    no->operacao = 0;
    
    no->filho[0] = corpo; 
    
    for (int i = 1; i < MAXCHILDREN; i++) no->filho[i] = NULL;
    return no;
}

TreeNode* novo_no_chamada(TreeNode* id, TreeNode* args) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    no->tipo = TIPO_CHAMADA;
    no->valor_s = NULL;
    no->operacao = 0;
    no->filho[0] = id;   
    no->filho[1] = args; 

    Simbolo* s = buscar_simbolo(id->valor_s);
    if (s != NULL) {
        if (strcmp(s->tipo, "procedure") == 0) {
            no->tipo_dado = EXP_VOID; /* Procedures não retornam valor, colocar void para verificar erros.*/
        } 
        else if (strcmp(s->tipo, "function") == 0) {
            
            no->tipo_dado = EXP_INTEGER; 
        }
        else {
             /* Se tentar chamar uma variável comum como função */
             no->tipo_dado = EXP_ERRO; 
        }
    } else {
        no->tipo_dado = EXP_ERRO;
    }

    for(int i=2; i<MAXCHILDREN; i++) no->filho[i] = NULL;
    return no;
}

TreeNode* novo_no_io(TipoNo tipo, TreeNode* args) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    no->tipo = tipo; // TIPO_LEITURA ou TIPO_ESCRITA
    no->valor_s = NULL;
    no->operacao = 0;
    no->filho[0] = args;
    for(int i=1; i<MAXCHILDREN; i++) no->filho[i] = NULL;
    return no;
}

TreeNode* novo_no_subrotina(char* nome, TreeNode* params, char* tipo_retorno, TreeNode* corpo) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    no->tipo = TIPO_SUBROTINA;
    no->valor_s = strdup(nome);
    
    no->filho[0] = params;
    no->filho[1] = corpo;
    
    
    if (tipo_retorno != NULL) {
       
        TreeNode* no_tipo = (TreeNode*) malloc(sizeof(TreeNode));
        no_tipo->tipo = TIPO_ID; 
        no_tipo->valor_s = strdup(tipo_retorno);
        for(int i=0; i<MAXCHILDREN; i++) no_tipo->filho[i]=NULL;
        
        no->filho[2] = no_tipo; 
    } else {
        no->filho[2] = NULL;
    }

    for(int i=3; i<MAXCHILDREN; i++) no->filho[i] = NULL;
    return no;
}

TreeNode* novo_no_bool_literal(char* valor) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    no->tipo = TIPO_BOOL_LITERAL;
    no->tipo_dado = EXP_BOOLEAN;
    no->valor_s = strdup(valor); /* "true" ou "false" */
    no->operacao = 0;
    
    for (int i = 0; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }
    return no;
}

void processar_declaracao_vars(TreeNode* lista_ids, char* tipo) {
    if (lista_ids == NULL) return;

    if (lista_ids->tipo == TIPO_ID) {
        // caso base: um ID sozinho
        if (buscar_simbolo(lista_ids->valor_s) != NULL) {
            printf("ERRO SEMANTICO: Redeclaracao da variavel '%s'. Ela ja foi declarada anteriormente.\n", lista_ids->valor_s);
            
        }else{
            inserir_simbolo(lista_ids->valor_s, tipo);
        }
    } 
    else if (lista_ids->tipo == TIPO_LISTA) {
        // caso recursivo: lista de IDs
        processar_declaracao_vars(lista_ids->filho[0], tipo); 
        processar_declaracao_vars(lista_ids->filho[1], tipo); 
    }
}

ExpType string_para_tipo(char* tipo_str) {
    if (strcmp(tipo_str, "integer") == 0) return EXP_INTEGER;
    if (strcmp(tipo_str, "boolean") == 0) return EXP_BOOLEAN;
    return EXP_VOID;
}