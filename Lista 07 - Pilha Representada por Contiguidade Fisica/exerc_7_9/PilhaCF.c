#include <stdio.h>
#include "PilhaCF.h"

//Função criaPilha
void criaPilha (PilhaCF *p) {
    
    p->topo = - 1;
}
//Função empilha
int empilha (PilhaCF *p, int dado) {
    
    if (p->topo == MAX_NODOS - 1)
        return PILHA_CHEIA;
    else {
        p->topo++;
        p->v[p->topo] = dado;
        return SUCESSO;
    }
}
//Função desempilha
int desempilha (PilhaCF *p, int *dado) {
    
    if (p->topo == - 1)
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
    
    if (p.topo == - 1)
        return PILHA_VAZIA;
    else
        return MAIS_DE_UM_NODO;
}
//Função exibe
void exibe (PilhaCF pilha) {
    
    int i;
    
    printf ("------ CONTEÚDO DA PILHA ------\n");
    for (i = 0; i <= pilha.topo; i++)
        printf ("ELEMENTO %d: %d\n", i + 1, pilha.v[i]);
}