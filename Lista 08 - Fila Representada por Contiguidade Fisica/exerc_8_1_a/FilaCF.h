/* 
 * File:   FilaCF.h
 * Author: Leonardo Adamoli
 *
 * Created on April 22, 2018, 7:23 PM
 */

#ifndef FILACF_H
#define FILACF_H
#define MAX_NODOS 3
#define SUCESSO 0
#define FILA_VAZIA 1
#define FILA_CHEIA 2
#define NAO_CHEIA 3
#define MAIS_DE_UM_NODO 4
#define ERRO 5

typedef struct {
    
    int v[MAX_NODOS];
    int frente;
    int re;
    
} FilaCF;

void criaFila(FilaCF *fila);
int insere(FilaCF *fila, int dado);
int retira(FilaCF *fila, int *dado);
int estaCheia(FilaCF fila);
int estaVazia(FilaCF fila);
int consulta(FilaCF fila, int dado);

#endif /* FILACF_H */

