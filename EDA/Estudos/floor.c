#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int public_floor(Node* tree, int *valor);
Node* private_floor(Node *p, int dado);

int main()
{
    int valor = 21;
    Node* raiz = NULL;
    raiz = inserirABB(raiz, 5);
    raiz = inserirABB(raiz, 3);
    raiz = inserirABB(raiz, 2);
    raiz = inserirABB(raiz, 1);
    raiz = inserirABB(raiz, 4);
    raiz = inserirABB(raiz, 8);
    raiz = inserirABB(raiz, 9);
    raiz = inserirABB(raiz, 10);
    raiz = inserirABB(raiz, 6);
    raiz = inserirABB(raiz, 7);
    raiz = inserirABB(raiz, 22);

    printf("%d\n", public_floor(raiz, &valor));
    printf("%d", valor);

    return 0;
}

int public_floor(Node* tree, int *valor)
{
    Node* p = private_floor(tree, *valor);
    if (!p)
        return 0;
    else
        *valor = p->data;
    
    return 1;
    
} 

Node* private_floor(Node *p, int dado)
{
    Node* temp;
    
    if (!p)
        return NULL;
    
    if (dado > p->data)
    {
        temp = private_floor(p->dir, dado);
        if (temp)
        {
            return temp;
        } 
        else 
        {
            return p;
        }
        
    }
    else if (dado < p->data)
    {
        temp = private_floor(p->esq, dado);

        if (temp)
        {
            return temp;
        }
        else
        {
            return NULL;
        }
        
    }
    else
    {
        return p;
    }
    
}


