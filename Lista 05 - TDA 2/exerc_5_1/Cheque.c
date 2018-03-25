/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include "Cheque.h"

//Função criaCheque
void criaCheque (int num, Cheque *cheque) {
    
    cheque->numCheque = num;
    cheque->situacao = 0;
    cheque->valor = 0;
}
//Função exibeCheque
void exibeCheque (Cheque cheque) {
    
    if (cheque.situacao == 0)
        printf ("Número do cheque: %d | Situação: Em Branco | Valor: %.2f\n", cheque.numCheque, cheque.valor);
    if (cheque.situacao == 1)
        printf ("Número do cheque: %d | Situação: Emitido | Valor: %.2f\n", cheque.numCheque, cheque.valor);
    if (cheque.situacao == 2)
        printf ("Número do cheque: %d | Situação: Compensado | Valor: %.2f\n", cheque.numCheque, cheque.valor);
}
//Função obtemSituacao
int obtemSituacao (Cheque cheque) {
    
    if (cheque.situacao == 0)
        return 0;
    if (cheque.situacao == 1)
        return 1;
    if (cheque.situacao == 2)
        return 2;
}
//Função obtemValor
float obtemValor (Cheque cheque) {
    
    return cheque.valor;
}
//Função obtemNumero
int obtemNumero (Cheque cheque) {
    
    return cheque.numCheque;
}
//Função compensaCheque
int compensaCheque (Cheque *cheque) {
    
    if (cheque->situacao == 1) {
        cheque->situacao = 2;
        return 0;
    }else
        return 1;
}
//Função emiteCheque
int emiteCheque (float valor, Cheque *cheque) {
    
    cheque->valor = valor;
    if (cheque->situacao == 0) {
        cheque->situacao = 1;
        return 0;
    }else
        return 1;
}

