#include <stdlib.h>

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

int isIsolated(Graph *grafo, int v) {

    // Verifica se o vértice v não tem nenhum vizinho
    if (grafo->adj[v].size > 0) {
        return 0; // O vértice v não é isolado, pois possui vizinhos
    }

    // Verifica se algum outro vértice tem v como vizinho
    for (int i = 0; i < grafo->V; i++) {
        AdjListNode* temp = grafo->adj[i].head;
        while (temp != NULL) {
            if (temp->dest == v) {
                return 0; // Outro vértice i tem v como vizinho, então v não é isolado
            }
            temp = temp->next;
        }
    }

    // Se nenhuma das condições acima for verdadeira, o vértice v é isolado
    return 1;
}


void inserirAresta(Graph *grafo, int v, int w){

    AdjListNode *newNode = novoAdjListNode(w);
    newNode->next = grafo->adj[v].head;
    grafo->adj[v].head = newNode;
    grafo->adj[v].size++;

    grafo->A++;
}

void inserirArestas(Graph* grafo, int** edges, int edgesSize) {
    for (int i = 0; i < edgesSize; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];

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
