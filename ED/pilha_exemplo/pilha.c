#include <stdlib.h>
#include "pilha.h"

pilha inicializar( int max ) {
	pilha p = (pilha)malloc(sizeof(_pilha));
	if(!p) return 0;
	p->maximo = max;
	p->topo = 0;
	p->tamanho = 0;
	return p;
}

void destruir( pilha p ) {
	while(!vazio(p))
		remover(p);
}

int inserir( pilha p, T elemento) {
	if(p->tamanho < p->maximo) {
		struct _no* novo = (struct _no*)malloc(sizeof(struct _no));
		if(!novo) return 0;
		novo->elemento = elemento;
		novo->link = p->topo;
		p->topo = novo;
		p->tamanho++;		
		return 1;
	}
	else
		return 0;
}

int vazio( pilha p ) {
	return p->topo == 0; // p->tamanho == 0
}

int remover( pilha p) {
	if( !vazio(p) ) {
		struct _no* e = p->topo;
		p->topo = p->topo->link;
		free(e);
		p->tamanho--;
		return 1;
	}
	return 0;
}

int topo( pilha p, T *elemento ) {
	if( !vazio(p)) {
		*elemento = p->topo->elemento;
		return 1;
	}
	return 0;
}
