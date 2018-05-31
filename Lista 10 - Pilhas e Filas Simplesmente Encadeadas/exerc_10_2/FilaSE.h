/* 
 * File:   FilaSE.h
 * Author: Leonardo Adamoli
 *
 * Created on May 21, 2018, 12:30 AM
 */

#ifndef FILASE_H
#define FILASE_H
#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct nodo Nodo;

struct nodo {
    
    int info;
    Nodo *prox;
};

typedef struct {
    
    Nodo *frente;
    Nodo *re;
    
} FilaSE;

void criaFila(FilaSE *fila);
int insere(FilaSE *fila, int dado);
int retira(FilaSE *fila, int *dado);
int estaVazia(FilaSE fila);
int consulta(FilaSE fila, int *dado);

#endif /* FILASE_H */

