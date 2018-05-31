/* 
 * File:   Talao.h
 * Author: Leonardo Adamoli
 *
 * Created on March 25, 2018, 11:56 PM
 */

#ifndef TALAO_H
#define TALAO_H

typedef struct {
    
    int numConta;
    Cheque cheque[10];
    
} Talao;

void criaTalao (int numConta, int numCheque, Talao *talao);
void exibeTalao (Talao talao);
int emiteChequeDoTalao (int numCheque, float valorCheque, Talao *talao);
int compensaChequeDoTalao (int numCheque, Talao *talao);
float somaChequesDoTalao (Talao talao, int situacao);

#endif /* TALAO_H */

