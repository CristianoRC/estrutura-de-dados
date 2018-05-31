/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 29, 2018, 6:05 PM
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
    int dado, resp, cod;
    
    setlocale(LC_ALL, "portuguese");
    criaPilha(&pilha);
    printf ("------ MENU DE OPÇÕES ------\n");
    printf ("0.FIM\n1.EMPILHA\n2.DESEMPILHA\n");
    printf ("---------------------------\n\n");
    printf ("Informe o código da operação: ");
    scanf ("%d", &cod);
    while (cod != 0) {
        switch (cod) {
            case 1: printf ("Informe um número para empilhar: ");
                    scanf ("%d", &dado);
                    resp = empilha(&pilha, dado);
                    if (resp == SUCESSO)
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    else
                        printf ("ERRO!\nA PILHA ESTÁ CHEIA!\n\n");
                    exibe(pilha);
                    printf ("\n");
                    break;
            
            case 2: resp = desempilha(&pilha, &dado);
                    if (resp == SUCESSO) {
                        printf ("Dado desempilhado -> %d\n", dado);
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    }else
                        printf ("ERRO!\nA PILHA ESTÁ VAZIA!\n\n");
                    exibe(pilha);
                    printf ("\n");
                    break;
            
            default: printf ("OPERAÇÃO INVÁLIDA!\n");        
        }
        printf ("------ MENU DE OPÇÕES ------\n");
        printf ("0.FIM\n1.EMPILHA\n2.DESEMPILHA\n\n");
        printf ("---------------------------\n");
        printf ("Informe o código da operação: ");
        scanf ("%d", &cod);
    }

    return (EXIT_SUCCESS);
}

