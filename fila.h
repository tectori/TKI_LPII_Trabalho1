#define TAM 5

typedef struct Fila{
    char str[TAM][20];
    int upos;
}fila;

fila cria_fila();
fila enfilera_fila(fila F, char str[]);
fila desenfilera_fila(fila F);
void imprime_fila(fila F);
