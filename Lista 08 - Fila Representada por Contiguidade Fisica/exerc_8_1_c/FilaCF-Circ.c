#include <stdio.h>
#include <stdlib.h>
#include "FilaCF-Circ.h"

//Função criaFila
void criaFila(FilaCF_Circ *fila) {
    
    fila->frente = 0;
    fila->re = -1;
    fila->tam = 0;
}

//Função insere
int insere(FilaCF_Circ *fila, int dado) {
    
    if (fila->tam == MAX_NODOS)
        return FILA_CHEIA;
    else {
        fila->re++;
        if (fila->re == MAX_NODOS) {
            fila->re = 0;
            fila->v[fila->re] = dado;
        }else
            fila->v[fila->re] = dado;
   
        fila->tam++;
    }
    return SUCESSO;
}

//Função retira
int retira(FilaCF_Circ *fila, int *dado) {
    
    if (fila->tam == 0)
        return FILA_VAZIA;
    else {
        if (fila->frente == MAX_NODOS - 1) {
            *dado = fila->v[fila->frente];
            fila->frente = 0;
        }else {
            *dado = fila->v[fila->frente];
            fila->frente++;
        }
        fila->tam--;
    }
    return SUCESSO;
}

//Função estaCheia
int estaCheia(FilaCF_Circ fila) {
    
    if (fila.tam == MAX_NODOS)
        return FILA_CHEIA;
    else
        return NAO_CHEIA;
}

//Função estaVazia
int estaVazia(FilaCF_Circ fila) {
    
    if (fila.tam == 0)
        return FILA_VAZIA;
    else
        return MAIS_DE_UM_NODO;
}

//Função exibe
void exibe(FilaCF_Circ fila) {
    
    int i;
 
    if (fila.tam == 0)
        printf ("ERRO!\nA FILA ESTÁ VAZIA!\n");
    else {
        printf ("Frente: %d | Ré: %d\n", fila.frente, fila.re);
        if (fila.re == 0 && fila.tam < MAX_NODOS)
            for (i = 0; i <= fila.tam; i+=2)
                printf ("Elemento %d: %d\n", i, fila.v[i]);
    }
}
