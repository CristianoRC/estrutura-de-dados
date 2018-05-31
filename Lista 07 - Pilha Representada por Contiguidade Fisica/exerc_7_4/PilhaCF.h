/* 
 * File:   PilhaCF.h
 * Author: Leonardo Adamoli
 *
 * Created on April 7, 2018, 10:39 AM
 */

#ifndef PILHACF_H
#define PILHACF_H
#define MAX_NODOS 5
#define SUCESSO 0
#define PILHA_VAZIA 1
#define PILHA_CHEIA 2
#define MAIS_DE_UM_NODO 3
#define NAO_CHEIA 4

typedef struct {
    
    int v[MAX_NODOS];
    int topo;
    
} PilhaCF;

void criaPilha (PilhaCF *p);
int empilha (PilhaCF *p, int dado);
int desempilha (PilhaCF *p, int *dado);
int estaCheia (PilhaCF p);
int estaVazia (PilhaCF p);

#endif /* PILHACF_H */

