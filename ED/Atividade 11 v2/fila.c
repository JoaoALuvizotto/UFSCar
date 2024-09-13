#include <stdlib.h>
#include "fila.h"

Fila* inicializar()
{
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (!fila)
        return 0;
    
    fila->quantidade = 0;
    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

Iterador primeiro(Fila* fila)
{
    Iterador It;
    It.item = fila->primeiro;
    It.fila = fila;

    return  It;
}
Iterador proximo(Iterador It)
{
    It.item = It.item->link;
    return It;
}
int valido(Iterador It)
{
    if (It.item != It.fila->sentinela)
        return 1;
    return 0;
}
int elemento(Iterador It)
{
    return It.item->dado;
}
int inserir(Fila* fila, int dado)
{
    No* no = (No*)malloc(sizeof(No));
    if(!no) 
        return 0;
    if (vazia(fila))
    {
        fila->primeiro = no;
        fila->ultimo = no;
    }
    else
    {
        fila->ultimo->link = no;
        fila->ultimo = no;
    }
    no->dado = dado;
    no->link  = NULL;
    fila->quantidade++;

    return 1;
}
int remover(Fila* fila, int* item)
{
    if (vazia(fila))
        return 0;
    *item = fila->primeiro->dado;
    if (fila->quantidade == 1)
    {
        free(fila->primeiro);
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else
    {
        No* temp = fila->primeiro;
        fila->primeiro = fila->primeiro->link;
        free(temp);
    }
    fila->quantidade--;
    return 1;
    
}
int vazia(Fila* fila)
{
    if (fila->quantidade == 0)
        return 1;
    return 0;
    
}
void destruir(Fila* fila)
{
    int a;
    while (!vazia(fila))
        remover(fila, &a);
    
    free(fila);    
}