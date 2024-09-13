#ifndef DEQUE_H
#define DEQUE_H

typedef struct node
{
    int dado;
    struct node* proximo;
    struct node* anterior;
} Node;


typedef struct deque
{
    Node* sentinela;
    int quantidade;
    int max;
} Deque;

Deque* inicializar(int);
int vazio(Deque*);
int cheio(Deque*);
int InsereI(Deque*, int);
int InsereF(Deque*, int);
int RemoveI(Deque*, int*);
int RemoveF(Deque*, int*);
void CABOOOM(Deque*);


#endif