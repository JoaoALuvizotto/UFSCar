#ifndef PILHA_H
#define PILHA_H

typedef int T;

struct _no {
	T elemento;
	struct _no* link;
};
typedef struct {
	struct _no* topo;
	int maximo;
	int tamanho;
} _pilha;

typedef _pilha* pilha;

pilha inicializar( int max);
void destruir( pilha p );
int inserir( pilha p, T elemento);
int vazio( pilha p );
int remover( pilha p);
int topo( pilha p, T *elemento);

#endif
