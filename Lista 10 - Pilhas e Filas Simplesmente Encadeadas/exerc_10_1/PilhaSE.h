/* 
 * File:   PilhaSE.h
 * Author: Leonardo Adamoli
 *
 * Created on May 19, 2018, 9:58 AM
 */

#ifndef PILHASE_H
#define PILHASE_H
#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct nodo Nodo;

struct nodo {
    
    int info;
    Nodo *prox;
};

typedef struct {
    
    Nodo *topo;
    
} PilhaSE;

void criaPilha(PilhaSE *pilha);
int empilha(PilhaSE *pilha, int info);
int desempilha(PilhaSE *pilha, int *info);
int estaVazia(PilhaSE pilha);
int consulta(PilhaSE pilha, int *info);
//void exibe(PilhaSE pilha);

#endif /* PILHASE_H */

