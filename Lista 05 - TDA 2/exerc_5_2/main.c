/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on March 25, 2018, 11:55 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Cheque.h"
#include "Talao.h"

int main(int argc, char** argv) {
    
    int numConta, numCheque, codOp, codEmCheque, codCompCheque, codSitCheque;
    float valorCheque, somaCheques;
    Talao talao;
    
    setlocale(LC_ALL, "portuguese");
    printf ("Informe o número da Conta: ");
    scanf ("%d", &numConta);
    printf ("Informe o Número do primeiro cheque da série: ");
    scanf ("%d", &numCheque);
    criaTalao(numConta, numCheque, &talao);
    printf ("\n");
    printf ("------Menu de Opções------\n");
    printf ("0.FIM\n1.EXIBE TALAO\n2.EMITE CHEQUE\n3.COMPENSA CHEQUE\n4.SOMA CHEQUES DO TALAO\n");
    printf ("--------------------------\n");
    printf ("Informe o código da operação: ");
    scanf ("%d", &codOp);
    
    while (codOp != 0) {
        switch(codOp) {

            case 1: exibeTalao(talao);
                    break;

            case 2: printf ("Informe o número e o valor do Cheque: ");
                    scanf ("%d %f", &numCheque, &valorCheque);
                    codEmCheque = emiteChequeDoTalao(numCheque, valorCheque, &talao);
                    if (codEmCheque == 0)
                        printf ("SUCESSO!\n");
                    else
                        printf ("ERRO!\n");
                    break;

            case 3: printf ("Informe o número do cheque: ");
                    scanf ("%d", &numCheque);
                    codCompCheque = compensaChequeDoTalao(numCheque, &talao);
                    if (codCompCheque == 0)
                        printf ("SUCESSO!\n");
                    else
                        printf ("ERRO!\n");
                    break;

            case 4: printf ("Informe o código da situação: ");
                    scanf ("%d", &codSitCheque);
                    somaCheques = somaChequesDoTalao(talao, codSitCheque);
                    printf ("Soma dos Cheques: %.2f\n", somaCheques);
                    break;
            
            default: printf ("Operação Inválida!\n");        
        }
        printf ("Informe o código da operação: ");
        scanf ("%d", &codOp);
        printf("\e[H\e[2J");
    }

    return (EXIT_SUCCESS);
}

