#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "globals.h"
#include "sintatico_novo.tab.h"

extern int yylineno;

// Função auxiliar para adicionar erros semânticos
static void erro_semantico(const char *formato, ...) {
    char buffer[512];
    va_list args;
    va_start(args, formato);
    vsnprintf(buffer, sizeof(buffer), formato, args);
    va_end(args);
    adicionar_erro_semantico(buffer);
}

TreeNode* novo_no_id(char *nome_id) {
    TreeNode *no = (TreeNode*) malloc(sizeof(TreeNode));
    if (no == NULL) yyerror("Out of memory");

    no->tipo = TIPO_ID;
    no->valor_s = strdup(nome_id);
    no->operacao = 0;

    Simbolo* s = buscar_simbolo(nome_id);
    if (s != NULL) {
        // Verificar se é um tipo primitivo sendo usado como variável
        if (s->categoria == CATEGORIA_TYPE) {
            erro_semantico("ERRO SEMANTICO (Linha %d): O identificador '%s' eh um tipo primitivo e nao pode ser usado como variavel.\n", yylineno, nome_id);
            no->tipo_dado = EXP_ERRO;
        } else if (s->categoria == CATEGORIA_VARIABLE) {
            no->tipo_dado = string_para_tipo(s->tipo);
        } else if (s->categoria == CATEGORIA_FUNCTION) {
            // Function: tipo de retorno é integer ou boolean (assumimos integer por padrão)
            no->tipo_dado = EXP_INTEGER;
        } else if (s->categoria == CATEGORIA_PROCEDURE) {
            no->tipo_dado = EXP_VOID;
        } else {
            no->tipo_dado = string_para_tipo(s->tipo);
        }
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

    // Verificar se algum operando é VOID (procedure sem retorno)
    if (esq != NULL && esq->tipo_dado == EXP_VOID) {
        erro_semantico("ERRO SEMANTICO (Linha %d): Tentativa de usar uma PROCEDURE (sem retorno) em uma expressao.\n", yylineno);
        no->tipo_dado = EXP_ERRO;
        return no;
    }

    if (dir != NULL && dir->tipo_dado == EXP_VOID) {
        erro_semantico("ERRO SEMANTICO (Linha %d): Tentativa de usar uma PROCEDURE (sem retorno) em uma expressao.\n", yylineno);
        no->tipo_dado = EXP_ERRO;
        return no;
    }

    // Verificar se algum operando tem erro
    if ((esq != NULL && esq->tipo_dado == EXP_ERRO) || (dir != NULL && dir->tipo_dado == EXP_ERRO)) {
        no->tipo_dado = EXP_ERRO;
        return no;
    }

    // Operações aritméticas: +, -, *, div
    if (op == TOKEN_SOMA || op == TOKEN_SUBT || op == TOKEN_MULT || op == TOKEN_DIV) {
        // Verificar se é operador unário: menos unário (-) tem esq=NULL, dir!=NULL
        if (esq == NULL && dir != NULL) {
            // Operador unário: menos unário (-)
            if (dir->tipo_dado != EXP_INTEGER) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Operador '-' unario requer operando do tipo INTEGER.\n", yylineno);
                no->tipo_dado = EXP_ERRO;
                return no;
            }
            no->tipo_dado = EXP_INTEGER;
        } else if (esq != NULL && dir != NULL) {
            // Operador binário: ambos operandos devem existir
            if (esq->tipo_dado != EXP_INTEGER || dir->tipo_dado != EXP_INTEGER) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Operacoes aritmeticas requerem operandos do tipo INTEGER.\n", yylineno);
                no->tipo_dado = EXP_ERRO;
                return no;
            }
            no->tipo_dado = EXP_INTEGER;
        } else {
            // Caso inválido: falta algum operando
            if (esq == NULL && dir == NULL) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Operacao requer pelo menos um operando.\n", yylineno);
            } else if (esq != NULL && dir == NULL) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Operacao binaria requer dois operandos.\n", yylineno);
            }
            no->tipo_dado = EXP_ERRO;
            return no;
        }
    }
    // Operações relacionais: <, <=, >, >=
    else if (op == TOKEN_MENOR || op == TOKEN_MENORIGUAL || op == TOKEN_MAIOR || op == TOKEN_MAIORIGUAL) {
        // Operandos devem ser integer
        if (esq == NULL || dir == NULL) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Operacao relacional requer dois operandos.\n", yylineno);
            no->tipo_dado = EXP_ERRO;
            return no;
        }
        if (esq->tipo_dado != EXP_INTEGER || dir->tipo_dado != EXP_INTEGER) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Operacoes relacionais (<, <=, >, >=) requerem operandos do tipo INTEGER.\n", yylineno);
            no->tipo_dado = EXP_ERRO;
            return no;
        }
        no->tipo_dado = EXP_BOOLEAN;
    }
    // Operações de igualdade/diferença: =, <>
    else if (op == TOKEN_IGUAL || op == TOKEN_DIF) {
        // Operandos devem ser do mesmo tipo primitivo (integer ou boolean)
        if (esq == NULL || dir == NULL) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Operacao de igualdade/diferenca requer dois operandos.\n", yylineno);
            no->tipo_dado = EXP_ERRO;
            return no;
        }
        if (esq->tipo_dado != dir->tipo_dado) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Operacoes de igualdade/diferenca (=, <>) requerem operandos do mesmo tipo primitivo.\n", yylineno);
            no->tipo_dado = EXP_ERRO;
            return no;
        }
        no->tipo_dado = EXP_BOOLEAN;
    }
    // Operações lógicas: and, or
    else if (op == TOKEN_AND || op == TOKEN_OR) {
        // Operandos devem ser boolean
        if (esq == NULL || dir == NULL) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Operacao logica (and, or) requer dois operandos.\n", yylineno);
            no->tipo_dado = EXP_ERRO;
            return no;
        }
        if (esq->tipo_dado != EXP_BOOLEAN || dir->tipo_dado != EXP_BOOLEAN) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Operacoes logicas (and, or) requerem operandos do tipo BOOLEAN.\n", yylineno);
            no->tipo_dado = EXP_ERRO;
            return no;
        }
        no->tipo_dado = EXP_BOOLEAN;
    }
    // Operador lógico unário: not
    else if (op == TOKEN_NOT) {
        // Operando deve ser boolean
        if (dir == NULL && esq != NULL) {
            // not como operador unário à esquerda (se implementado assim)
            if (esq->tipo_dado != EXP_BOOLEAN) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Operador 'not' requer operando do tipo BOOLEAN.\n", yylineno);
                no->tipo_dado = EXP_ERRO;
                return no;
            }
            no->tipo_dado = EXP_BOOLEAN;
        } else if (esq == NULL && dir != NULL) {
            // not como operador unário à direita (implementação atual)
            if (dir->tipo_dado != EXP_BOOLEAN) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Operador 'not' requer operando do tipo BOOLEAN.\n", yylineno);
                no->tipo_dado = EXP_ERRO;
                return no;
            }
            no->tipo_dado = EXP_BOOLEAN;
        } else {
            no->tipo_dado = EXP_ERRO;
        }
    }
    else {
        // Operador desconhecido
        erro_semantico("ERRO SEMANTICO (Linha %d): Operador desconhecido.\n", yylineno);
        no->tipo_dado = EXP_ERRO;
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
        if (s->categoria == CATEGORIA_PROCEDURE) {
            no->tipo_dado = EXP_VOID; /* Procedures não retornam valor */
        }
        else if (s->categoria == CATEGORIA_FUNCTION) {
            // Functions retornam integer ou boolean conforme declarado
            // Por enquanto, assumimos integer (pode ser melhorado se necessário)
            no->tipo_dado = EXP_INTEGER;
        }
        else if (s->categoria == CATEGORIA_VARIABLE) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Tentativa de chamar a variavel '%s' como funcao ou procedure.\n", yylineno, id->valor_s);
            no->tipo_dado = EXP_ERRO;
        }
        else if (s->categoria == CATEGORIA_TYPE) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Tentativa de chamar o tipo '%s' como funcao ou procedure.\n", yylineno, id->valor_s);
            no->tipo_dado = EXP_ERRO;
        }
        else {
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
        // Verificar redeclaração apenas no escopo atual (não nos escopos externos)
        Simbolo* s = buscar_simbolo(lista_ids->valor_s);
        if (s != NULL) {
            // Verificar se está tentando redeclarar um tipo primitivo
            if (s->categoria == CATEGORIA_TYPE) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Nao e possivel redeclarar o tipo primitivo '%s' como variavel.\n", yylineno, lista_ids->valor_s);
            } else {
                // Verificar se é redeclaração no mesmo escopo
                // Se o símbolo encontrado está no escopo atual, é erro
                // Se está em escopo externo, é shadowing (permitido)
                Simbolo* s_atual = buscar_simbolo_no_escopo_atual(lista_ids->valor_s);
                if (s_atual != NULL) {
                    // Redeclaração no mesmo escopo - erro
                    erro_semantico("ERRO SEMANTICO (Linha %d): Redeclaracao da variavel '%s'. Ela ja foi declarada anteriormente.\n", yylineno, lista_ids->valor_s);
                } else {
                    // Shadowing - permitido, inserir no escopo atual
                    inserir_simbolo(lista_ids->valor_s, tipo);
                }
            }
        } else {
            inserir_simbolo(lista_ids->valor_s, tipo);
        }
    }
    else if (lista_ids->tipo == TIPO_LISTA) {
        // caso recursivo: lista de IDs
        processar_declaracao_vars(lista_ids->filho[0], tipo);
        processar_declaracao_vars(lista_ids->filho[1], tipo);
    }
}

void processar_declaracao_params(TreeNode* lista_ids, char* tipo) {
    if (lista_ids == NULL) return;

    if (lista_ids->tipo == TIPO_ID) {
        // caso base: um ID sozinho
        Simbolo* s = buscar_simbolo(lista_ids->valor_s);
        if (s != NULL) {
            // Verificar se está tentando redeclarar um tipo primitivo
            if (s->categoria == CATEGORIA_TYPE) {
                erro_semantico("ERRO SEMANTICO (Linha %d): Nao e possivel redeclarar o tipo primitivo '%s' como parametro.\n", yylineno, lista_ids->valor_s);
            } else {
                // Permitir redeclaração de parâmetros entre diferentes subrotinas
                // (não reportar erro, apenas inserir)
                inserir_simbolo(lista_ids->valor_s, tipo);
            }
        } else {
            inserir_simbolo(lista_ids->valor_s, tipo);
        }
    }
    else if (lista_ids->tipo == TIPO_LISTA) {
        // caso recursivo: lista de IDs
        processar_declaracao_params(lista_ids->filho[0], tipo);
        processar_declaracao_params(lista_ids->filho[1], tipo);
    }
}

ExpType string_para_tipo(char* tipo_str) {
    if (strcmp(tipo_str, "integer") == 0) return EXP_INTEGER;
    if (strcmp(tipo_str, "boolean") == 0) return EXP_BOOLEAN;
    return EXP_VOID;
}

void verificar_lista_identificadores_read(TreeNode* lista_ids) {
    if (lista_ids == NULL) return;

    if (lista_ids->tipo == TIPO_ID) {
        // caso base: um ID sozinho
        Simbolo* s = buscar_simbolo(lista_ids->valor_s);
        if (s == NULL) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Identificador '%s' nao declarado no comando 'read'.\n", yylineno, lista_ids->valor_s);
        } else if (s->categoria == CATEGORIA_TYPE) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Nao e possivel ler em um tipo primitivo '%s' no comando 'read'.\n", yylineno, lista_ids->valor_s);
        } else if (s->categoria == CATEGORIA_PROCEDURE || s->categoria == CATEGORIA_FUNCTION) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Nao e possivel ler em uma subrotina '%s' no comando 'read'.\n", yylineno, lista_ids->valor_s);
        }
    } else if (lista_ids->tipo == TIPO_LISTA) {
        // caso recursivo: lista de IDs
        verificar_lista_identificadores_read(lista_ids->filho[0]);
        verificar_lista_identificadores_read(lista_ids->filho[1]);
    }
}

void verificar_lista_expressoes_write(TreeNode* lista_expr) {
    if (lista_expr == NULL) return;

    if (lista_expr->tipo == TIPO_ID || lista_expr->tipo == TIPO_NUMERO ||
        lista_expr->tipo == TIPO_BOOL_LITERAL || lista_expr->tipo == TIPO_OPERACAO ||
        lista_expr->tipo == TIPO_CHAMADA) {
        // caso base: uma expressão
        if (lista_expr->tipo_dado == EXP_ERRO) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Expressao invalida no comando 'write'.\n", yylineno);
        } else if (lista_expr->tipo_dado != EXP_INTEGER && lista_expr->tipo_dado != EXP_BOOLEAN) {
            erro_semantico("ERRO SEMANTICO (Linha %d): Expressao no comando 'write' deve ser do tipo INTEGER ou BOOLEAN.\n", yylineno);
        }
    } else if (lista_expr->tipo == TIPO_LISTA) {
        // caso recursivo: lista de expressões
        verificar_lista_expressoes_write(lista_expr->filho[0]);
        verificar_lista_expressoes_write(lista_expr->filho[1]);
    }
}

/* Função auxiliar para imprimir espaços de indentação */
static void indentar(int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  "); // 2 espaços por nível
    }
}

/* Função auxiliar para converter o código do token em string */
static char* get_op_str(int op) {
    switch(op) {
        case TOKEN_SOMA: return "+";
        case TOKEN_SUBT: return "-";
        case TOKEN_MULT: return "*";
        case TOKEN_DIV:  return "/";
        case TOKEN_AND:  return "AND";
        case TOKEN_OR:   return "OR";
        case TOKEN_NOT:  return "NOT";
        case TOKEN_IGUAL: return "=";
        case TOKEN_DIF:   return "<>";
        case TOKEN_MENOR: return "<";
        case TOKEN_MAIOR: return ">";
        case TOKEN_MAIORIGUAL: return ">=";
        case TOKEN_MENORIGUAL: return "<=";
        default: return "?";
    }
}

void imprimir_arvore(TreeNode *tree, int nivel) {
    if (tree == NULL) return;

    indentar(nivel);

    switch (tree->tipo) {
        case TIPO_PROGRAMA:
            printf("[PROGRAMA] %s\n", tree->valor_s ? tree->valor_s : "");
            break;
        case TIPO_VAR_DECL:
            printf("[DECL VAR]\n");
            break;
        case TIPO_SUBROTINA:
            printf("[SUBROTINA] %s\n", tree->valor_s ? tree->valor_s : "anonima");
            break;
        case TIPO_LISTA:
            printf("[LISTA]\n"); 
            /* Dica: Lista às vezes polui a árvore, mas é bom para ver a estrutura real */
            break;
        case TIPO_CONDICIONAL:
            printf("[IF/ELSE]\n");
            break;
        case TIPO_WHILE:
            printf("[WHILE]\n");
            break;
        case TIPO_ATRIBUICAO:
            printf("[ATRIBUICAO :=]\n");
            break;
        case TIPO_OPERACAO:
            printf("[OPERACAO] %s\n", get_op_str(tree->operacao));
            break;
        case TIPO_NUMERO:
            printf("[NUM] %s\n", tree->valor_s);
            break;
        case TIPO_ID:
            printf("[ID] %s", tree->valor_s);
            /* Opcional: mostrar o tipo se já foi inferido */
            if (tree->tipo_dado == EXP_INTEGER) printf(" (int)");
            else if (tree->tipo_dado == EXP_BOOLEAN) printf(" (bool)");
            printf("\n");
            break;
        case TIPO_CHAMADA:
            printf("[CHAMADA] Func/Proc\n");
            break;
        case TIPO_LEITURA:
            printf("[READ]\n");
            break;
        case TIPO_ESCRITA:
            printf("[WRITE]\n");
            break;
        case TIPO_BOOL_LITERAL:
            printf("[BOOL] %s\n", tree->valor_s);
            break;
        default:
            printf("[NO DESCONHECIDO %d]\n", tree->tipo);
            break;
    }

    /* Chamada recursiva para os filhos */
    for (int i = 0; i < MAXCHILDREN; i++) {
        imprimir_arvore(tree->filho[i], nivel + 1);
    }
}