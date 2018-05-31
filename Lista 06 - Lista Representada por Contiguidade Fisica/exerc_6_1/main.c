/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on March 30, 2018, 4:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    ListaCF lista;
    int op, resp, qtNodos, posicao, cod;
    Dado dado;
    
    setlocale(LC_ALL, "portuguese");
    criaLista(&lista);
    printf ("------Menu de Opções------\n");
    printf ("0.FIM\n1.INCLUI NO FIM\n2.EXIBE LISTA\n3.QUANTIDADE DE NODOS\n4.EXIBE SITUAÇÃO DA LISTA\n5.EXCLUI DO FIM\n"
            "6.INCLUI NO INÍCIO\n7.EXCLUI DO INÍCIO\n8.CONSULTA POR POSIÇÃO\n9.VERIFICA EXISTÊNCIA\n10.CONSULTA POR CÓDIGO\n"
            "11.INCLUI NA POSIÇÃO\n12.EXCLUI DA POSIÇÃO\n13.INCLUI ANTES\n14.EXCLUI NODO\n");
    printf ("--------------------------\n");
    printf ("Informe um código de operação: ");
    scanf ("%d", &op);
    
    while (op > 0 && op <= 14) {
        switch (op) {
            case 1: //incluiNoFim
                    printf ("Informe o Código e o Peso da pessoa: ");
                    scanf ("%d %f", &dado.cod, &dado.peso);
                    resp = incluiNoFim(dado, &lista);
                    if (resp == SUCESSO)
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                    else
                        printf ("ERRO!\nA LISTA ESTÁ CHEIA!\n");
                    exibe(lista);
                    break;
                    
            case 2: //exibe
                    printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                    exibe(lista);
                    break;
            
            case 3: //quantidadeDeNodos
                    qtNodos = quantidadeDeNodos(lista);
                    printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                    printf ("Quantidade de Nodos: %d\n", qtNodos);
                    exibe(lista);
                    break;
            
            case 4: //exibeSituacaoDaLista
                    resp = estaCheia(lista);
                    if (resp == 1)
                        printf ("A LISTA ESTÁ CHEIA!\n");
                    else {
                        resp = estaVazia(lista);
                        if (resp == 1)
                            printf ("A LISTA ESTÁ VAZIA!\n");
                        else
                            printf ("A LISTA POSSUI 1 OU MAIS NODOS!\n");
                    }
                    printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                    exibe(lista);
                    break;
                    
            case 5: //excluiDoFim
                    resp = excluiDoFim(&lista, &dado);
                    if (resp == LISTA_VAZIA)
                        printf ("A LISTA ESTÁ VAZIA\n");
                    else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                    }
                    exibe(lista);
                    break;
            
            case 6: //incluiNoInicio
                    printf ("Informe o Código e o Peso da pessoa: ");
                    scanf ("%d %f", &dado.cod, &dado.peso);
                    resp = incluiNoInicio(dado, &lista);
                    if (resp == LISTA_CHEIA)
                        printf ("A LISTA ESTÁ CHEIA!\n");
                    else 
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                    exibe(lista);
                    break;
            
            case 7: //excluiDoInicio
                    resp = excluiDoInicio(&lista, &dado);
                    if (resp == LISTA_VAZIA)
                        printf ("A LISTA ESTÁ VAZIA\n");
                    else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                    }
                    exibe(lista);
                    break;
                    
            case 8: //consultaPorPosicao
                    printf ("Informe uma Posição: ");
                    scanf ("%d", &posicao);
                    resp = consultaPorPosicao(lista, posicao, &dado);
                    if (resp == POSICAO_INVALIDA)
                        printf ("POSIÇÃO INVÁLIDA!\n");
                    else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                    }
                    exibe(lista);
                    break;
                    
            case 9: //existe
                    printf ("Informe um Código: ");
                    scanf ("%d", &cod);
                    resp = existe(lista, cod);
                    if (resp == 0) {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("NODO NÃO ESTA NA LISTA!\n");
                    }else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("NODO ESTA NA LISTA!\n");
                    }
                    exibe(lista);
                    break;
            
            case 10: //consultaPorCodigo
                     printf ("Informe um Código: ");
                     scanf ("%d", &cod);
                     resp = consultaPorCodigo (lista, cod, &dado);
                     if (resp == SUCESSO) {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso); 
                     }else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                        printf ("CÓDIGO INEXISTENTE!\n");
                     }
                     exibe(lista);
                     break;
            
            case 11: //incluiNaPosicao
                     printf ("Informe uma Posição: ");
                     scanf ("%d", &posicao);
                     printf ("Informe o Código e o Peso da pessoa: ");
                     scanf ("%d %f", &dado.cod, &dado.peso);
                     resp = incluiNaPosicao(posicao, dado, &lista);
                     if (resp == LISTA_CHEIA)
                         printf ("ERRO!\nA LISTA ESTÁ CHEIA!\n");
                     if (resp == POSICAO_INVALIDA)
                         printf ("ERRO!\nPOSICAO INVÁLIDA!\n");
                     if (resp == SUCESSO)
                         printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                     exibe(lista);
                     break;
            
            case 12: //excluiDaPosicao
                     printf ("Informe uma Posição: ");
                     scanf ("%d", &posicao);
                     resp = excluiDaPosicao(posicao, &lista, &dado);
                     if (resp == POSICAO_INVALIDA)
                         printf ("POSIÇÃO INVÁLIDA!\n");
                     else {
                         printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                         printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                     }
                     exibe(lista);
                     break;
            
            case 13: //incluiAntes
                     printf ("Informe um Código: ");
                     scanf ("%d", &cod);
                     printf ("Informe o Código e o Peso da pessoa: ");
                     scanf ("%d %f", &dado.cod, &dado.peso);
                     resp = incluiAntes(cod, dado, &lista);
                     if (resp == LISTA_CHEIA)
                         printf ("A LISTA ESTÁ CHEIA!\n");
                     if (resp == CODIGO_INEXISTENTE)
                         printf ("CÓDIGO INEXISTENTE!\n");
                     if (resp == SUCESSO)
                         printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                     exibe(lista);
                     break;
                     
            case 14: //excluiNodo
                     printf ("Informe um Código: ");
                     scanf ("%d", &cod);
                     resp = excluiNodo(cod, &dado, &lista);
                     if (resp == CODIGO_INEXISTENTE)
                         printf ("CÓDIGO INEXISTENTE!\n");
                     else {
                         printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n");
                         printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                     }
                     exibe(lista);
                     break;
            
            default: printf ("OPERAÇÃO INVÁLIDA!\n");
        }
        printf ("--------------------------\n\n");
        printf ("Informe um código de operação: ");
        scanf ("%d", &op);
        //Limpa a tela
        printf("\e[H\e[2J");
    }

    return (EXIT_SUCCESS);
}

