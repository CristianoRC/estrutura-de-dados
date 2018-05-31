#include <stdio.h>
#include "PilhaCF.h"

//Função criaPilha
void criaPilha (PilhaCF *p) {
    
    p->topo = - 1;
}
//Função empilha
int empilha (PilhaCF *p, int dado) {
    
    int i;
    
    if (p->topo == MAX_NODOS - 1)
        return PILHA_CHEIA;
    else
        if (p->topo == - 1) {
            p->topo++;
            for (i = p->topo; i <= p->topo; i++)
                p->v[i] = dado;
            return SUCESSO;
        }else {
            p->topo++;
            for (i = p->topo; i <= p->topo; i++)
                p->v[i] = dado;
            return SUCESSO;
    }
}
//Função desempilha
int desempilha (PilhaCF *p, int *dado) {
    
    int i;
    
    if (p->topo == - 1)
        return PILHA_VAZIA;
    else {
        for (i = p->topo; i <= p->topo; i++)
            *dado = p->v[i];
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
