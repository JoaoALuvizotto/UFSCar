#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void BFS(int** matriAdj, int inicialV, int numV, int distance[], int visited[])
{
    Deque* fila;
    int removido;
    fila = inicializarDeque(numV);

    insereF(fila, inicialV);
    visited[inicialV] = 1;
    distance[inicialV] = 0;
    printf("Origem da busca: %d\n", inicialV+1);
    printf("Vertices alcancados e distancias:\n");
    while (!vazio(fila))
    {
        removeI(fila, &removido);
        printf("%d %d\n", removido+1, distance[removido]);
        for (int i = 0; i < numV; i++)
        {   
            if (matriAdj[removido][i] == 1 &&visited[i] == 0 )
            {
                insereF(fila, i);
                distance[i] = distance[removido] + 1;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int** matrizAdj;
    int numV, inicio, destino, inicialV;

    scanf("%d", &numV);

    int distance[numV], visited[numV];

    for (int i = 0; i < numV; i++)
    {
        distance[i] = -1; 
        visited[i] = 0;    
    }

    matrizAdj = (int**)malloc(sizeof(int*) * numV);

    for (int i = 0; i < numV; i++)
    {
        matrizAdj[i] = (int*)malloc(sizeof(int) * numV);
        
        for (int j = 0; j < numV; j++)
            matrizAdj[i][j] = 0;
    }

    while (scanf("%d,%d", &inicio, &destino) == 2 && inicio != 0 && destino != 0) 
    {
        matrizAdj[inicio - 1][destino - 1] = 1;
        matrizAdj[destino - 1][inicio - 1] = 1;
    }
    
    scanf("%d", &inicialV);
    
    BFS(matrizAdj, inicialV - 1, numV, distance, visited);

    for (int i = 0; i < numV; i++)
    {
        free(matrizAdj[i]);
    }
    free(matrizAdj);

    return 0;
}
