/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on March 25, 2018, 7:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Cheque.h"

int main(int argc, char** argv) {
    
    int num1, num2, codEm1, codEm2, codComp1, codComp2;
    Cheque cheque1, cheque2;
    float valor1, valor2;
    
    setlocale(LC_ALL, "portuguese");
    printf ("------Criação dos Cheques------\n");
    printf ("Informe um número: ");
    scanf ("%d", &num1);
    criaCheque(num1, &cheque1);
    printf ("Informe outro Número: ");
    scanf ("%d", &num2);
    criaCheque(num2, &cheque2);
    printf ("\n");
    
    printf ("------Valores dos Cheques------\n");
    printf ("Informe o valor do cheque %d: ", cheque1.numCheque);
    scanf ("%f", &valor1);
    codEm1 = emiteCheque(valor1, &cheque1);
    if (codEm1 == 0)
        printf ("Cheque %d emitido com sucesso!\n", cheque1.numCheque);
    else
        printf ("Operação não permitida!\n");
    printf ("\n");
    
    printf ("Informe o valor do cheque %d: ", cheque2.numCheque);
    scanf ("%f", &valor2);
    codEm2 = emiteCheque(valor2, &cheque2);
    if (codEm2 == 0)
        printf ("Cheque %d emitido com sucesso!\n", cheque2.numCheque);
    else
        printf ("Operação não permitida!\n");
    printf ("\n");
    
    exibeCheque(cheque1);
    exibeCheque(cheque2);
    if (obtemValor(cheque1) > obtemValor(cheque2)) {
        codComp1 = compensaCheque(&cheque1);
        if (codComp1 == 0)
            printf ("Cheque %d compenssado com sucesso!\n", cheque1.numCheque);
        else
            printf ("Operação não permitida\n");
    }else{
        codComp2 = compensaCheque(&cheque2);
        if (codComp2 == 0)
            printf ("Cheque %d compenssado com sucesso!\n", cheque2.numCheque);
        else
            printf ("Operação não permitida\n");
    }
    printf ("\n");
    printf ("Código do cheque %d: %d\n", cheque1.numCheque, obtemSituacao(cheque1));
    printf ("Código do cheque %d: %d\n", cheque2.numCheque, obtemSituacao(cheque2));
    printf ("Número do Cheque 1: %d\n", cheque1.numCheque);
    printf ("Número do Cheque 2: %d\n", cheque2.numCheque);
   
    return (EXIT_SUCCESS);
}

