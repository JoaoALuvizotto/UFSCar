//Joao Augusto Luvizotto RA:823078
#include <stdlib.h>
#include "deque.h"
/*este deque foi implementado com a utilizacao de um vetor circular, pois o utilizando confere ao codigo eficiencia
e evita desperdicio de memoria*/
//inicializa o deque
Deque* inicializar(int maximo)
{
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->sentinela = (Node*)malloc(sizeof(Node));
    deque->sentinela->anterior = deque->sentinela;
    deque->sentinela->proximo = deque->sentinela;
    deque->quantidade = 0;
    deque->max = maximo;
    return deque;
}
//verifica se o deque esta vazio
int vazio(Deque* deque)
{
    if (deque->quantidade  == 0)
        return 1;
    return 0;
    
}
//verifica se o deque esta cheio
int cheio(Deque* deque)
{
    if(deque->quantidade == deque->max)
        return 1;
    return 0;
}
//insere no inicio do deque
int InsereI(Deque* deque, int dado)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (cheio(deque) || !node)
        return 0;
    else
    {
        node->dado = dado;
        node->proximo = deque->sentinela->proximo;
        node->anterior = deque->sentinela;
        deque->sentinela->proximo = node;
        node->proximo->anterior = node;
        deque->quantidade++;
    }
    return 1;
   
}
//insere no final do deque
int InsereF(Deque* deque, int dado)
{
    Node* node = (Node*)malloc(sizeof(Node));
     if (cheio(deque) || !node)
        return 0;
    else
    {
        node->dado = dado;
        node->proximo = deque->sentinela;
        deque->sentinela->anterior->proximo = node;
        node->anterior = deque->sentinela->anterior;
        deque->sentinela->anterior = node;
        deque->quantidade++;
    }
    return 1;

}
//remove do inicio do deque
int RemoveI(Deque* deque, int* dado)
{
    Node* p;
    if (!vazio(deque))
    {
       p = deque->sentinela->proximo;
       deque->sentinela->proximo = p->proximo;
       p->proximo->anterior = deque->sentinela;
       deque->quantidade--;
       *dado = p->dado;
       free(p);
       return 1;
    }
    return 0;
    
}
//remove do final do deque
int RemoveF(Deque* deque, int* dado)
{
    Node* p;
    if (!vazio(deque))
    {
       p = deque->sentinela->anterior;
       deque->sentinela->anterior = p->anterior;
       p->anterior->proximo = deque->sentinela;
       deque->quantidade--;
       *dado = p->dado;
       free(p);
       return 1;
    }
    return 0;
}
//funcao que desaloca o deque
void CABOOOM(Deque* deque)
{
    int dado;
    while (deque->sentinela->proximo != deque->sentinela)
        RemoveI(deque, &dado);
    
}