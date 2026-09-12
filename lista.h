#define TAM 5

typedef struct No{
    int chave;
    char nome[30];
    char endereco[50];
}tno;

typedef struct Lista{
    tno no[TAM];
    int upos;
}lista;

lista cria_lista();
lista insere_lista(lista L, int chave, char nome[], char endereco[], int posicao);
lista remove_lista(lista L, int posicao);
int busca_lista(lista L, int valor_chave);
lista ordena_lista(lista L);
void imprime_lista(lista L);
void imprime_busca_lista(int chave_busca, int posicao);
