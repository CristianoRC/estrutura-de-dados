#include <stdio.h>
#include "Cheque.h"

//Função criaCheque
void criaCheque (int numCheque, Cheque *cheque) {
    
    cheque->numCheque = numCheque;
    cheque->situacao = 0;
    cheque->valor = 0;
}
//Função exibeCheque
void exibeCheque (Cheque cheque) {
    
    if (cheque.situacao == 0)
        printf ("Número do Cheque: %d | Situação: Em Branco | Valor: %.2f\n", cheque.numCheque, cheque.valor);
    if (cheque.situacao == 1)
        printf ("Número do Cheque: %d | Situação: Emitido | Valor: %.2f\n", cheque.numCheque, cheque.valor);
    if (cheque.situacao == 2)
        printf ("Número do Cheque: %d | Situação: Compensado | Valor: %.2f\n", cheque.numCheque, cheque.valor);
}
//Função obtemSituação
int obtemSituacao (Cheque cheque) {
    
    if (cheque.situacao == 2)
        return 2;
    else
        if (cheque.situacao == 1)
            return 1;
        else
            return 0;
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
    
    if (cheque->situacao == 0) {
        cheque->valor = valor;
        cheque->situacao = 1;
        return 0;
    }else
        return 1;
}