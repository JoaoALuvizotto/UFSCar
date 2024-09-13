#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    char value;
    struct No* dir;
    struct No* esq;
}No;

No* buildingTree(char* pOrdem, int pMin, int pMax, char* iOrdem, int iMin, int iMax);
void PosOrdem(No* tree);
void freeTree(No *tree);

int main()
{
    int testes, qtdnos;
    char pOrdem[53], iOrdem[53];
    
    scanf("%d ", &testes);

    for (int i = 0; i < testes; i++)
    {
        scanf("%d ", &qtdnos);
        scanf("%s", pOrdem);
        scanf("%s", iOrdem);

        No* tree = buildingTree(pOrdem, 0, qtdnos-1, iOrdem, 0, qtdnos-1);

        PosOrdem(tree);
        printf("\n");
        freeTree(tree);
    }
    return 0;
}

No* buildingTree(char* pOrdem, int pMin, int pMax, char* iOrdem, int iMin, int iMax)
{
    int indice = -1;
    if (pMin > pMax || iMin > iMax)
        return NULL;
        
    for (int i = 0; iOrdem[i] != '\0'; i++)
        if (pOrdem[pMin] == iOrdem[i])
            indice = i;
        
    No* node = (No*)malloc(sizeof(No));

    node->value = pOrdem[pMin];
    node->esq = buildingTree(pOrdem, pMin + 1, pMin + (indice - iMin), iOrdem, iMin, indice - 1);
    node->dir = buildingTree(pOrdem, pMin + 1 + (indice - iMin) , pMax, iOrdem, indice + 1, iMax);
    return node;
}

void PosOrdem(No* tree)
{
    if (tree == NULL)
        return;

    PosOrdem(tree->esq);
    PosOrdem(tree->dir);

    printf("%c", tree->value);
    
}

void freeTree(No *tree) {
    if (tree == NULL) {
        return;
    }
    freeTree(tree->esq);
    freeTree(tree->dir);
    free(tree);
}