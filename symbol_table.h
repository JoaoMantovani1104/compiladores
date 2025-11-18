#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_


Simbolo* buscar_simbolo(char *nome);
void inserir_simbolo(char *nome, char *tipo);

typedef struct Simbolo {
    char *nome;
    char *tipo;
    
    struct Simbolo *proximo; 
} Simbolo;


#endif