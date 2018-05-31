/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 10, 2018, 8:48 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    PilhaCF pilha, pilha2;
    int x, resp, dado, i, aux;
    
    setlocale(LC_ALL, "portuguese");
    criaPilha(&pilha);
    criaPilha(&pilha2);
    for (i = 0; i < 2; i++) {
        printf ("Informe o dado %d: ", i + 1);
        scanf ("%d", &dado);
        printf ("EMPILHA\n");
        resp = empilha(&pilha, dado);
        if (resp == PILHA_CHEIA)
            printf ("ERRO!\nPILHA CHEIA!\n");
        else
            printf ("SUCESSO!\n");
    }
    printf ("\n");
    printf ("DESEMPILHA\n");
    resp = desempilha(&pilha, &dado);
    if (resp == SUCESSO) {
        aux = pilha.v[pilha.topo + 1];
        printf ("EMPILHA\n");
        resp = empilha(&pilha2, aux);
        if (resp == SUCESSO)
            printf ("SUCESSO!\n");
        else
            printf ("A PILHA ESTÁ CHEIA!\n");
    }else
        printf ("ERRO!\nPILHA VAZIA!\n");
    printf ("\n");
    printf ("DESEMPILHA\n");
    resp = desempilha(&pilha, &dado);
    if (resp == SUCESSO) {
        aux = pilha.v[pilha.topo + 1];
        x = pilha.v[pilha.topo + 1];
        printf ("EMPILHA\n");
        resp = empilha(&pilha2, aux);
        if (resp == SUCESSO)
            printf ("SUCESSO!\n");
        else
            printf ("A PILHA ESTÁ CHEIA!\n");
    }else
        printf ("ERRO!\nPILHA VAZIA!\n");
    printf ("------Variável X------\n");
    printf ("CONTEÚDO: %d\n\n", x);
    printf ("------Pilha 1------\n");
    for (i = 0; i <= pilha2.topo; i++)
        printf ("CONTEÚDO DO NODO %d: %d\n", i + 1, pilha.v[i]);

    return (EXIT_SUCCESS);
}

