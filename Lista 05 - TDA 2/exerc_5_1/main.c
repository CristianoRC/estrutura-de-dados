/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on March 22, 2018, 9:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "Cheque.h"

//Função principal
int main(int argc, char** argv) {
    
    Cheque cheque1, cheque2;
    int num1, num2, codEm1, codEm2, codComp1, codComp2;
    float valor1, valor2;
    
    setlocale(LC_ALL, "portuguese");
    printf ("------Criação de Cheque------\n");
    printf ("Informe um número: ");
    scanf ("%d", &num1);
    criaCheque(num1, &cheque1);
    
    printf ("Informe outro Número: ");
    scanf ("%d", &num2);
    criaCheque(num2, &cheque2);
    printf("\n");
    
    printf ("------Valor do Cheque------\n");
    printf ("Informe um valor: ");
    scanf ("%f", &valor1);
    codEm1 = emiteCheque(valor1, &cheque1);
    if (codEm1 == 0)
        printf ("Emitido com sucesso!\n");
    else
        printf ("Erro na emissão!\n");
    printf("\n");
    
    printf ("Informe outro valor: ");
    scanf ("%f", &valor2);
    codEm2 = emiteCheque(valor2, &cheque2);
     if (codEm2 == 0)
        printf ("Emitido com sucesso!\n");
    else
        printf ("Erro na emissão!\n");
    printf("\n");
    
    exibeCheque(cheque1);
    exibeCheque(cheque2);
    valor1 = obtemValor(cheque1);
    valor2 = obtemValor(cheque2);
    if (valor1 > valor2) {
        codComp1 = compensaCheque(&cheque1);
        if (codComp1 == 0)
            printf ("Cheque %d Compensado com sucesso!\n", cheque1.numCheque);
        else
            printf ("Erro na compensação!\n");
    }
    else{
        codComp2 = compensaCheque(&cheque2);
        if (codComp2 == 0)
            printf ("Cheque %d Compensado com sucesso!\n", cheque2.numCheque);
        else
            printf ("Erro na compensação!\n");
    }
    printf("\n");
    printf ("Código do cheque %d = %d\n", cheque1.numCheque, obtemSituacao(cheque1));
    printf ("Código do cheque %d = %d\n", cheque2.numCheque, obtemSituacao(cheque2));
    printf ("Número do Cheque 1: %d\n", obtemNumero(cheque1));
    printf ("Número do Cheque 2: %d\n", obtemNumero(cheque2));
   
    return (EXIT_SUCCESS);
}
