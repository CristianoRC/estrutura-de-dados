#include <stdio.h>
#include "Cheque.h"
#include "Talao.h"

//Função criaTalao
void criaTalao (int numConta, int numCheque, Talao *talao) {
    
    int i;
    
    talao->numConta = numConta;
    for (i = 0; i < 10; i++) {
        criaCheque(numCheque, &talao->cheque[i]);
        numCheque++;
    }
}
//Função exibeTalao
void exibeTalao (Talao talao) {
    
    int i;
    
    printf ("Número da conta: %d\n", talao.numConta);
    for (i = 0; i < 10; i++)
        exibeCheque(talao.cheque[i]);
}
//Função emiteChequeDoTalao
int emiteChequeDoTalao (int numCheque, float valorCheque, Talao *talao) {
    
    int i, f = 0;
    
    for (i = 0; i < 10; i++) {
        if (obtemNumero(talao->cheque[i]) == numCheque) {
           f = 1; 
           emiteCheque(valorCheque, &talao->cheque[i]);
           break;
        }
    }if (f == 1)
        return 0;
    else
        return 1;
}
//Função compensaChequeDoTalao
int compensaChequeDoTalao (int numCheque, Talao *talao) {
    
    int i, f = 0;
    
    for (i = 0; i < 10; i++) {
        if (obtemNumero(talao->cheque[i]) == numCheque) {
            f = 1;
            compensaCheque(&talao->cheque[i]);
            break;
        }
    }if (f == 1)
        return 0;
    else
        return 1;
}
//Função somaChequesDoTalao
float somaChequesDoTalao (Talao talao, int situacao) {
    
    int i;
    float soma = 0;
    
    for (i = 0; i < 10; i++) {
        if (obtemSituacao(talao.cheque[i]) == situacao)
            soma += obtemValor(talao.cheque[i]);       
    }
    return soma;
}