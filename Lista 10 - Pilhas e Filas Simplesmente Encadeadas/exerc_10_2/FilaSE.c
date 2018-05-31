#include <stdio.h>
#include <stdlib.h>
#include "FilaSE.h"

//Função criaFila
void criaFila(FilaSE *fila) {
    
    fila->frente = NULL;
    fila->re = NULL;
}

//Função insere
int insere(FilaSE *fila, int dado) {
    
    Nodo *pNodo;
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pNodo->info = dado;
        pNodo->prox = NULL;
        if (fila->frente == NULL) {
            fila->frente = pNodo;
            fila->re = pNodo;
        }else {
            fila->re->prox = pNodo;
            fila->re = pNodo;
        }
    }
    return SUCESSO;
}

//Função retira
int retira (FilaSE *fila, int *dado) {
    
    Nodo *pNodo;
    
    if (fila->frente == NULL)
        return FILA_VAZIA;
    else {
        pNodo = fila->frente;
        *dado = pNodo->info;
        fila->frente = pNodo->prox;
        free(pNodo);
    }
    return SUCESSO;
}
//Função estaVazia
int estaVazia(FilaSE fila) {
    
    if (fila.frente == NULL)
        return 1;
    else
        return 0;
}

//Função consulta
int consulta(FilaSE fila, int *dado) {
    
    if (fila.frente == NULL)
        return FILA_VAZIA;
    else
        *dado = fila.frente->info;
    return SUCESSO;
}

