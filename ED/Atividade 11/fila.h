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
    int quantidade;
}Fila;

Fila* inicializar();
int inserir(Fila*, int);
int remover(Fila*, int*);
int vazia(Fila*);
void destruir(Fila*);



#endif