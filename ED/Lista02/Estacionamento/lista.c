#include "lista.h"
#include <stdio.h>


Lista* inicializar()
{
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    Node* sentinela = (Node*)malloc(sizeof(Node));
    lista->sentinela = sentinela;
    lista->quantidade = 0;
    sentinela->proximo = sentinela;
    sentinela->anterior = sentinela;
    return lista;
}
int vazio(Lista* lista)
{
    return lista->sentinela->proximo == lista->sentinela;
}
int inserirI(Lista* lista, T data)
{
    Node* no = (Node*)malloc(sizeof(Node));
    if(!no)
        return 0;
    Node* temp;
    temp = lista->sentinela->proximo;
    lista->sentinela->proximo = no;
    no->anterior = lista->sentinela;
    no->proximo = temp;
    no->data = data;
    return 1;
}
int inserirF(Lista* lista, T data)
{
    Node* no = (Node*)malloc(sizeof(Node));
    Node* temp;
    if(!no)
        return 0;
    temp = lista->sentinela->anterior;
    lista->sentinela->anterior = no;
    temp->proximo = no;
    no->proximo = lista->sentinela;
    no->anterior = temp;
    return 1;
}
int removerI(Lista* lista, T* data)
{
    if (vazio(lista))
        return 0;
    Node* temp;
    *data = lista->sentinela->proximo->data;
    temp = lista->sentinela->proximo;
    lista->sentinela->proximo = temp->proximo;
    temp->proximo->anterior = lista->sentinela;
    free(temp);
    return 1;
}
int removerF(Lista* lista, T* data)
{
    if (vazio(lista))
        return 0;
    Node* temp;
    *data = lista->sentinela->anterior->data;
    temp = lista->sentinela->anterior;
    lista->sentinela->anterior = temp->anterior;
    temp->anterior->proximo = lista->sentinela;
    free(temp);
    return 1;
}

Iterador inserirDepois(Iterador i, T data)
{
    Node* no = (Node*)malloc(sizeof(Node));
    Node* temp;
    no->data = data;
    i.lista->quantidade++;
    temp = i.elemento->proximo;
    i.elemento->proximo = no;
    no->anterior = i.elemento;
    no->proximo = temp;
    temp->anterior = no;
    return i;
}
Iterador removerElemento(Iterador i)
{
    if (i.elemento != i.lista->sentinela)
    {
        Node* temp = i.elemento;
        i.elemento->anterior->proximo = i.elemento->proximo;
        i.elemento->proximo->anterior = i.elemento->anterior;
        i.elemento = i.elemento->anterior;
        i.lista->quantidade--;
        free(temp);
    }
    return i;
}
Iterador proximo(Iterador i)
{
    i.elemento = i.elemento->proximo;
    return i;
}
Iterador primeiro(Lista* l)
{
    Iterador i;
    i.elemento = l->sentinela->proximo;
    return i;
}
Iterador anterior(Iterador i)
{
    i.elemento = i.elemento->anterior;
    return i;
}
Iterador ultimo(Lista* l)
{
    Iterador i;
    i.elemento = l->sentinela->anterior;
    return i;
}
T conteudo(Iterador i)
{
    return i.elemento->data;
}
int valido(Iterador i)
{
    return i.elemento != i.lista->sentinela;
}
void LIMPARRRRRRRRRRR(Lista* l)
{
    T* data;
    while (!vazio(l))
    {
        removerI(l, &data);
    }
    
}
void CABOOOOM(Lista* l)
{
    LIMPARRRRRRRRRRR(l);
    free(l);
}