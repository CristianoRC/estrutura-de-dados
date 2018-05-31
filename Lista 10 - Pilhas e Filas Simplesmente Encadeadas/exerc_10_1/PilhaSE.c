#include <stdio.h>
#include <stdlib.h>
#include "PilhaSE.h"

//Função criaPilha
void criaPilha(PilhaSE *pilha) {
    
    pilha->topo = NULL;
}

//Função empilha
int empilha(PilhaSE *pilha, int info) {
    
    Nodo *pNodo;
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pNodo->info = info;
        pNodo->prox = pilha->topo;
        pilha->topo = pNodo;
    }
    return SUCESSO;
}

//Função desempilha
int desempilha(PilhaSE *pilha, int *info) {
    
    Nodo *pNodo, *pAux;
    
    pNodo = pilha->topo;
    if (pNodo == NULL)
        return PILHA_VAZIA;
    else {
        if (pNodo->prox == NULL) {
            *info = pNodo->info;
            pilha->topo = NULL;
            free(pNodo);
        }else {
            *info = pNodo->info;
            pilha->topo = pNodo->prox;
            free(pNodo);
        }    
    }
    return SUCESSO;
}

//Função estaVazia
int estaVazia(PilhaSE pilha){
    
    if (pilha.topo == NULL)
        return 1;
    else
        return 0;
}

//Função consulta
int consulta(PilhaSE pilha, int *info) {
    
    if (pilha.topo == NULL)
        return PILHA_VAZIA;
    else 
        *info = pilha.topo->info;
    
    return SUCESSO;
}

/*
Função exibe
void exibe(PilhaSE pilha) {
    
    PilhaSE pilhaAux;
    Nodo *pNodo;
    int dado, resp;
   
    pNodo = pilha.topo;
    if (pNodo == NULL)
        printf ("ERRO!\nPILHA VAZIA!\n");
    else {
        printf ("------ CONTEÚDO DA PILHA: ------\n");
        while (pNodo != NULL) {
            resp = desempilha(&pilha, &dado);
            printf("Endereço atual: %p | Dado: %d | Próximo endereço: %p\n", pNodo, dado, pNodo->prox);
            resp = empilha(&pilhaAux, dado);
            pNodo = pNodo->prox;
        }
    }
}
*/