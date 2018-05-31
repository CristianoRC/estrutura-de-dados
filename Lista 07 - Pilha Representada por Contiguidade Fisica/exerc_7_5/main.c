/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 14, 2018, 11:35 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int x, i, dado, resp;
    PilhaCF pilha;
    
    setlocale(LC_ALL, "portuguese");
    criaPilha(&pilha);
    for (i = 0; i < 3; i++) {
        printf ("Informe o elemento %d da Pilha: ", i + 1);
        scanf ("%d", &dado);
        resp = empilha(&pilha, dado);
    }
    for (i = pilha.topo; i >= 0; i--) {
        printf ("DESEMPILHA\n");
        resp = desempilha(&pilha, &dado);
    }    
    printf ("\n");
    x = pilha.v[pilha.topo + 1];
    printf ("O Topo da Pilha é: %d\n", pilha.topo);
    printf ("O Conteúdo da Variável X é: %d\n", x);
          
    return (EXIT_SUCCESS);
}

