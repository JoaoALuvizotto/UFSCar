#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct no {
    int v;
    struct no *esq, *dir;
} No;

void largura(No* t);
int conta_nos(No* t);
int conta_folhas(No* t);
int busca(No* t, int v);
No* espelho_private(No* t);

int main()
{
    No* NOOOSSA = (No*)malloc(sizeof(No));
    NOOOSSA->v = 1;

    No* NOOOSSA2 = (No*)malloc(sizeof(No));
    NOOOSSA2->v = 2;

    No* NOOOSSA3 = (No*)malloc(sizeof(No));
    NOOOSSA3->v = 3;

    No* NOOOSSA4 = (No*)malloc(sizeof(No));
    NOOOSSA4->v = 4;

    No* NOOOSSA5 = (No*)malloc(sizeof(No));
    NOOOSSA5->v = 5;


    NOOOSSA->esq = NOOOSSA2;
    NOOOSSA->dir = NOOOSSA3;
    NOOOSSA2->esq = NOOOSSA4;
    NOOOSSA2->dir = NOOOSSA5;

    NOOOSSA3->dir = NULL;
    NOOOSSA3->esq = NULL;

    NOOOSSA4->dir = NULL;
    NOOOSSA4->esq = NULL;

    NOOOSSA5->dir = NULL;
    NOOOSSA5->esq = NULL;

    largura(NOOOSSA);

    printf("\n%d", conta_nos(NOOOSSA));

    printf("\n%d", conta_folhas(NOOOSSA));

    printf("\n%d", busca( NOOOSSA, 1));
    printf("\n%d", busca( NOOOSSA, 2));
    printf("\n%d", busca( NOOOSSA, 3));
    printf("\n%d", busca( NOOOSSA, 4));
    printf("\n%d", busca( NOOOSSA, 5));
    printf("\n%d\n", busca( NOOOSSA, 6));

    No* ASSOOON = espelho_private(NOOOSSA);

    largura(ASSOOON);

    return 0;
}

void largura(No* t)
{
    if(!t)
        return;

    queue* Fila = (queue*) malloc(sizeof(queue));
    initialize(Fila);

    push(Fila, t);

    while (!empty(Fila))
    {
        No* noRemovido = (No*) front(Fila);
        printf("%d ", noRemovido->v);
        pop(Fila);

        if (noRemovido->esq)
            push(Fila, noRemovido->esq);

        if (noRemovido->dir)
            push(Fila, noRemovido->dir);
    }
     
    destroy(Fila);

}

int conta_nos(No* t)
{
    if (!t)
        return 0;

    return conta_nos(t->esq) + 1 + conta_nos(t->dir);
    
}

int conta_folhas(No* t)
{
    if (!t->esq && !t->dir)
        return 1;

    return conta_folhas(t->esq) + conta_folhas(t->dir);
    
}

int busca(No* t, int v)
{
    if (!t)
        return 0;
    
    if (t->v == v)
        return 1;    

    if (busca(t->esq, v) || busca(t->dir, v))
        return 1;

    return 0;
    
}

No* espelho_private(No* t){
    
    if (!t)
    {
        return NULL;
    }
    
    No *novoNo = (No*) malloc (sizeof(No));
    novoNo->v = t->v;

    novoNo->esq = espelho_private(t->dir);
    novoNo->dir = espelho_private(t->esq);

    return novoNo;
}
