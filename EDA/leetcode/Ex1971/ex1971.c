#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
    int size;
    int grauEntrada; 
} AdjList;

typedef struct Graph {
    int A;        
    int V;        
    AdjList* adj; 
} Graph;

AdjListNode* novoAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* inicializar(int V) {
    Graph* grafo = (Graph*) malloc(sizeof(Graph));
    grafo->A = 0;
    grafo->V = V;

    grafo->adj = (AdjList*) malloc(V * sizeof(AdjList));

    for (int i = 0; i < V; i++) {
        grafo->adj[i].head = NULL;
        grafo->adj[i].size = 0;
        grafo->adj[i].grauEntrada = 0;
    }

    return grafo;
}

void inserirAresta(Graph *grafo, int v, int w){

    AdjListNode *newNode = novoAdjListNode(w);
    newNode->next = grafo->adj[v].head;
    grafo->adj[v].head = newNode;
    grafo->adj[w].grauEntrada++;
    grafo->adj[v].size++;

    grafo->A++;
}

void inserirArestas(Graph* grafo, int** edges, int edgesSize) {
    for (int i = 0; i < edgesSize; i++) {
        int src = edges[i][1];
        int dest = edges[i][0];

        AdjListNode* newNode = novoAdjListNode(dest);
        newNode->next = grafo->adj[src].head;
        grafo->adj[src].head = newNode;
        grafo->adj[src].size++;

        newNode = novoAdjListNode(src);
        newNode->next = grafo->adj[dest].head;
        grafo->adj[dest].head = newNode;
        grafo->adj[dest].size++;

        grafo->A++;
    }
}

void liberarGrafo(Graph* grafo) {
    for (int i = 0; i < grafo->V; i++) {
        AdjListNode* current = grafo->adj[i].head;
        while (current != NULL) {
            AdjListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(grafo->adj);
    free(grafo);
}

bool privateValidPath(Graph* g, int visitados[], int source, int destination)
{
    AdjListNode* p = g->adj[source].head;
    visitados[source] = 1;
    while (p != NULL)
    {

        if (visitados[p->dest] == destination)
        {
            return true;
        }
        
        if(privateValidPath(g, visitados, p->dest, destination))
        {
            return true;
        }

        p = p->next;
    }
    visitados[source] = 2;    

    return false;
}


bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    Graph*g = inicializar(n);

    int visitados[n];

    for (int i = 0; i < n; i++)
    {
        visitados[i] = 0;
    }
    

    inserirArestas(g, edges, edgesSize);
    
    return privateValidPath(g, visitados, source, destination);
    
}