#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node *esq;
    struct Node *dir;
    struct Node *pai;
    int valor;
} Node;

int nivel(Node* a);
void link(Node* a, Node* b);
int lca(Node* a, Node* b);
void cut(Node* a);

int main(){

    int num_arvores, num_operacoes;
    char operacao[10];

    scanf("%d %d", &num_arvores, &num_operacoes);

    Node **arvores = (Node**) malloc (sizeof(Node*) * num_arvores );

    for (int i = 0; i < num_arvores; i++)
    {
        arvores[i] = (Node *) malloc(sizeof(Node));
        arvores[i]->valor = i+1;
        arvores[i]->esq = NULL;
        arvores[i]->dir = NULL;
        arvores[i]->pai = NULL;
    }
    
    for (int i = 0; i < num_operacoes; i++)
    {
        int a, b;
        scanf("%s", operacao);

        if (strcmp(operacao, "lca") == 0)
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", lca(arvores[a-1], arvores[b-1]));
        }
        else if (strcmp(operacao, "link") == 0)
        {
            scanf("%d %d", &a, &b);
            link(arvores[a-1], arvores[b-1]);
        }
        else if(strcmp(operacao, "cut") == 0)
        {
            scanf("%d", &a);
            cut(arvores[a-1]);
        }
    }
    
    for (int i = 0; i < num_arvores; i++)
        free(arvores[i]);

    free(arvores);

    return 0;
}

void link(Node* a, Node* b)
{
    if (!b->esq)
    {
        b->esq = a;
        a->pai = b;
    }
    else if (!b->dir)
    {
        b->dir = a;
        a->pai = b;
    }

}
int lca(Node* a, Node* b)
{
    int nivelA = nivel(a);
    int nivelB = nivel(b);

    while (nivelA > nivelB)
    {
        a = a->pai;
        nivelA--;
    }

    while (nivelB > nivelA)
    {
        b = b->pai;
        nivelB--;
    }

    while (a->pai != b->pai)
    {
        a = a->pai;
        b = b->pai;
    }

    if (a == b)
    {
        return a->valor;
    }
    return a->pai->valor;

}
void cut(Node* a)
{
    if (a->pai)
    {
        if (a->pai->esq == a)
            a->pai->esq = NULL;
        else
            a->pai->dir = NULL;
        
        a->pai = NULL;
        //free(a);
    }
}
int nivel(Node* a)
{
    int contador = 0;
    for (; a->pai != NULL; contador++)
        a = a->pai;

    return contador;
}