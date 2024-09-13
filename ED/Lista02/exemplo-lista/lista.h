#ifndef LISTA_H
#define LISTA_H

typedef int T;

struct _node {
	T data;
	struct _node* proximo;
	struct _node* anterior;
};
typedef struct _node node;

struct _lista {
	node* sentinela;
	unsigned quantidade;
};

typedef struct _lista* lista;

typedef struct {
	node* elemento;
	lista l;
} iterador;

lista inicializar();
void destruir( lista );

iterador primeiro( lista );
iterador proximo( iterador );
int valido( iterador );
T elemento( iterador );

iterador inserirDepois( iterador, T );

iterador remover( iterador );

iterador procuraPrimeiro( lista, T );
iterador procuraProximo( iterador, T );
#endif
