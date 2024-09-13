//Joao Augusto Luvizotto RA:823078
#include <stdlib.h>
#include "fila.h"
//Inicializa a fila, onde como não possui nenhum item ainda os ponteiros precisam ser inicializados como NULLs
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
//Insere um item na fila
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
//Remove um item da fila
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
//Verifica se a fila esta vazia ou nao
int vazia(Fila* fila)
{
    if (fila->quantidade == 0)
        return 1;
    return 0;
    
}
//desacola a memoria alocada para a fila
void destruir(Fila* fila)
{
    int a;
    while (!vazia(fila))
        remover(fila, &a);
    
    free(fila);    
}