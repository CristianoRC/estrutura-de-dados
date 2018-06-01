/* 
 * File:   ListaDE.h
 * Author: Leonardo Adamoli
 *
 * Created on May 21, 2018, 11:35 AM
 */

#ifndef LISTADE_H
#define LISTADE_H
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
    Nodo *ant;
};

typedef struct {
    
    Nodo *inicio;
    Nodo *fim;
    int n;
    
} ListaDE;

void criaLista(ListaDE *lista);
int incluiNoInicio(ListaDE *lista, Dado dado);
void exibe(ListaDE lista);
int quantidadeDeNodos(ListaDE lista);
int estaVazia(ListaDE lista);
int excluiDoInicio(ListaDE *lista, Dado *dado);
int incluiNoFim(ListaDE *lista, Dado dado);
int excluiDoFim(ListaDE *lista, Dado *dado);
int existe(ListaDE lista, int cod);
int consultaPorCodigo(ListaDE lista, int cod, Dado *dado);
int incluiDepois(ListaDE *lista, int cod, Dado dado);
int excluiNodo(ListaDE *lista, int cod, Dado *dado);

#endif /* LISTADE_H */

