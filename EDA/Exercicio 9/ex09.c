#include <stdio.h>
#include <stdlib.h>
#include "graphList.h"

typedef struct infoNode
{
    int numNode;
    int timeInicial;
    int timeFinal;

}infoNode;

void DFS(Graph* G, int visitados[], int V, int* timestamp, infoNode infoNodes[], int* indice, int* ciclico)
{
    int posicaoInserida = *indice;
    AdjListNode* aux = G->adj[V].head; 
    visitados[V] = 1;
    infoNodes[*indice].numNode = V;
    (*timestamp)++;
    infoNodes[*indice].timeInicial = *timestamp;
    (*indice)++;
    while (aux)
    {
        if (visitados[aux->dest] == 0)
            DFS(G, visitados, aux->dest, timestamp, infoNodes, indice, ciclico);

        if (visitados[aux->dest] == 1)
            *ciclico = 1;

        aux = aux->next;
    }
    visitados[V] = 2;
    (*timestamp)++;
    infoNodes[posicaoInserida].timeFinal = *timestamp;

}

int main()
{
    Graph* G; 
    int timestamp = 0, indice = 0, ciclico = 0;
    int numVertice = 0, inicio, destino;

    scanf("%d", &numVertice);
    int visitados[numVertice];
    for (int i = 0; i < numVertice; i++)
        visitados[i] = 0;
    
    infoNode infoNodes[numVertice];

    G = inicializar(numVertice);

    scanf("%d,%d", &inicio, &destino);

    while (inicio != 0 && destino != 0)
    {
        inserirAresta(G, inicio-1, destino-1);
        scanf("%d,%d", &inicio, &destino);
    }

    for (int i = 0; i < numVertice; i++)
    {
        if(visitados[i] == 0)
            DFS(G, visitados, i, &timestamp, infoNodes, &indice, &ciclico);        
    }
    
    for (int i = 0; i < numVertice; i++)
    {
        printf("%d [%d,%d]\n", infoNodes[i].numNode+1, infoNodes[i].timeInicial, infoNodes[i].timeFinal);
    }
    
    if (ciclico)
    {
        printf("aciclico: nao");
    }
    else
    {
        printf("aciclico: sim");
    }
    
    return 0;

}