#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXCHILDREN 5

typedef struct TreeNode {
  TipoNo tipo;
  char *valor_s;
  int operacao;
  
  struct TreeNode *filho[MAXCHILDREN]; 
  
} TreeNode;

TreeNode* novo_no_id(char *nome_id);


extern TreeNode *savedTree;

#endif  
