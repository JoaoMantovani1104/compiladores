#include "globals.h"
#include "symbol_table.h"


Simbolo* buscar_simbolo(char *nome) {
    Simbolo *atual = tabela_de_simbolos;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void inserir_simbolo(char *nome, char *tipo) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome); // copia a string
    novo->tipo = strdup(tipo);
    novo->proximo = tabela_de_simbolos; // inserir no início da lista
    tabela_de_simbolos = novo; // Atualiza a cabeça da lista
    
    printf("Análise Semântica: Inseriu '%s' na tabela.\n", nome);
}