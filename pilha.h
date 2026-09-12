#define TAM 5

typedef struct Pilha{
    char str[TAM][20];
    int upos;
}pilha;

pilha cria_pilha();
pilha push_pilha(pilha P, char str[]);
pilha pop_pilha(pilha P);
void imprime_pilha(pilha P);
