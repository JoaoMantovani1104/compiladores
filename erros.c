#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

// Listas de erros
static Erro *lista_erros_lexicos = NULL;
static Erro *lista_erros_sintaticos = NULL;
static Erro *lista_erros_semanticos = NULL;

// Contadores
int contador_erros_lexicos = 0;
static int contador_erros_sintaticos = 0;
static int contador_erros_semanticos = 0;

void adicionar_erro_lexico(const char *mensagem) {
    Erro *novo = (Erro*) malloc(sizeof(Erro));
    if (novo == NULL) return;

    novo->mensagem = strdup(mensagem);
    novo->proximo = lista_erros_lexicos;
    lista_erros_lexicos = novo;
    contador_erros_lexicos++;
}

void adicionar_erro_sintatico(const char *mensagem) {
    Erro *novo = (Erro*) malloc(sizeof(Erro));
    if (novo == NULL) return;

    novo->mensagem = strdup(mensagem);
    novo->proximo = lista_erros_sintaticos;
    lista_erros_sintaticos = novo;
    contador_erros_sintaticos++;
}

void adicionar_erro_semantico(const char *mensagem) {
    Erro *novo = (Erro*) malloc(sizeof(Erro));
    if (novo == NULL) return;

    novo->mensagem = strdup(mensagem);
    novo->proximo = lista_erros_semanticos;
    lista_erros_semanticos = novo;
    contador_erros_semanticos++;
}

void exibir_erros_lexicos() {
    Erro *atual = lista_erros_lexicos;
    int i = 1;
    while (atual != NULL) {
        printf("  %d. %s", i++, atual->mensagem);
        if (atual->mensagem[strlen(atual->mensagem) - 1] != '\n') {
            printf("\n");
        }
        atual = atual->proximo;
    }
}

void exibir_erros_sintaticos() {
    Erro *atual = lista_erros_sintaticos;
    int i = 1;
    while (atual != NULL) {
        printf("  %d. %s", i++, atual->mensagem);
        if (atual->mensagem[strlen(atual->mensagem) - 1] != '\n') {
            printf("\n");
        }
        atual = atual->proximo;
    }
}

void exibir_erros_semanticos() {
    Erro *atual = lista_erros_semanticos;
    int i = 1;
    while (atual != NULL) {
        printf("  %d. %s", i++, atual->mensagem);
        if (atual->mensagem[strlen(atual->mensagem) - 1] != '\n') {
            printf("\n");
        }
        atual = atual->proximo;
    }
}

void limpar_erros_lexicos() {
    Erro *atual = lista_erros_lexicos;
    while (atual != NULL) {
        Erro *temp = atual;
        atual = atual->proximo;
        free(temp->mensagem);
        free(temp);
    }
    lista_erros_lexicos = NULL;
    contador_erros_lexicos = 0;
}

void limpar_erros_sintaticos() {
    Erro *atual = lista_erros_sintaticos;
    while (atual != NULL) {
        Erro *temp = atual;
        atual = atual->proximo;
        free(temp->mensagem);
        free(temp);
    }
    lista_erros_sintaticos = NULL;
    contador_erros_sintaticos = 0;
}

void limpar_erros_semanticos() {
    Erro *atual = lista_erros_semanticos;
    while (atual != NULL) {
        Erro *temp = atual;
        atual = atual->proximo;
        free(temp->mensagem);
        free(temp);
    }
    lista_erros_semanticos = NULL;
    contador_erros_semanticos = 0;
}

int contar_erros_lexicos() {
    return contador_erros_lexicos;
}

int contar_erros_sintaticos() {
    return contador_erros_sintaticos;
}

int contar_erros_semanticos() {
    return contador_erros_semanticos;
}

