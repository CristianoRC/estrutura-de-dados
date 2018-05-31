/* 
 * File:   Cheque.h
 * Author: Leonardo Adamoli
 *
 * Created on March 25, 2018, 8:02 PM
 */

#ifndef CHEQUE_H
#define CHEQUE_H

typedef struct {
    
    int numCheque, situacao;
    float valor;
    
} Cheque;

void criaCheque (int numCheque, Cheque *cheque);
void exibeCheque (Cheque cheque);
int obtemSituacao (Cheque cheque);
float obtemValor (Cheque cheque);
int obtemNumero (Cheque cheque);
int compensaCheque (Cheque *cheque);
int emiteCheque (float valor, Cheque *cheque);

#endif /* CHEQUE_H */

