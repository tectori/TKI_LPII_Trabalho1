#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"

lista cria_lista(){
    lista L;
    L.upos = 0;
    return L;
}

bool lista_cheia(lista L){
    return L.upos >= TAM;
}

lista insere_lista(lista L, int chave, char nome[], char endereco[], int posicao){
    bool cheio = lista_cheia(L);
    int i;
    if (!cheio && posicao == -1){
        L.no[L.upos].chave = chave;
        strcpy(L.no[L.upos].nome, nome);
        strcpy(L.no[L.upos].endereco, endereco);
        L.upos++;
    }
    else if (!cheio && posicao >= -1 && posicao <= L.upos){
        for(i=L.upos; i>posicao; i--){
            L.no[i] = L.no[i-1];
        }
        L.no[posicao].chave = chave;
        strcpy(L.no[posicao].nome, nome);
        strcpy(L.no[posicao].endereco, endereco);
        L.upos++;
    }
    else if (cheio) printf("Lista cheia\n");
    return L;
}

bool lista_vazia(lista L){
    return L.upos == 0;
}

lista remove_lista(lista L, int posicao){
    int i;
    bool vazio = lista_vazia(L);
    if(!vazio && posicao > -1 && posicao < L.upos){
        for(i=posicao; i<(L.upos-1); i++){
            L.no[i] = L.no[i+1];
        }
        L.upos--;
    }
    if(vazio) printf("Lista vazia\n");
    return L;
}

int busca_lista(lista L, int valor_chave){
    int i;
    for(i=0; i<L.upos; i++){
        if (L.no[i].chave == valor_chave){
            return i;
        }
    }
    return -1;
}

lista ordena_lista(lista L){
    int i, j;
    tno temp;
    for(i=0; i<(L.upos-1); i++){
        for(j=(i+1); j<L.upos; j++){
            if(L.no[i].chave > L.no[j].chave){
                temp = L.no[i];
                L.no[i] = L.no[j];
                L.no[j] = temp;
            }
        }
    }
    return L;
}

void imprime_lista(lista L){
    int i;
    for(i=0; i<L.upos; i++){
        printf("%d - %s, %s   ", L.no[i].chave, L.no[i].nome, L.no[i].endereco);
    }
    if(lista_vazia(L)) printf("Lista vazia");
    printf("\n");
}

void imprime_busca_lista(int chave_busca, int posicao){
    if(posicao == -1) printf("A chave %d não existe\n", chave_busca);
    else printf("A chave %d está na posição %d\n", chave_busca, posicao);
}
