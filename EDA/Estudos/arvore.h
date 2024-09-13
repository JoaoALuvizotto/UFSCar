#include <stdlib.h>

typedef struct Node
{
    struct Node *esq, *dir;
    int data;
} Node;

Node *inserirABB(Node *raiz, int data){

    if (!raiz)
    {
        Node *NovoNode = (Node*) malloc (sizeof(Node));
        NovoNode->data = data;
        NovoNode->esq = NULL;
        NovoNode->dir = NULL;
        return NovoNode;
    }
    
    if (data > raiz->data)
    {
        raiz->dir = inserirABB(raiz->dir, data);
        //inseriu na direita
    }
    else
    {
        raiz->esq = inserirABB(raiz->esq, data);
    }

    return raiz;
}