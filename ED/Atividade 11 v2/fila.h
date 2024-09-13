#ifndef FILA_H
#define FILA_H

typedef struct no
{
    int dado;
    struct no* link;
}No;

typedef struct fila
{
    No *primeiro, *ultimo;
    No* sentinela;
    int quantidade;
}Fila;

typedef struct iterador
{
    No* item;
    Fila* fila;
}Iterador;



Fila* inicializar();
int inserir(Fila*, int);
Iterador primeiro(Fila*);
Iterador proximo(Iterador);
int valido(Iterador);
int elemento(Iterador);
int remover(Fila*, int*);
int vazia(Fila*);
void destruir(Fila*);



#endif