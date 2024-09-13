#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node{
    struct Node* esq;
    struct Node* dir;
    int value;
} node;

typedef struct abb
{
    node* raiz;
} ABB;

void inserir (ABB* tree, int valor);
node* inserir_privado(node* p, int valor);
void pre_ordem(node* no);
void in_ordem(node* no);
void pos_ordem(node* no);
void in_nivel(node* t);


int main()
{
    int qtd_num, num;

    ABB* tree = (ABB*)malloc(sizeof(ABB));
    tree->raiz = NULL;

    scanf("%d", &qtd_num);
    
    for (int i = 0; i < qtd_num; i++)
    {
        scanf("%d", &num);
        inserir(tree, num);
    }
    
    printf("Pr.:");
    pre_ordem(tree->raiz);
    printf("\n");

    printf("In.:");
    in_ordem(tree->raiz);
    printf("\n");  

    printf("Po.:");
    pos_ordem(tree->raiz);
    printf("\n");

    printf("Ni.:");
    in_nivel(tree->raiz);
    printf("\n");
    
    return 0;
}

void inserir (ABB* tree, int valor)
{
    tree->raiz = inserir_privado(tree->raiz, valor);
}

node* inserir_privado(node* no, int valor)
{
    if(!no)
    {
        node* novo = (node*)malloc(sizeof(node));
        novo->value = valor;
        novo->esq = novo->dir = 0;
        return novo;
    }
    else if (no->value > valor)
        no->esq = inserir_privado(no->esq, valor);
    else if (no->value < valor)
        no->dir = inserir_privado(no->dir, valor);
    else
        no->value = valor;

    return no;
}

void pos_ordem(node* no)
{
    if (no)
    {
       pos_ordem(no->esq);

       pos_ordem(no->dir);

       printf(" %d", no->value);
    }
    
    return;

}

void pre_ordem(node* no)
{
    if (no)
    {
        printf(" %d", no->value);

        pre_ordem(no->esq);
        
        pre_ordem(no->dir);
    }

    return; 
    
}
void in_ordem(node* no)
{
     if (no)
    {
        in_ordem(no->esq);
        
        printf(" %d", no->value);

        in_ordem(no->dir);
    }

    return; 
    
}

void in_nivel(node* t)
{
    if(!t)
        return;

    queue* Fila = (queue*) malloc(sizeof(queue));
    initialize(Fila);

    push(Fila, t);

    while (!empty(Fila))
    {
        node* noRemovido = (node*) front(Fila);
        printf(" %d", noRemovido->value);
        pop(Fila);

        if (noRemovido->esq)
            push(Fila, noRemovido->esq);

        if (noRemovido->dir)
            push(Fila, noRemovido->dir);
    }
     
    destroy(Fila);

}
