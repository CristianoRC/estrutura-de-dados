/* 
 * File:   FilaCF-Circ.h
 * Author: Leonardo Adamoli
 *
 * Created on June 1, 2018, 3:14 PM
 */

#ifndef FILACF_CIRC_H
#define FILACF_CIRC_H
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
    int tam;
    
} FilaCF_Circ;

void criaFila(FilaCF_Circ *fila);
int insere(FilaCF_Circ *fila, int dado);
int retira(FilaCF_Circ *fila, int *dado);
int estaCheia(FilaCF_Circ fila);
int estaVazia(FilaCF_Circ fila);
void exibe(FilaCF_Circ fila);

#endif /* FILACF_CIRC_H */

