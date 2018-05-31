/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 11, 2018, 8:34 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    PilhaCF pilha1, pilha2;
    int i, dado, resp;
    
    setlocale(LC_ALL, "portuguese");
    printf ("------Criação das Pilhas------\n");
    criaPilha(&pilha1);
    criaPilha(&pilha2);
    for (i = 0; i < MAX_NODOS; i++) {
        printf ("Informe o elemento %d da Pilha 1: ", i + 1);
        scanf ("%d", &dado);
        resp = empilha(&pilha1, dado);
    }
    for (i = 0; i < MAX_NODOS; i++) {
        resp = desempilha(&pilha1, &dado);
        pilha2.v[i] = dado;
    }
    printf ("\n");
    for (i = 0; i < MAX_NODOS; i++)
        printf ("Elemento %d da pilha 2: %d\n", i + 1, pilha2.v[i]);
    
    return (EXIT_SUCCESS);
}

