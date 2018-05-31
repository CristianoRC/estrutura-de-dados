#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

//Função criaLista
void criaLista(ListaSE *lista) {
    
    lista->inicio = NULL;
}

//Função incluiNoInicio
int incluiNoInicio(ListaSE *lista, Dado dado) {
    
    Nodo *pNodo;
    
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pNodo->info = dado;
        pNodo->prox = lista->inicio;
        lista->inicio = pNodo;
        return SUCESSO;
    }    
}

//Função exibe
void exibe(ListaSE lista) {
    
    Nodo *pAux;
    int pos = 1;
    
    pAux = lista.inicio;
    if (pAux == NULL)
        printf ("ERRO!\nA LISTA ESTÁ VAZIA!\n");
    else {
        pAux = lista.inicio;
        printf ("------ CONTEÚDO DA LISTA ------\n");
        while (pAux != NULL) {
            printf ("Endereço Atual: %p | Posição: %d | Código: %d | Peso: %.2f | Próximo Endereço: %p\n", pAux, pos, pAux->info.cod, pAux->info.peso, pAux->prox);
            pos++;
            pAux = pAux->prox;
        }
    }
}

//Função quantidadeDeNodos
int quantidadeDeNodos(ListaSE lista) {
    
    int c = 0;
    Nodo *pAux;
    
    if (lista.inicio == NULL)
        return c;
    else {
        pAux = lista.inicio;
        while (pAux != NULL) {
            c++;
            pAux = pAux->prox;
        }
        return c;
    }
}

//Função estaVazia
int estaVazia(ListaSE lista) {
    
    if (lista.inicio == NULL)
        return 1;
    else
        return 0;
}

//Função excluiDoInicio
int excluiDoInicio(ListaSE *lista, Dado *dado) {
    
    Nodo *pTemp = NULL;
    
    if (lista->inicio == NULL)
        return LISTA_VAZIA;
    else {
        *dado = lista->inicio->info;
        pTemp = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(pTemp);
        return SUCESSO;
    }
}

//Função incluiNoFim
int incluiNoFim(ListaSE *lista, Dado dado) {
    
    Nodo *pNodo, *pAux, *pTemp = NULL;
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    pNodo->prox = NULL;
    pAux = lista->inicio;
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        if (lista->inicio == NULL) {
            pNodo->info = dado;
            lista->inicio = pNodo;
        }else {
            while (pAux != NULL) {
                pTemp = pAux;
                pAux = pAux->prox;
            }
            pNodo->info = dado;
            pTemp->prox = pNodo;    
        }    
        return SUCESSO;
    }
}

//Função excluiDoFim
int excluiDoFim (ListaSE *lista, Dado *dado) {
    
    Nodo *pAux, *pTemp = NULL;
    
    pAux = lista->inicio;
    if (pAux == NULL)
        return LISTA_VAZIA;
    else {
        if (pAux->prox == NULL) {
            *dado = pAux->info;
            lista->inicio = NULL;
            free(pAux);
        }else {
            while (pAux->prox != NULL) {
                pTemp = pAux;
                pAux = pAux->prox;
            }
            *dado = pAux->info;
            pTemp->prox = NULL;
            free (pAux);
        }
        return SUCESSO;
    }
}

//Função existe
int existe(ListaSE lista, int cod) {
    
    Nodo *pAux;
    int flag = 0;
    
    pAux = lista.inicio;
    if (pAux == NULL)
        return LISTA_VAZIA;
    else {
        while (pAux != NULL) {
            if (pAux->info.cod == cod){
                flag = 1;
                break;
            }
            pAux = pAux->prox;
        }
        if (flag == 1)
            return 1;
        else
            return 0;
    }
}

//Função consultaPorCodigo
int consultaPorCodigo(ListaSE lista, int cod, Dado *dado) {
    
    Nodo *pAux;
    int flag = 0;
    
    pAux = lista.inicio;
    if (pAux == NULL)
        return LISTA_VAZIA;
    else {
        while (pAux != NULL) {
            if (pAux->info.cod == cod){
                flag = 1;
                *dado = pAux->info;
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

//Função incluiDepois
int incluiDepois(ListaSE *lista, int cod, Dado dado) {
    
    Nodo *pNodo, *pAux, *pTemp = NULL;
    int flag = 0;
    
    pNodo = (Nodo *) malloc (sizeof(Nodo));
    if (pNodo == NULL)
        return FALTOU_MEMORIA;
    else {
        pAux = lista->inicio;
        while (pAux != NULL) {
            if (pAux->info.cod == cod) {
                flag = 1;
                pTemp = pAux->prox;
                pNodo->info = dado;
                pAux->prox = pNodo;
                pNodo->prox = pTemp;
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
int excluiNodo(ListaSE *lista, int cod, Dado *dado) {
    
    Nodo *pAux, *pTemp = NULL;
    int c = 0, flag = 0;
    
    pAux = lista->inicio;
    if (pAux == NULL)
        return LISTA_VAZIA;
    else {
        while (pAux != NULL) {
            if (pAux->info.cod == cod) {
                if (pAux->prox == NULL && c == 0) {
                    *dado = pAux->info;
                    lista->inicio = NULL;
                    free(pAux);
                    flag = 1;
                    break;
                }
                if (pAux->prox == NULL) {
                    *dado = pAux->info;
                    pTemp->prox = NULL;
                    free(pAux);
                    flag = 1;
                    break;
                }
                if (c == 0) {
                    *dado = pAux->info;
                    lista->inicio = pAux->prox;
                    free(pAux);
                    flag = 1;
                    break;
                }else {
                    *dado = pAux->info;
                    pTemp->prox = pAux->prox;
                    free(pAux);
                    flag = 1;
                    break;
                }
                
            }
            c++;
            pTemp = pAux;
            pAux = pAux->prox;
        }
        if (flag == 1)
            return SUCESSO;
        else
            return CODIGO_INEXISTENTE;
    }
}