#ifndef LISTA_H
#define LISTA_H

typedef struct Carro
{
    char placa[9];
    char modelo_marca[30];
    char cor[30]; 
} Carro;


typedef Carro T;

typedef struct node
{
    T data;
    struct node *proximo;
    struct node *anterior;
}Node;

typedef struct lista
{
    Node* sentinela;
    int quantidade;
}Lista;

typedef struct iterador
{
    Node *elemento;
    Lista *lista;
}Iterador;


Lista* inicializar();
int vazio(Lista*);
int inserirI(Lista*, T);
int inserirF(Lista*, T);
int removerI(Lista*, T*);
int removerF(Lista*, T*);
void CABOOOOM(Lista*);
Iterador inserirDepois(Iterador, T);
Iterador removerElemento(Iterador);
Iterador proximo(Iterador);
Iterador primeiro(Lista*);
Iterador anterior(Iterador);
Iterador ultimo(Lista*);
T conteudo(Iterador);
int valido(Iterador);


#endif