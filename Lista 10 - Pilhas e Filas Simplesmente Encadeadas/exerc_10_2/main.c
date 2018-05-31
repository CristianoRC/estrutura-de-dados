/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on May 21, 2018, 12:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FilaSE.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    FilaSE fila;
    int dado, cod, resp;
    
    setlocale(LC_ALL, "portuguese");
    criaFila(&fila);
    printf ("------Menu de Operações------\n\n");
    printf ("0.FIM\n1.INSERE\n2.RETIRA\n3.CONSULTA\n4.EXIBE SITUAÇÃO DA FILA\n\n");
    printf ("Informe o Código da Operação: ");
    scanf ("%d", &cod);
    printf ("\n");
    while (cod > 0 && cod <= 4) {
        switch (cod) {
            //Cases
            case 1: printf ("Informe um dado para sem armazenado na Fila: ");
                    scanf ("%d", &dado);
                    resp = insere(&fila, dado);
                    if (resp == SUCESSO)
                        printf ("ARMAZENADO COM SUCESSO!\n");
                    else
                        printf ("ERRO!\nFALTOU MEMÓRIA!\n");
                    printf ("\n");
                    break;
				
            case 2: resp = retira(&fila, &dado);
                    if (resp == SUCESSO) {
			printf ("REMOVIDO COM SUCESSO!\n");
			printf ("O DADO EXCLUÍDO FOI: %d\n\n", dado);
                    }else
			printf ("A FILA ESTÁ VAZIA!\n");
                    break;
				
            case 3: resp = consulta(fila, &dado);
                    if (resp == SUCESSO)
			printf ("DADO DA FRENTE: %d\n", dado);
                    else
			printf ("FILA VAZIA!\n");
                    break;
                    
            case 4: resp = estaVazia(fila);
                    if (resp == 1)
                        printf ("FILA VAZIA!\n");
                    else
                        printf ("FILA COM UM OU MAIS NODOS!\n");
                    break;       
            
            default: printf ("OPERAÇÃO INVÁLIDA!\n");
        }
        printf ("------Menu de Operações------\n\n");
        printf ("0.FIM\n1.INSERE\n2.RETIRA\n3.CONSULTA\n4.EXIBE SITUAÇÃO DA FILA\n\n");
        printf ("Informe o Código da Operação: ");
        scanf ("%d", &cod);
        printf ("\n");
        //Limpa a tela
        printf("\e[H\e[2J");
    }    

    return (EXIT_SUCCESS);
}

