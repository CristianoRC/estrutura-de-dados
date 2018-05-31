#include <stdio.h>
#include "FilaCF.h"

//Função criaFila
void criaFila(FilaCF *fila) {
    
    fila->frente = 0;
    fila->re = -1;
}
//Função insere
int insere(FilaCF *fila, int dado) {
    
    if (fila->re == MAX_NODOS - 1)
        printf ("A FILA ESTÁ CHEIA!\n");
    else {
        fila->re++;
        fila->v[fila->re] = dado;
        return SUCESSO;
    }
}
//Função retira
int retira(FilaCF *fila, int *dado) {
    
    int i, qtNodos;
    
    if (fila->re < fila->frente)
        printf ("A FILA ESTÁ VAZIA!\n");
    else {
        *dado = fila->v[fila->frente];
        fila->frente++;
        qtNodos = ((fila->re + 1) - fila->frente);
        if (qtNodos > 0)
            for (i = 1; i <= qtNodos; i++)
                fila->v[i - 1] = fila->v[i];
        return SUCESSO;
    }
}
//Função estaCheia
int estaCheia(FilaCF fila) {
    
    if (fila.re == MAX_NODOS - 1)
        return FILA_CHEIA;
    else
        return NAO_CHEIA;
}
//Função estaVazia
int estaVazia(FilaCF fila) {
    
    if (fila.re < fila.frente)
        return FILA_VAZIA;
    else
        return MAIS_DE_UM_NODO;
}
//Função consulta
int consulta(FilaCF fila, int dado) {
    
    int i, flag = 0;
    
    if (fila.re < fila.frente)
        return FILA_VAZIA;
    else {
        for (i = 0; i <= fila.re; i++)
            if (fila.v[i] == dado) {
                flag = 1;
                break;
            }
        if (flag == 1)
            return SUCESSO;
        else
            return ERRO;
    }
}