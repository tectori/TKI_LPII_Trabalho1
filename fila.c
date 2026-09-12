#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

fila cria_fila(){
    fila F;
    F.upos = 0;
    return F;
}

bool fila_cheia(fila F){
    return F.upos >= TAM;
}

fila enfilera_fila(fila F, char str[]){
    bool cheio = fila_cheia(F);
    if(!cheio){
        strcpy(F.str[F.upos], str);
        F.upos++;
    }
    else if(cheio) printf("Fila cheia\n");
    return F;
}

bool fila_vazia(fila F){
    return F.upos == 0;
}

fila desenfilera_fila(fila F){
    int i;
    if(!fila_vazia(F)){
        for(i=0; i<(F.upos-1); i++){
            strcpy(F.str[i], F.str[i+1]);
        }
        F.upos--;
    }
    else if(fila_vazia(F)) printf("Fila vazia\n");
    return F;
}

void imprime_fila(fila F){
    int i;
    for(i=0; i<F.upos; i++){
        printf("%s ", F.str[i]);
    }
    if(fila_vazia(F)) printf("Fila vazia");
    printf("\n");
}
