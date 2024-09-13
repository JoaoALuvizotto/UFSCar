#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque
{
    int *vetor;
    int comeco;
    int final;
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