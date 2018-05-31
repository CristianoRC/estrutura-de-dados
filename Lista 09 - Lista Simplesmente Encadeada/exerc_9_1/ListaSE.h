/* 
 * File:   ListaSE.h
 * Author: Leonardo Adamoli
 *
 * Created on May 9, 2018, 8:39 AM
 */

#ifndef LISTASE_H
#define LISTASE_H
#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    
    int cod;
    float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
    
    Dado info;
    Nodo *prox;
};

typedef struct {
    
    Nodo *inicio;
} ListaSE;

void criaLista(ListaSE *lista);
int incluiNoInicio(ListaSE *lista, Dado dado);
void exibe(ListaSE lista);
int quantidadeDeNodos(ListaSE lista);
int estaVazia(ListaSE lista);
int excluiDoInicio(ListaSE *lista, Dado *dado);
int incluiNoFim(ListaSE *lista, Dado dado);
int excluiDoFim(ListaSE *lista, Dado *dado);
int existe(ListaSE lista, int cod);
int consultaPorCodigo(ListaSE lista, int cod, Dado *dado);
int incluiDepois(ListaSE *lista, int cod, Dado dado);
int excluiNodo(ListaSE *lista, int cod, Dado *dado);

#endif /* LISTASE_H */

