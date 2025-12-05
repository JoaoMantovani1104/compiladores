#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

/* Estrutura para representar um escopo (tabela de símbolos) */
typedef struct Escopo {
    Simbolo *tabela;  /* Tabela de símbolos deste escopo */
    struct Escopo *proximo;  /* Próximo escopo na pilha */
} Escopo;

/* Pilha de escopos - o topo é o escopo atual */
static Escopo *pilha_escopos = NULL;

/* Tabela de símbolos global (escopo principal) */
Simbolo *tabela_de_simbolos = NULL;

/* Buscar símbolo apenas no escopo atual (para verificação de redeclaração) */
Simbolo* buscar_simbolo_no_escopo_atual(char *nome) {
    /* Buscar apenas no escopo atual (topo da pilha) */
    /* Se não há pilha de escopos, retornar NULL (não buscar na tabela global) */
    /* Isso permite distinguir entre shadowing (variável em escopo externo) e redeclaração (mesmo escopo) */
    if (pilha_escopos != NULL) {
        Simbolo *atual = pilha_escopos->tabela;
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) return atual;
            atual = atual->proximo;
        }
    }
    /* Se não há pilha de escopos, estamos no escopo global */
    /* Nesse caso, buscar na tabela global */
    if (pilha_escopos == NULL) {
        Simbolo *atual = tabela_de_simbolos;
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) return atual;
            atual = atual->proximo;
        }
    }
    return NULL;
}

Simbolo* buscar_simbolo(char *nome) {
    /* Buscar no escopo atual primeiro, depois nos escopos externos */
    Escopo *escopo_atual = pilha_escopos;

    /* Se há pilha de escopos, buscar do mais interno para o mais externo */
    while (escopo_atual != NULL) {
        Simbolo *atual = escopo_atual->tabela;
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) return atual;
            atual = atual->proximo;
        }
        escopo_atual = escopo_atual->proximo;
    }

    /* Se não encontrou na pilha, buscar na tabela global */
    Simbolo *atual = tabela_de_simbolos;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }

    return NULL;
}

void inserir_simbolo(char *nome, char *tipo) {
    // Por padrão, assume-se que é uma variável
    inserir_simbolo_com_categoria(nome, tipo, CATEGORIA_VARIABLE);
}

void inserir_simbolo_com_categoria(char *nome, char *tipo, CategoriaSimbolo categoria) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->categoria = categoria;

    /* Inserir no escopo atual (se houver pilha) ou na tabela global */
    if (pilha_escopos != NULL) {
        /* Inserir no escopo atual (topo da pilha) */
        novo->proximo = pilha_escopos->tabela;
        pilha_escopos->tabela = novo;
    } else {
        /* Inserir na tabela global */
        novo->proximo = tabela_de_simbolos;
        tabela_de_simbolos = novo;
    }
}

void abrir_escopo() {
    /* Criar novo escopo e adicionar no topo da pilha */
    Escopo *novo_escopo = (Escopo*) malloc(sizeof(Escopo));
    novo_escopo->tabela = NULL;
    novo_escopo->proximo = pilha_escopos;
    pilha_escopos = novo_escopo;
}

void fechar_escopo() {
    /* Remover o escopo do topo da pilha e liberar memória */
    if (pilha_escopos != NULL) {
        Escopo *escopo_remover = pilha_escopos;
        pilha_escopos = pilha_escopos->proximo;

        /* Liberar símbolos do escopo */
        Simbolo *atual = escopo_remover->tabela;
        while (atual != NULL) {
            Simbolo *proximo = atual->proximo;
            free(atual->nome);
            free(atual->tipo);
            free(atual);
            atual = proximo;
        }

        free(escopo_remover);
    }
}

void inicializar_tipos_primitivos() {
    // Instalar integer e boolean como tipos primitivos na tabela de símbolos
    // Conforme especificação: devem ser instalados no início da análise semântica
    inserir_simbolo_com_categoria("integer", "tipo", CATEGORIA_TYPE);
    inserir_simbolo_com_categoria("boolean", "tipo", CATEGORIA_TYPE);
    // printf("Análise Semântica: Tipos primitivos 'integer' e 'boolean' instalados na tabela.\n");
}