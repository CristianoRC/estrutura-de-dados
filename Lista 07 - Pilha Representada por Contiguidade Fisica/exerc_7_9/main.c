/* 
 * File:   main.c
 * Author: Leonardo Adamoli
 *
 * Created on April 29, 2018, 9:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "PilhaCF.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    PilhaCF pilhaOpd, pilhaOpr;
    char s[21];
    int i, j, dado, resp;
    float resultado = 0;
    
    setlocale(LC_ALL, "portuguese");
    printf("Informe a Expressão: ");
    scanf ("%s", s);
    criaPilha(&pilhaOpd);
    criaPilha(&pilhaOpr);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 48 && s[i] <= 57) {
            dado = 0;
            for (j = '0'; j != s[i]; j++)
                dado++;
            resp = empilha(&pilhaOpd, dado);
        }if (s[i] == 42 || s[i] == 43 || s[i] == 45 || s[i] == 47) {
            dado = s[i];
            resp = empilha(&pilhaOpr, dado);
        }if (s[i] == 41) {
            resp = desempilha(&pilhaOpd, &dado);
            resultado = dado;
            resp = desempilha(&pilhaOpr, &dado);
            if (dado == 43) {
                resp = desempilha(&pilhaOpd, &dado);
                resultado += dado;
            }if (dado == 42) {
                resp = desempilha(&pilhaOpd, &dado);
                resultado *= dado;
            }if (dado == 45) {
                resp = desempilha(&pilhaOpd, &dado);
                resultado = dado - resultado;
            }if (dado == 47) {
                resp = desempilha(&pilhaOpd, &dado);
                resultado = dado / resultado;
            }
            resp = empilha(&pilhaOpd, resultado);
        }
    }printf ("Resultado da Expressão é = %.1f\n", resultado);
    
    return (EXIT_SUCCESS);
}

