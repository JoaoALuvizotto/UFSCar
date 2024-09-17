#include <stdlib.h>
#include <stdio.h>
#include "graphList.h"
#include "minHeap.h"

int OrdenaTopologica(Graph* g, MinHeap* h, int ordenacao[], int visitados[])
{
    int aux = 0, tam = 0;
    AdjListNode* p;
    while (h->size > 0)
    {
        aux = extractMin(h);
        ordenacao[tam++] = aux;
        p = g->adj[aux].head;
        while (p != NULL)
        {
            if (visitados[p->dest] == 1)
            {
                return 0;    
            }
            
            g->adj[p->dest].grauEntrada--;
            if ( g->adj[p->dest].grauEntrada == 0 && visitados[p->dest] == 0)
            {
                insertMinHeap(h, p->dest);
                visitados[p->dest] = 1;
            }
            p = p->next;
        }   
        //boas praticas 
        visitados[aux] = L_tmpnam;
        
        
    }
    
    if (tam != g->V) {
        return 0; 
    }
    
    return 1;

}

int main()
{
    int N = 0, M = 0, A, B;
    Graph* g;
    MinHeap* h;
    
    scanf("%d %d", &N, &M);
    int visitados[N];
    int ordenacao[N];
    
    for (int i = 0; i < N; i++)
    {
        visitados[i] = 0;
    }
    

    g = inicializar(N);
    h = createMinHeap(N);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);
        inserirAresta(g, A, B);
    }

    for (int i = 0; i < N; i++)
    {
        if (g->adj[i].grauEntrada == 0)
        {
            insertMinHeap(h, i);
            visitados[i] = 1;
        }
    }
    
    if (h->size == 0 && N != 0)
    {
        printf("*\n");
        return 0;
    }

    if (OrdenaTopologica(g, h, ordenacao, visitados))
    {
        for (int i = 0; i < N; i++)
        {
            printf("%d\n", ordenacao[i]);
        }
        
    }
    else
    {
        printf("*\n");
    }
    
    

    return 0;
}