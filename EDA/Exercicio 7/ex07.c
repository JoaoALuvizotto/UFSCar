#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    char letra;
    int frequencia;
    struct Node* esq;
    struct Node* dir;
    struct Node* proximo;
} node;

typedef struct Lista
{
    node* inicio;
    int tamanho;
} lista;

void inicializarLista(lista* lista)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirLista(lista* lista, node* no)
{
    if (lista->inicio == NULL)
    {
        lista->inicio = no;
    }
    else if (lista->inicio->frequencia > no->frequencia)
    {
        no->proximo = lista->inicio;
        lista->inicio = no;
    }
    else
    {
        node* auxiliar = lista->inicio;
        while (auxiliar->proximo && auxiliar->proximo->frequencia <= no->frequencia)
        {
            auxiliar = auxiliar->proximo;
        }
        no->proximo = auxiliar->proximo;
        auxiliar->proximo = no;
    }
    lista->tamanho++;
}

node* removeNo(lista* lista)
{
    node* no = NULL;
    if (lista->inicio)
    {
        no = lista->inicio;
        lista->inicio = no->proximo;
        no->proximo = NULL;
        lista->tamanho--;
    }
    return no;
}

node* makeTree(lista* lista)
{
    while (lista->tamanho > 1)
    {
        node* primeiro = removeNo(lista);
        node* segundo = removeNo(lista);
        node* novo = (node*)malloc(sizeof(node));
        novo->letra = '+';
        novo->frequencia = primeiro->frequencia + segundo->frequencia;
        novo->esq = primeiro;
        novo->dir = segundo;
        novo->proximo = NULL;
        inserirLista(lista, novo);
    }
    return lista->inicio;
}

int calcBits(node* arvore, int altura)
{
    if (arvore->dir == NULL && arvore->esq == NULL)
        return arvore->frequencia * altura;
    
    return calcBits(arvore->dir, altura + 1) + calcBits(arvore->esq, altura + 1);
}

int main()
{
    int vet_freq[28] = {0};
    char letra;
    node* arvore;
    lista lista;

    inicializarLista(&lista);

    for (int i = 0; scanf("%c", &letra) != EOF; i++)
    {
        letra = tolower(letra);
        if (isalpha(letra))
        {
            vet_freq[letra - 'a']++;
        }
        else if (letra == ' ')
            vet_freq[26]++;
        else if (letra == '\n')
            vet_freq[27]++;

    }

    for (int i = 0; i < 28; i++)
    {
        if (vet_freq[i] > 0)
        {
            node* no = (node*)malloc(sizeof(node));
            if (i < 26)
                no->letra = i + 'a';
            else if (i == 26)
                no->letra = ' ';
            else if (i == 27)
                no->letra = '\n';
            
            no->frequencia = vet_freq[i];
            no->dir = NULL;
            no->esq = NULL;
            no->proximo = NULL;
            inserirLista(&lista, no);
        }
    }

    arvore = makeTree(&lista);

    printf("%d\n", calcBits(arvore, 0));


    return 0;
}
