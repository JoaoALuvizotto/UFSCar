#include <stdlib.h>
#include "deque.h"

Deque* inicializarDeque(int max){

    Deque *deque = (Deque*) malloc(sizeof(Deque));
    deque->max = max;
    deque->fim = NULL;
    deque->inicio = NULL;
    deque->tamanho = 0;

    return deque;
}

int cheio(Deque *deque){
    return deque->tamanho == deque->max;
}

int vazio(Deque *deque){
    return deque->tamanho == 0;
}

int insereI(Deque *deque , int data){

    if (cheio(deque))
        return 0;
    else
    {
        Node *novo_node = (Node*) malloc (sizeof(Node));
        novo_node->data = data;
        novo_node->prev = NULL;

        if (vazio(deque))
        {
            deque->inicio = novo_node;
            deque->fim = novo_node;
            novo_node->next = NULL;
        }
        else
        {
            novo_node->next = deque->inicio;
            deque->inicio->prev = novo_node;
            deque->inicio = novo_node;
        }

        deque->tamanho++;
        return 1;
    }
    
}

int insereF(Deque *deque, int data){

    if (cheio(deque))
    {
        return 0;
    }
    else
    {
        Node *novo_node = (Node*) malloc (sizeof(Node));
        novo_node->data = data;
        novo_node->next = NULL;

        if (vazio(deque))
        {
            deque->inicio = novo_node;
            deque->fim = novo_node;
            novo_node->prev = NULL;
        }
        else
        {
            deque->fim->next = novo_node;
            novo_node->prev = deque->fim;
            deque->fim = novo_node;
        }

        deque->tamanho++;
        return 1;
    }
    
}

int removeF(Deque *deque, int *data){

    if (vazio(deque))
    {
        return 0;
    }
    else
    {
        *data = deque->fim->data;

        if (deque->tamanho == 1)
        {
            free(deque->fim);
            deque->inicio = NULL;
            deque->fim = NULL;
        }
        else
        {
            Node *temp = deque->fim;
            deque->fim = deque->fim->prev;
            deque->fim->next = NULL;
            free(temp);
        }
        
        deque->tamanho--;
        return 1;
    }
    
}

int removeI(Deque *deque, int *data){

    if (vazio(deque))
    {
        return 0;
    }
    else
    {
        *data = deque->inicio->data;

        if (deque->tamanho == 1)
        {
            free(deque->inicio);
            deque->inicio = NULL;
            deque->fim = NULL;
        }
        else
        {
            Node *temp = deque->inicio;
            deque->inicio = deque->inicio->next;
            deque->inicio->prev = NULL;
            free(temp);
        }
        
        deque->tamanho--;
        return 1;
    }
    
}

void destruirDeque(Deque *deque){

    while (!vazio(deque))
    {
        int removido;
        removeF(deque, &removido);
    }
    
    free(deque);
}