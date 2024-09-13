#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node *pai;
    int valor;
} Node;

int nivel(Node* a);
int lca(Node* a, Node* b);

int main(){

    int qtdTrees, ops;
    char operacao[10];

    scanf("%d %d", &qtdTrees, &ops);

    Node **trees = (Node**) malloc (sizeof(Node*) * qtdTrees );

    for (int i = 0; i < qtdTrees; i++)
    {
        trees[i] = (Node *) malloc(sizeof(Node));
        trees[i]->valor = i+1;
        trees[i]->pai = NULL;
    }
    
    for (int i = 0; i < ops; i++)
    {
        int a, b;
        scanf("%s", operacao);

        if (!strcmp(operacao, "lca"))
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", lca(trees[a-1], trees[b-1]));
        }
        else if (!strcmp(operacao, "link"))
        {
            scanf("%d %d", &a, &b);
            trees[a-1]->pai = trees[b-1];
        }
        else if(!strcmp(operacao, "cut"))
        {
            scanf("%d", &a);
            trees[a-1]->pai = NULL;
        }
    }
    
    for (int i = 0; i < qtdTrees; i++)
        free(trees[i]);

    free(trees);

    return 0;
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
        return a->valor;
    return a->pai->valor;

}
int nivel(Node* a)
{
    int contador = 0;
    for (; a->pai != NULL; contador++)
        a = a->pai;

    return contador;
}