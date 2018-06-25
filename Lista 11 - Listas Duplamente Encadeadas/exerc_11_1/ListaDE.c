#include <stdio.h>
#include <stdlib.h>
#include "ListaDE.h"

//Função criaLista
void criaLista(ListaDE *lista) {
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->n = 0;
}

//Função incluiNoInicio
int incluiNoInicio(ListaDE *lista, Dado dado) {
    
    Nodo *pNodo;
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pNodo->info = dado;
        pNodo->prox = lista->inicio;
        pNodo->ant = NULL;
        lista->inicio = pNodo;
        if (lista->n == 0)
            lista->fim = pNodo;
        else 
            lista->inicio->prox->ant = pNodo;
        lista->n++;
        return SUCESSO;
    }
}

//Função exibe
void exibe(ListaDE lista) {
    
    Nodo *pAux;
    int pos = 1;
    
    pAux = lista.inicio;
    if (pAux == NULL)
        printf ("ERRO!\nLISTA VAZIA!\n");
    else {
        while (pAux != NULL) {
            printf ("Endereço Anterior: %p | Endereço atual: %p | Posição: %d | Código: %d | Peso: %.2f | Próximo Endereço: %p\n", pAux->ant, pAux, pos, pAux->info.cod, pAux->info.peso, pAux->prox);
            pos++;
            pAux = pAux->prox;
        }
    }
}

//Função quantidadeDeNodos
int quantidadeDeNodos(ListaDE lista) {
    
    if (lista.n == 0)
        return 0;
    else
        return lista.n;
}

//Função estaVazia
int estaVazia(ListaDE lista) {
    
    if (lista.n == 0)
        return 1;
    else
        return 0;
}

//Função existe
int existe(ListaDE lista, int cod) {
    
    Nodo *pAux;
    int flag = 0;
    
    pAux = lista.inicio;
    if (pAux == NULL)
        return LISTA_VAZIA;
    else {
        while (pAux != NULL) {
            if (pAux->info.cod == cod) {
                flag = 1;
                break;
            }
            pAux = pAux->prox;
        }
        if (flag == 1)
            return SUCESSO;
        else
            return CODIGO_INEXISTENTE;
    }
}

//Função incluiNoFim
int incluiNoFim(ListaDE *lista, Dado dado) {
    
    Nodo *pNodo;
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pNodo->info = dado;
        pNodo->prox = NULL;
        if (lista->n == 0) {
            pNodo->ant = NULL;
            lista->inicio = pNodo;
        }else {
            pNodo->ant = lista->fim;
            lista->fim->prox = pNodo;
        }    
        lista->fim = pNodo;    
        lista->n++;
        return SUCESSO;
    }
}

//Função excluiDoFim
int excluiDoFim(ListaDE *lista, Dado *dado) {
    
    Nodo *pNodo;
    
    if (estaVazia(*lista) == 1)
        return LISTA_VAZIA;
    else {
        pNodo = lista->fim;
        *dado = pNodo->info;
        if (pNodo->ant == NULL && pNodo->prox == NULL && lista->n == 1) {
            lista->inicio = NULL;
            lista->fim = NULL;
        }else {
            pNodo->ant->prox = NULL;
            lista->fim = pNodo->ant;
        }
        lista->n--;
        free(pNodo);
        return SUCESSO;
    }
}

//Função consultaPorCodigo
int consultaPorCodigo(ListaDE lista, int cod, Dado *dado) {
    
    Nodo *pAux;
    int flag = 0;
    
    pAux = lista.inicio;
    while (pAux != NULL) {
        if (pAux->info.cod == cod) {
            flag = 1;
            break;
        }
        pAux = pAux->prox;
    }
    if (flag == 1) {
        *dado = pAux->info;
        return SUCESSO;
    }else
        return CODIGO_INEXISTENTE;
}

//Função excluiDoInicio
int excluiDoInicio(ListaDE *lista, Dado *dado) {
    
    Nodo *pNodo;
    
    if (estaVazia(*lista) == 1)
        return LISTA_VAZIA;
    else {
        pNodo = lista->inicio;
        *dado = pNodo->info;
        if (lista->n == 1) {
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->n--;
            free(pNodo);
        }else {
            lista->inicio = pNodo->prox;
            pNodo->prox->ant = NULL;
            lista->n--;
            free(pNodo);
        }
        return SUCESSO;
    }
}

//Função incluiDepois
int incluiDepois(ListaDE *lista, int cod, Dado dado) {
    
    Nodo *pNodo, *pAux;
    int flag = 1; 
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pAux = lista->inicio;
        pNodo->info = dado;
        while (pAux != NULL) {
            if (pAux->info.cod == cod) {
                if (pAux->ant == NULL && pAux->prox == NULL && lista->n == 1) {
                    pNodo->ant = pAux;
                    pNodo->prox = NULL;
                    pAux->prox = pNodo;
                    lista->fim = pNodo;
                    lista->n++;
                    flag = 1;
                    break;
                }
                if (pAux->ant != NULL && pAux->prox == NULL && lista->n > 1) {
                    pNodo->ant = pAux;
                    pNodo->prox = NULL;
                    pAux->prox = pNodo;
                    lista->fim = pNodo;
                    lista->n++;
                    flag = 1;
                    break;
                }
                if (pAux->ant != NULL && pAux->prox != NULL && lista->n > 1 || pAux->ant == NULL && pAux->prox != NULL && lista->n > 1) {
                    pNodo->ant = pAux;
                    pNodo->prox = pAux->prox;
                    pAux->prox->ant = pNodo;
                    pAux->prox = pNodo;
                    lista->n++;
                    flag = 1;
                    break;
                }
            }
            pAux = pAux->prox;
        }
        if (flag == 1)
            return SUCESSO;
        else
            return CODIGO_INEXISTENTE;
    }
}

//Função excluiNodo
int excluiNodo (ListaDE *lista, int cod, Dado *dado) {
    
    Nodo *pNodo;
    int flag = 0;
    
    pNodo = lista->inicio;
    if (estaVazia(*lista) == 1)
        return LISTA_VAZIA;
    else {
        while (pNodo != NULL) {
            if (pNodo->info.cod == cod) {
                *dado = pNodo->info;
                if (pNodo->ant == NULL && pNodo->prox == NULL && lista->n == 1) {
                    lista->inicio = NULL;
                    lista->fim = NULL;
                    lista->n--;
                    free(pNodo);
                    flag = 1;
                    break;
                }
                if (pNodo->ant == NULL && pNodo->prox != NULL && lista->n > 1) {
                    lista->inicio = pNodo->prox;
                    pNodo->prox->ant = NULL;
                    lista->n--;
                    free(pNodo);
                    flag = 1;
                    break;
                }
                if (pNodo->ant != NULL && pNodo->prox != NULL && lista->n > 1) {
                    pNodo->ant->prox = pNodo->prox;
                    pNodo->prox->ant = pNodo->ant;
                    lista->n--;
                    free(pNodo);
                    flag = 1;
                    break;
                }
                if (pNodo->ant != NULL && pNodo->prox == NULL && lista->n > 1) {
                    pNodo->ant->prox = NULL;
                    lista->fim = pNodo->ant;
                    lista->n--;
                    free(pNodo);
                    flag = 1;
                    break;
                }
            }
            pNodo = pNodo->prox;
        }
        if (flag == 1)
            return SUCESSO;
        else
            return CODIGO_INEXISTENTE;
    }
}


