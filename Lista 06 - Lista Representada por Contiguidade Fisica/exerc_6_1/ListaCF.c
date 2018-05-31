#include <stdio.h>
#include "ListaCF.h"

//Função criaLista
void criaLista (ListaCF *lista) {
    
    lista->n = 0;
}
//Função incluiNoFim
int incluiNoFim (Dado dado, ListaCF *lista) {

    if (lista->n == MAX_NODOS)
        return LISTA_CHEIA;
    else {
        lista->v[lista->n] = dado;
        lista->n++;
        return SUCESSO;
    }
}
//Função exibe
void exibe (ListaCF lista) {
    
    int i;
    
    if (lista.n == 0)
        printf ("ERRO!\nA LISTA ESTÁ VAZIA!\n");
    else
        for (i = 0; i < lista.n; i++)
            printf ("Nodo %d: Código: %d | Peso: %.2f\n", i+1, lista.v[i].cod, lista.v[i].peso);
}
//Função quantidaDeDeNodos
int quantidadeDeNodos (ListaCF lista) {
    
    int i, cn = 0;
    
    for (i = 0; i < lista.n; i++) {
        if (lista.v[i].cod != 0 && lista.v[i].peso != 0)
            cn++;
    }
    return cn;
}
//Função estaCheia
int estaCheia (ListaCF lista) {
    
    if (lista.n == MAX_NODOS)
        return 1;
    else
        return 0;
}
//Função estaVazia
int estaVazia (ListaCF lista) {
    
    if (lista.n == 0)
        return 1;
    else
        return 0;
}
//Função excluiDoFim
int excluiDoFim (ListaCF *lista, Dado *dado) {
    
    if (lista->n == 0)
        return LISTA_VAZIA;
    else {
        *dado = lista->v[lista->n - 1];
        lista->n--;
        return SUCESSO;
    }
}
//Função incluiNoInicio
int incluiNoInicio (Dado dado, ListaCF *lista) {
    
    int i, c = lista->n - 1;
    
    if (lista->n == MAX_NODOS)
        return LISTA_CHEIA;
    else {
        if (lista->n == 0) {
            lista->v[0] = dado;
            lista->n++;
            return SUCESSO;
        }else {
            for (i = lista->n; i > 0; i--) {
                lista->v[i] = lista->v[c];
                c--;
            }
            lista->v[0] = dado;
            lista->n++;
            return SUCESSO;
        } 
    }
}
//Função excluiDoInicio
int excluiDoInicio (ListaCF *lista, Dado *dado) {
    
    int i;
    
    if (lista->n == 0)
        return LISTA_VAZIA;
    else {
        *dado = lista->v[0];
        for (i = 1; i < lista->n; i++)
            lista->v[i - 1] = lista->v[i];
        lista->n--;
        return SUCESSO;
    }
}
//Função consultaPorPosicao
int consultaPorPosicao (ListaCF lista, int posicao, Dado *dado) {
    
    int i;
    
    if (posicao > lista.n)
        return POSICAO_INVALIDA;
    else {
        for (i = 0; i < lista.n; i++) {
            if (i == posicao - 1) {
                *dado = lista.v[i];
                return SUCESSO;
                break;
            }    
        }
    }    
}
//Função existe
int existe (ListaCF lista, int codigo) {
    
    int i, f = 0;
    
    for (i = 0; i < lista.n; i++) {
        if (codigo == lista.v[i].cod)
            f = 1;
        break;       
    }
    if (f == 1)
        return 1;
    else
        return 0;
}
//Função consultaPorCodigo
int consultaPorCodigo (ListaCF lista, int codigo, Dado *dado) {
    
    int i;
    
    for (i = 0; i < lista.n; i++) {
        if (codigo == lista.v[i].cod) {
            *dado = lista.v[i];
            return SUCESSO;
            break;
        }    
    }
    return CODIGO_INEXISTENTE;
}
//Função incluiNaPosicao
int incluiNaPosicao (int posicao, Dado dado, ListaCF *lista) {
    
    int i, c = lista->n - 1;
    
    if (lista->n == MAX_NODOS)
        return LISTA_CHEIA;
    else
        if (posicao > MAX_NODOS)
            return POSICAO_INVALIDA;
        else
            if (lista->v[posicao - 1].cod == 0 && lista->v[posicao - 1].peso == 0) {
                lista->v[posicao - 1] = dado;
                lista->n++;
                return SUCESSO;
            }else {
                for (i = lista->n; i > posicao - 1; i--) {
                    lista->v[i] = lista->v[c];
                    c--;
                }    
                lista->v[posicao - 1] = dado;
                lista->n++;
                return SUCESSO;
            }    
}
//Função excluiDaPosicao
int excluiDaPosicao (int posicao, ListaCF *lista, Dado *dado) {
    
    int i;
    
    if (posicao > lista->n)
        return POSICAO_INVALIDA;
    else {
        *dado = lista->v[posicao - 1];
        for (i = posicao - 1; i < lista->n; i++)
            lista->v[i] = lista->v[i + 1];
        lista->n--;
        return SUCESSO;  
    }     
}
//Função incluiAntes
int incluiAntes (int codigo, Dado dado, ListaCF *lista) {
    
    int i, j, f = 0, c = lista->n - 1;
    
    if (lista->n == MAX_NODOS)
        return LISTA_CHEIA;
    else {
        for (i = 0; i < lista->n; i++) {
            if (lista->v[i].cod == codigo) {
                f = 1;
                break;
            }
        }if (f == 1) {
            for (j = lista->n; j > i; j--) {
                lista->v[j] = lista->v[c];
                c--;
            }
            lista->v[i] = dado;
            lista->n++;
            return SUCESSO;
        }else
            return CODIGO_INEXISTENTE;
    }
}
//Função excluiNodo
int excluiNodo (int codigo, Dado *dado, ListaCF *lista) {
    
    int i, j, f = 0, c;
    
    for (i = 0; i < lista->n; i++) {
        if (lista->v[i].cod == codigo) {
            f = 1;
            c = i;
            break;
        }
    }if (f == 1) {
        *dado = lista->v[i];
        if (lista->n - 1 == i) {
            lista->n--;
            return SUCESSO;
        }else {
            for (j = i; j < lista->n; j++) {
                c++;
                lista->v[j] = lista->v[c];
            }
            lista->n--;
            return SUCESSO;
        }
    }else
        return CODIGO_INEXISTENTE;
}
