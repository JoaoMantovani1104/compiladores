#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

TreeNode* novo_no_id(char *nome_id) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");
    
    no->tipo = TIPO_ID;
    no->valor_s = strdup(nome_id);
    no->operacao = 0; // Sem operação
    

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

    // definição dos filhos
    no->filho[0] = no_variavel;   // O 'x'
    no->filho[1] = no_expressao; // O 'a + 5'
    
    
    for (int i = 2; i < MAXCHILDREN; i++) {
        no->filho[i] = NULL;
    }
    
    return no;
}
