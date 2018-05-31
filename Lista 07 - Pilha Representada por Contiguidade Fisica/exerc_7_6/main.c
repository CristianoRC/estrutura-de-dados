/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 22, 2018, 4:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    PilhaCF pilha1, pilha2, pilhaAux;
    int i, dado, resp;
    
    setlocale(LC_ALL, "portuguese");
    printf ("------ CRIAÇÃO DAS PILHAS ------\n");
    criaPilha(&pilha1);
    criaPilha(&pilha2);
    criaPilha(&pilhaAux);
    for (i = 0; i < MAX_NODOS; i++) { //Carrega a pilha 1
        printf ("Informe o elemento %d da Pilha 1: ", i + 1);
        scanf ("%d", &dado);
        resp = empilha(&pilha1, dado);
        if (resp == SUCESSO)
            printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
        else
            printf ("PILHA CHEIA!\n");
    }
    for (i = pilha1.topo; i >= 0; i--) { //Tira os elementos da pilha 1 e joga em uma pilhaAux
        resp = desempilha(&pilha1, &dado);
        resp = empilha(&pilhaAux, dado);
    }
    for (i = pilhaAux.topo; i >= 0; i--) { //Tira da pilhaAux e joga na pilha2, mantendo a ordem original da pilha 1
        resp = desempilha(&pilhaAux, &dado);
        resp = empilha(&pilha2, dado);
    }
    printf("\n");
    printf ("------ CONTEÚDO DA PILHA 2 ------\n");
    for (i = 0; i <= pilha2.topo; i++) //Exibe pilha 2
        printf ("ELEMENTO %d: %d\n", i + 1, pilha2.v[i]);
    
    return (EXIT_SUCCESS);
}

