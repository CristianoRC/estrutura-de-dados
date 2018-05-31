/* 
 * File:   ListaCF.h
 * Author: Leonardo Adamoli
 *
 * Created on March 30, 2018, 4:27 PM
 */

#ifndef LISTACF_H
#define LISTACF_H
#define MAX_NODOS 5
#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define POSICAO_INVALIDA 3
#define CODIGO_INEXISTENTE 4

typedef struct {
    
    int cod;
    float peso;
    
} Dado;

typedef struct {
    
    int n;
    Dado v[MAX_NODOS];
    
} ListaCF;

void criaLista (ListaCF *lista);
int incluiNoFim (Dado dado, ListaCF *lista);
void exibe (ListaCF lista);
int quantidadeDeNodos (ListaCF lista);
int estaCheia (ListaCF lista);
int estaVazia (ListaCF lista);
int excluiDoFim (ListaCF *lista, Dado *dado);
int incluiNoInicio (Dado dado, ListaCF *lista);
int excluiDoInicio (ListaCF *lista, Dado *dado);
int consultaPorPosicao (ListaCF lista, int posicao, Dado *dado);
int existe (ListaCF lista, int codigo);
int consultaPorCodigo (ListaCF lista, int codigo, Dado *dado);
int incluiNaPosicao (int posicao, Dado dado, ListaCF *lista);
int excluiDaPosicao (int posicao, ListaCF *lista, Dado *dado);
int incluiAntes (int codigo, Dado dado, ListaCF *lista);
int excluiNodo (int codigo, Dado *dado, ListaCF *lista);

#endif /* LISTACF_H */

