/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on May 21, 2018, 11:35 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaDE.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    ListaDE lista;
    int op, resp, qtNodos, posicao, cod;
    Dado dado;
    
    setlocale(LC_ALL, "portuguese");
    criaLista(&lista);
    printf ("------Menu de Opções------\n");
    printf ("0.FIM\n1.INCLUI NO FIM\n2.EXIBE LISTA\n3.QUANTIDADE DE NODOS\n4.EXIBE SITUAÇÃO DA LISTA\n5.EXCLUI DO FIM\n"
            "6.INCLUI NO INÍCIO\n7.EXCLUI DO INÍCIO\n8.VERIFICA EXISTÊNCIA\n9.CONSULTA POR CÓDIGO\n"
            "10.INCLUI DEPOIS\n11.EXCLUI NODO\n");
    printf ("--------------------------\n");
    printf ("Informe um código de operação: ");
    scanf ("%d", &op);
    
    while (op > 0 && op <= 11) {
        switch (op) {
            
            case 1: //incluiNoFim
                    printf ("Informe o Código e o Peso da pessoa: ");
                    scanf ("%d %f", &dado.cod, &dado.peso);
                    resp = incluiNoFim(&lista, dado);
                    if (resp == SUCESSO)
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    else
                        printf ("ERRO!\nFALTOU MEMÓRIA!\n\n");
                    exibe(lista);
                    printf("\n");
                    break;
            
            case 2: //exibe
                    printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    exibe(lista);
                    printf("\n");
                    break;
             
            case 3: //quantidadeDeNodos
                    qtNodos = quantidadeDeNodos(lista);
                    printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    printf ("Quantidade de Nodos: %d\n", qtNodos);
                    exibe(lista);
                    printf("\n");
                    break;
            
            case 4: //exibeSituacaoDaLista
                    resp = estaVazia(lista);
                    if (resp == 1)
                        printf ("A LISTA ESTÁ VAZIA!\n\n");
                    else
                        printf ("A LISTA POSSUI 1 OU MAIS NODOS!\n\n");
                    printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    exibe(lista);
                    printf("\n");
                    break;
                 
            case 5: //excluiDoFim
                    resp = excluiDoFim(&lista, &dado);
                    if (resp == LISTA_VAZIA)
                        printf ("A LISTA ESTÁ VAZIA\n\n");
                    else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                        printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                    }
                    exibe(lista);
                    printf("\n");
                    break;
                 
            case 6: //incluiNoInicio
                    printf ("Informe o Código e o Peso da pessoa: ");
                    scanf ("%d %f", &dado.cod, &dado.peso);
                    resp = incluiNoInicio(&lista, dado);
                    if (resp == FALTOU_MEMORIA)
                        printf ("FALTOU MEMÓRIA!\n\n");
                    else 
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    exibe(lista);
                    printf("\n");
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
                    printf("\n");
                    break;
           
            case 8: //existe
                    printf ("Informe um Código: ");
                    scanf ("%d", &cod);
                    resp = existe(lista, cod);
                    if (resp == CODIGO_INEXISTENTE) {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                        printf ("NODO NÃO ESTA NA LISTA!\n");
                    }else {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                        printf ("NODO ESTA NA LISTA!\n\n");
                    }
                    exibe(lista);
                    printf("\n");
                    break;
            
            case 9: //consultaPorCodigo
                    if (estaVazia(lista) == 1)
                        printf ("A LISTA ESTÁ VAZIA!\n\n");
                    else {
                        printf ("Informe um Código: ");
                        scanf ("%d", &cod);
                        resp = consultaPorCodigo (lista, cod, &dado);
                        if (resp == SUCESSO) {
                            printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                            printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso); 
                        }else {
                            printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                            printf ("CÓDIGO INEXISTENTE!\n");
                        }
                    }    
                    exibe(lista);
                    printf("\n");
                    break;
            
            case 10: //incluiDepois
                    printf ("Informe um Código: ");
                    scanf ("%d", &cod);
                    printf ("Informe o Código e o Peso da pessoa: ");
                    scanf ("%d %f", &dado.cod, &dado.peso);
                    resp = incluiDepois(&lista, cod, dado);
                    if (resp == FALTOU_MEMORIA)
                        printf ("FALTOU MEMÓRIA!\n\n");
                    if (resp == CODIGO_INEXISTENTE)
                        printf ("CÓDIGO INEXISTENTE!\n\n");
                    if (resp == SUCESSO)
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                    exibe(lista);
                    printf("\n");
                    break;
                    
            case 11: //excluiNodo
                    printf ("Informe um Código: ");
                    scanf ("%d", &cod);
                    resp = excluiNodo(&lista, cod, &dado);
                    if (resp == CODIGO_INEXISTENTE)
                        printf ("CÓDIGO INEXISTENTE!\n\n");
                    if (resp == LISTA_VAZIA)
                        printf ("LISTA VAZIA!\n\n");
                    if (resp == SUCESSO) {
                        printf ("OPERAÇÃO REALIZADA COM SUCESSO!\n\n");
                        printf ("Código: %d | Peso: %.2f\n", dado.cod, dado.peso);
                    }
                    exibe(lista);
                    printf("\n");
                    break;
           
            default: printf("\n");
                     printf ("OPERAÇÃO INVÁLIDA!\n\n");
        }
        printf ("------Menu de Opções------\n");
        printf ("0.FIM\n1.INCLUI NO FIM\n2.EXIBE LISTA\n3.QUANTIDADE DE NODOS\n4.EXIBE SITUAÇÃO DA LISTA\n5.EXCLUI DO FIM\n"
                "6.INCLUI NO INÍCIO\n7.EXCLUI DO INÍCIO\n8.VERIFICA EXISTÊNCIA\n9.CONSULTA POR CÓDIGO\n"
                "10.INCLUI DEPOIS\n11.EXCLUI NODO\n");
        printf ("--------------------------\n");
        printf ("Informe um código de operação: ");
        scanf ("%d", &op);
        system("clear");
    }
    return (EXIT_SUCCESS);
}

