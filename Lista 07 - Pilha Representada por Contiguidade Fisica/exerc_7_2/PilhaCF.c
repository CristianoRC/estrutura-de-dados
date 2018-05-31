#include <stdio.h>
#include "PilhaCF.h"

//Função criaPilha
void criaPilha (PilhaCF *p) {
    
    p->topo = -1;
}
//Função empilha
int empilha (PilhaCF *p, int dado) {
    
    int i;
    
    if (p->topo == MAX_NODOS -1)
        return PILHA_CHEIA;
    else {
        p->topo++;
        p->v[p->topo] = dado;
        return SUCESSO;
    }
}
//Função desempilha
int desempilha (PilhaCF *p, int *dado) {
    
    int i;
    
    if (p->topo == -1)
        return PILHA_VAZIA;
    else {
        *dado = p->v[p->topo];
        p->topo--;
        return SUCESSO;
    }
}
//Função estaCheia
int estaCheia (PilhaCF p) {
    
    if (p.topo == MAX_NODOS - 1)
        return PILHA_CHEIA;
    else
        return NAO_CHEIA;
}
//Função estaVazia
int estaVazia (PilhaCF p) {
    
    if (p.topo == -1)
        return PILHA_VAZIA;
    else
        return MAIS_DE_UM_NODO;
}
