#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXCHILDREN 5

typedef struct Simbolo {
    char *nome;
    char *tipo;
    
    
    struct Simbolo *proximo; 
} Simbolo;

Simbolo* buscar_simbolo(char *nome);
void inserir_simbolo(char *nome, char *tipo);

//tipos
typedef enum {
    EXP_VOID,    /* Para comandos que não retornam valor */
    EXP_INTEGER,
    EXP_BOOLEAN,
    EXP_ERRO     /* Para propagar que já houve erro */
} ExpType;

typedef enum {
    TIPO_ID,
    TIPO_NUMERO,
    TIPO_ATRIBUICAO,
    TIPO_OPERACAO,
    TIPO_LISTA,
    TIPO_CONDICIONAL, 
    TIPO_PROGRAMA,    /* Nó raiz */
    TIPO_VAR_DECL,    
    TIPO_SUBROTINA,   /* Procedure ou Function */
    TIPO_WHILE,       
    TIPO_LEITURA,     
    TIPO_ESCRITA,     
    TIPO_CHAMADA,      
    TIPO_BOOL_LITERAL
} TipoNo;


typedef struct TreeNode {
  TipoNo tipo;
  char *valor_s;
  int operacao;
  ExpType tipo_dado;
  
  struct TreeNode *filho[MAXCHILDREN]; 
  
} TreeNode;


TreeNode* novo_no_id(char *nome_id);

TreeNode* novo_no_atribuicao(TreeNode* no_variavel, TreeNode* no_expressao);
TreeNode* novo_no_num(char *val);
TreeNode* novo_no_operacao(TreeNode* esq, int op, TreeNode* dir);
TreeNode* novo_no_lista(TreeNode* no, TreeNode* proximo);
TreeNode* novo_no_condicional(TreeNode* cond, TreeNode* then_bloco, TreeNode* else_bloco);
TreeNode* novo_no_while(TreeNode* condicao, TreeNode* corpo);
TreeNode* novo_no_chamada(TreeNode* id, TreeNode* args);
TreeNode* novo_no_programa(char* nome_prog, TreeNode* corpo);
TreeNode* novo_no_io(TipoNo tipo, TreeNode* args);
TreeNode* novo_no_subrotina(char* nome, TreeNode* params, char* tipo_retorno, TreeNode* corpo);
TreeNode* novo_no_bool_literal(char* valor);
void processar_declaracao_vars(TreeNode* lista_ids, char* tipo);
ExpType string_para_tipo(char* tipo_str);
void yyerror(const char *s);

extern TreeNode *savedTree;
extern Simbolo *tabela_de_simbolos; 
extern int yylineno;
extern char *yytext;


#endif  
