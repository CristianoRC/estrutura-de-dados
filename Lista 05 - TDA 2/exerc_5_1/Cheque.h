/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cheque.h
 * Author: Leonardo Adamoli
 *
 * Created on March 22, 2018, 9:13 AM
 */

#ifndef CHEQUE_H
#define CHEQUE_H

//Define a estrutura do tipo 'cheque'
typedef struct {
    
    int numCheque, situacao;
    float valor;    
} Cheque;

//Declara os protótipos
void criaCheque (int num, Cheque *cheque);
void exibeCheque (Cheque cheque);
int obtemSituacao (Cheque cheque);
float obtemValor (Cheque cheque);
int obtemNumero (Cheque cheque);
int compensaCheque (Cheque *cheque);
int emiteCheque (float valor, Cheque *cheque);

#endif /* CHEQUE_H */

