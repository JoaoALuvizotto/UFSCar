#ifndef PILHA_H
#define PILHA_H

typedef struct pilha
{
    int max;
    char* vetor;
    int topo;
} Pilha;

Pilha* inicializar(int);
int vazia(Pilha*);
int inserir(Pilha*, char);
int remover(Pilha*, char);
int verificar(Pilha*, char[]);
void destruir(Pilha*);

#endif