/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 8, 2018, 11:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    PilhaCF pilha;
    int dado, i, resp, x;
    
    setlocale(LC_ALL, "portuguese");
    criaPilha(&pilha);
    for (i = 0; i < 2; i++) {
        printf ("Informe o dado %d: ", i + 1);
        scanf ("%d", &dado);
        resp = empilha(&pilha, dado);
        if (resp == PILHA_CHEIA)
            printf ("ERRO!\nPILHA CHEIA!\n");
        else
            printf ("SUCESSO!\n");
    }
    printf ("\n");
    resp = desempilha(&pilha, &dado);
    if (resp == SUCESSO)
        printf ("O DADO EXCLUIDO FOI: %d\n", pilha.v[pilha.topo + 1]);
    else
        printf ("ERRO!\nPILHA VAZIA!\n");
    printf ("\n");
    resp = desempilha(&pilha, &dado);
    if (resp == SUCESSO)
        x = pilha.v[pilha.topo + 1];
    else
        printf ("ERRO!\nPILHA VAZIA!\n");
    printf ("------Variável X------\n");
    printf ("CONTEÚDO: %d\n", x); 
    printf ("\n\n");
    printf ("------Pilha------\n");
    resp = estaVazia(pilha);
    if (resp == PILHA_VAZIA)
        printf ("A PILHA ESTÁ VAZIA!\n");
    else
        printf ("MAIS DE UM NODOD!\n");
    
    return (EXIT_SUCCESS);
}

