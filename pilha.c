#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

pilha cria_pilha(){
    pilha P;
    P.upos = 0;
    return P;
}

bool pilha_cheia(pilha P){
    return P.upos >= TAM;
}

pilha push_pilha(pilha P, char str[]){
    bool cheio = pilha_cheia(P);
    if(!cheio){
        strcpy(P.str[P.upos], str);
        P.upos++;
    }
    else if(cheio) printf("Pilha cheia\n");
    return P;
}

bool pilha_vazia(pilha P){
    return P.upos == 0;
}

pilha pop_pilha(pilha P){
    if (!pilha_vazia(P)) P.upos--;
    else if (pilha_vazia(P)) printf("Pilha vazia\n");
    return P;
}

void imprime_pilha(pilha P){
    int i;
    for(i=0; i<P.upos; i++){
        printf("%s ", P.str[i]);
    }
    if(pilha_vazia(P)) printf("Pilha vazia");
    printf("\n");
}
