#ifndef PILHA_H
#define PILHA_H

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque
{
    Node *inicio;
    Node *fim;
    int tamanho;
    int max;
} Deque;

int insereI(Deque *deque , int data);

int insereF(Deque *deque, int data);

int removeF(Deque *deque, int *data);

int removeI(Deque *deque, int *data);

int cheio(Deque *deque);

int vazio(Deque *deque);

Deque* inicializarDeque(int max);

void destruirDeque(Deque *deque);

#endif