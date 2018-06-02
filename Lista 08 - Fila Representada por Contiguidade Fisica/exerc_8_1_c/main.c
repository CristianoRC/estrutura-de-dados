/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on June 1, 2018, 3:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaCF-Circ.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    FilaCF_Circ fila;
    int dado, operacao, resp;
    
    setlocale(LC_ALL, "portuguese");
    criaFila(&fila);
    printf ("------ MENU DE OPÇÕES ------\n");
    printf ("0.FIM\n1.INSERE\n2.RETIRA\n3.ESTÁ CHEIA?\n4.ESTÁ VAZIA?\n5.EXIBE\n");
    printf("----------------------------\n\n");
    printf ("Informe a operação desejada: ");
    scanf ("%d", &operacao);
    while (operacao > 0 && operacao <= 5) {
        switch (operacao) {
            
            case 1: //Função insere
                    printf ("Informe um número: ");
                    scanf ("%d", &dado);
                    resp = insere(&fila, dado);
                    if (resp == SUCESSO)
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    else
                        printf ("ERRO!\nA FILA ESTÁ CHEIA!\n\n");
                    break;
                    
            case 2: //Função retira
                    resp = retira(&fila, &dado);
                    if (resp == SUCESSO) {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                        printf ("DADO REMOVIDO -> %d\n", dado);
                    }    
                    else
                        printf ("ERRO!\nA FILA ESTÁ VAZIA!\n\n");
                    break;
                    
            case 3: //Função estaCheia
                    resp = estaCheia(fila);
                    if (resp == FILA_CHEIA)
                        printf ("A FILA ESTÁ CHEIA!\n\n");
                    else
                        printf ("FILA AINDA COM ESPAÇOS!\n\n");
                    break;
            
            case 4: //Função estaVazia
                    resp = estaVazia(fila);
                    if (resp == FILA_VAZIA)
                        printf ("A FILA ESTA VAZIA!\n\n");
                    else
                        printf ("FILA COM UM OU MAIS NODO!\n\n");
                    break;
            
            case 5: //Exibe
                    exibe(fila);
                    printf ("\n");
                    break;
            
            default: printf ("OPERAÇÃO INVÁLIDA!\n");
        }
        printf ("------ MENU DE OPÇÕES ------\n");
        printf ("0.FIM\n1.INSERE\n2.RETIRA\n3.ESTÁ CHEIA?\n4.ESTÁ VAZIA?\n5.EXIBE\n");
        printf("----------------------------\n\n");
        printf ("Informe a operação desejada: ");
        scanf ("%d", &operacao);
        system("clear");
    }
    
    return (EXIT_SUCCESS);
}

