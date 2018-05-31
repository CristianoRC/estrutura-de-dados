/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 24, 2018, 8:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    FilaCF fila;
    int dado, operacao, resp, i;
    
    setlocale(LC_ALL, "portuguese");
    criaFila(&fila);
    printf ("------ MENU DE OPÇÕES ------\n");
    printf ("0.FIM\n1.INSERE\n2.RETIRA\n3.EXIBE\n");
    printf("----------------------------\n\n");
    printf ("Informe a operação desejada: ");
    scanf ("%d", &operacao);
    while (operacao != 0) {
        switch (operacao) {
            case 1: printf ("Informe um número: ");
                    scanf ("%d", &dado);
                    resp = insere(&fila, dado);
                    if (resp == SUCESSO)
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                    else
                        printf ("ERRO!\nA FILA ESTÁ CHEIA!\n");
                    break;
                    
            case 2: resp = retira(&fila, &dado);
                    if (resp == SUCESSO) {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("DADO REMOVIDO -> %d\n", dado);
                    }    
                    else
                        printf ("ERRO!\nA FILA ESTÁ CHEIA!\n");
                    break;
                    
            case 3: printf("------ SITUAÇÃO DA FILA ------\n");
                    printf ("FRENTE: %d | RÉ: %d\n", fila.frente, fila.re);
                    if (fila.frente == 0)
                        for (i = 0; i <= fila.re; i++)
                            printf ("ELEMENTO %d: %d\n", i, fila.v[i]);
                    else
                        for (i = 0; i < fila.re; i++)
                            printf ("ELEMENTO %d: %d\n", i, fila.v[i]);
                    break;
                    
            default: printf ("OPERAÇÃO INVÁLIDA!\n");
        }
        printf ("------ MENU DE OPÇÕES ------\n");
        printf ("0.FIM\n1.INSERE\n2.RETIRA\n3.EXIBE\n");
        printf("----------------------------\n\n");
        printf ("Informe a operação desejada: ");
        scanf ("%d", &operacao);
    }

    return (EXIT_SUCCESS);
}

