#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void BFS(int** matrizAdj, int inicialV, int numV, int distance[], int visited[])
{
    Deque* fila;
    int removido;
    fila = inicializarDeque(numV);

    insereF(fila, inicialV);
    visited[inicialV] = 1;

    printf("Origem da busca: %d\n", inicialV + 1);
    printf("Vertices alcancados e distancias:\n");

    while (!vazio(fila))
    {
        removeI(fila, &removido);
        printf("%d %d\n", removido + 1, distance[removido]);
        for (int i = 0; i < numV; i++)
        {   
            if (!visited[i] && matrizAdj[removido][i] == 1)
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

    // Lê o número de vértices
    scanf("%d", &numV);

    // Inicializa as distâncias e os visitados
    int distance[numV], visited[numV];
    for (int i = 0; i < numV; i++)
    {
        distance[i] = 0;  // Inicializa as distâncias como -1 (não alcançado)
        visited[i] = 0;    // Marca todos os vértices como não visitados
    }

    // Aloca memória para a matriz de adjacência
    matrizAdj = (int**)malloc(sizeof(int*) * numV);
    for (int i = 0; i < numV; i++)
    {
        matrizAdj[i] = (int*)malloc(sizeof(int) * numV);
        for (int j = 0; j < numV; j++)
            matrizAdj[i][j] = 0;
    }

    // Lê as arestas do grafo
    while (scanf("%d,%d", &inicio, &destino), inicio != 0 && destino != 0)
    {
        matrizAdj[inicio - 1][destino - 1] = 1;
        matrizAdj[destino - 1][inicio - 1] = 1;
    }

    // Lê o vértice inicial para a BFS
    scanf("%d", &inicialV);
    
    // Executa a busca em largura
    BFS(matrizAdj, inicialV - 1, numV, distance, visited);

    // Libera a memória alocada para a matriz de adjacência
    for (int i = 0; i < numV; i++)
        free(matrizAdj[i]);
    free(matrizAdj);

    return 0;
}
