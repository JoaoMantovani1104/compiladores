#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

/* estrutura para representar escopo (tabela de símbolos) */
typedef struct Escopo {
    Simbolo *tabela;  /* tabela de símbolos deste escopo */
    struct Escopo *proximo;  /* próximo escopo na pilha */
} Escopo;

static Escopo *pilha_escopos = NULL;

/* tabela de símbolos global (escopo principal) */
Simbolo *tabela_de_simbolos = NULL;

/* para verificação de redeclaração */
Simbolo* buscar_simbolo_no_escopo_atual(char *nome) {
    /* escopo atual -> topo da pilha */
    /* distinção entre shadowing (variável em escopo externo) e redeclaração */
    if (pilha_escopos != NULL) {
        Simbolo *atual = pilha_escopos->tabela;
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) return atual;
            atual = atual->proximo;
        }
    }
    /* sem pilha de escopos, há só o escopo global */
    /* buscar na tabela global */
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
    /* buscar no escopo atual primeiro, depois nos escopos externos */
    Escopo *escopo_atual = pilha_escopos;

    /* se há pilha de escopos, buscar do mais interno para o mais externo */
    while (escopo_atual != NULL) {
        Simbolo *atual = escopo_atual->tabela;
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) return atual;
            atual = atual->proximo;
        }
        escopo_atual = escopo_atual->proximo;
    }

    /* se não encontrou na pilha, buscar na tabela global */
    Simbolo *atual = tabela_de_simbolos;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }

    return NULL;
}

void inserir_simbolo(char *nome, char *tipo) {
    // por padrão, assume-se que é uma variável
    inserir_simbolo_com_categoria(nome, tipo, CATEGORIA_VARIABLE);
}

void inserir_simbolo_com_categoria(char *nome, char *tipo, CategoriaSimbolo categoria) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->categoria = categoria;

    if (pilha_escopos != NULL) {
        /* inserir no escopo atual (topo da pilha) */
        novo->proximo = pilha_escopos->tabela;
        pilha_escopos->tabela = novo;
    } else {
        /* inserir na tabela global */
        novo->proximo = tabela_de_simbolos;
        tabela_de_simbolos = novo;
    }
}

void abrir_escopo() {
    /* criar novo escopo e adicionar no topo da pilha */
    Escopo *novo_escopo = (Escopo*) malloc(sizeof(Escopo));
    novo_escopo->tabela = NULL;
    novo_escopo->proximo = pilha_escopos;
    pilha_escopos = novo_escopo;
}

void fechar_escopo() {
    /* remover o escopo do topo da pilha e liberar memória */
    if (pilha_escopos != NULL) {
        Escopo *escopo_remover = pilha_escopos;
        pilha_escopos = pilha_escopos->proximo;

        /* liberar os símbolos do escopo */
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
    // inserir integer e boolean como tipos primitivos na tabela de símbolos
    //feito no início da análise semantica
    inserir_simbolo_com_categoria("integer", "tipo", CATEGORIA_TYPE);
    inserir_simbolo_com_categoria("boolean", "tipo", CATEGORIA_TYPE);
    // printf("Análise Semântica: Tipos primitivos 'integer' e 'boolean' instalados na tabela.\n");
}