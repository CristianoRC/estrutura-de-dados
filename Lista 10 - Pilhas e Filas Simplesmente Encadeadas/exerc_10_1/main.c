/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on May 19, 2018, 4:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaSE.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    PilhaSE pilha;
    int dado, resp, cod;
	
    setlocale(LC_ALL, "portuguese");
    criaPilha(&pilha);
    printf ("------Menu de Operações------\n\n");
    printf ("0.FIM\n1.EMPILHA\n2.DESEMPILHA\n3.CONSULTA\n4.EXIBE SITUAÇÃO DA LISTA\n\n");
    printf ("Informe o Código da Operação: ");
    scanf ("%d", &cod);
    printf ("\n");
    while (cod >= 1 && cod <= 5) {
        switch (cod) {
            //Cases
            case 1: printf ("Informe um dado para sem armazenado na Pilha: ");
                    scanf ("%d", &dado);
                    resp = empilha(&pilha, dado);
                    if (resp == SUCESSO)
                        printf ("ARMAZENADO COM SUCESSO!\n");
                    else
                        printf ("ERRO!\nFALTOU MEMÓRIA!\n");
                    printf ("\n");
                    break;
				
            case 2: resp = desempilha(&pilha, &dado);
                    if (resp == SUCESSO) {
			printf ("REMOVIDO COM SUCESSO!\n");
			printf ("O DADO EXCLUÍDO FOI: %d\n\n", dado);
                    }else
			printf ("A PILHA ESTÁ VAZIA!\n");
                    break;
				
            case 3: resp = consulta(pilha, &dado);
                    if (resp == SUCESSO)
			printf ("DADO DO TOPO: %d\n", dado);
                    else
			printf ("PILHA VAZIA!\n");
                    break;
                    
            case 4: resp = estaVazia(pilha);
                    if (resp == 1)
                        printf ("PILHA VAZIA!\n");
                    else
                        printf ("PILHA COM UM OU MAIS NODOS!\n");
                    break;
            
            /*case 5: exibe(pilha);	
                    printf ("\n");	
                    break;	
            */         
            
            default: printf ("OPERAÇÃO INVÁLIDA!\n");        
        }
	printf ("0.FIM\n1.EMPILHA\n2.DESEMPILHA\n3.CONSULTA\n4.EXIBE SITUAÇÃO DA LISTA\n\n");
        printf ("Informe o Código da Operação: ");
        scanf ("%d", &cod);
        printf ("\n");
        //Limpa a tela
        printf("\e[H\e[2J");
    }

    return (EXIT_SUCCESS);
}

