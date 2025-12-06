#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXCHILDREN 5

typedef enum {
    CATEGORIA_VARIABLE,
    CATEGORIA_TYPE,
    CATEGORIA_PROCEDURE,
    CATEGORIA_FUNCTION
} CategoriaSimbolo;

typedef struct Simbolo {
    char *nome;
    char *tipo;
    CategoriaSimbolo categoria;
    struct Simbolo *proximo;
} Simbolo;

Simbolo* buscar_simbolo(char *nome);
Simbolo* buscar_simbolo_no_escopo_atual(char *nome); // buscar apenas no escopo atual
void inserir_simbolo(char *nome, char *tipo);
void inserir_simbolo_com_categoria(char *nome, char *tipo, CategoriaSimbolo categoria);
void inicializar_tipos_primitivos();
void abrir_escopo();
void fechar_escopo();

//tipos
typedef enum {
    EXP_VOID,    /* comandos que não retornam valor */
    EXP_INTEGER,
    EXP_BOOLEAN,
    EXP_ERRO     /* propagar que já houve erro */
} ExpType;

typedef enum {
    TIPO_ID,
    TIPO_NUMERO,
    TIPO_ATRIBUICAO,
    TIPO_OPERACAO,
    TIPO_LISTA,
    TIPO_CONDICIONAL,
    TIPO_PROGRAMA,    /* nó raiz */
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
void processar_declaracao_params(TreeNode* lista_ids, char* tipo);
ExpType string_para_tipo(char* tipo_str);
void verificar_lista_identificadores_read(TreeNode* lista_ids);
void verificar_lista_expressoes_write(TreeNode* lista_expr);
void yyerror(const char *s);
void imprimir_arvore(TreeNode *tree, int nivel);

extern TreeNode *savedTree;
extern Simbolo *tabela_de_simbolos;
extern int yylineno;
extern char *yytext;

// estruturas para armazenar erros
typedef struct Erro {
    char *mensagem;
    struct Erro *proximo;
} Erro;

// funções de gerenciamento dos erros
void adicionar_erro_lexico(const char *mensagem);
void adicionar_erro_sintatico(const char *mensagem);
void adicionar_erro_semantico(const char *mensagem);
void exibir_erros_lexicos();
void exibir_erros_sintaticos();
void exibir_erros_semanticos();
void limpar_erros_lexicos();
void limpar_erros_sintaticos();
void limpar_erros_semanticos();
int contar_erros_lexicos();
int contar_erros_sintaticos();
int contar_erros_semanticos();

#endif
