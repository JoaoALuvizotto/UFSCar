#include <stdlib.h>
#include "lista.h"

lista inicializar() {
	lista l = (lista)malloc(sizeof(struct _lista));
	l->sentinela = (node*)malloc(sizeof(node));
	l->sentinela->proximo = l->sentinela;
	l->sentinela->anterior = l->sentinela;
	l->quantidade = 0;
	return l;
}

void destruir(lista l) {
	// implementar!
}

iterador primeiro(lista l) {
	iterador i;
	i.elemento = l->sentinela->proximo;
	i.l = l;
	return i;
}

iterador proximo( iterador i ){
	i.elemento = i.elemento->proximo;
	return i;
}

int valido( iterador i ) {
	return i.elemento != i.l->sentinela;
}

T elemento( iterador i ) {
	return i.elemento->data;
}

// retorno é um iterador para o novo elemento
iterador inserirDepois( iterador i, T data) {
	node *n = (node*) malloc(sizeof(node));
	n->data = data;
	n->proximo = i.elemento->proximo;
	n->anterior = i.elemento;
	i.elemento->proximo->anterior = n;
	i.elemento->proximo = n;
	i.l->quantidade++;
	i.elemento = n;
	return i;
}

// retorna o anterior ao removido
iterador remover( iterador i ) {
	if( i.elemento != i.l->sentinela ) {
		node *n = i.elemento;
		i.elemento = i.elemento->anterior;
		i.elemento->proximo = n->proximo;
		n->proximo->anterior = i.elemento;
		i.l->quantidade--;
		free(n);
	}
	return i;
}

iterador procuraPrimeiro( lista l, T data ) {
	iterador i;
	i.elemento = l->sentinela;
	i.l = l;
	return procuraProximo(i, data);
}

iterador procuraProximo( iterador i, T data) {
	i = proximo(i);
	while( valido(i) ) {
		if( elemento(i) == data )
			return i;
		i = proximo(i);
	}
	return i;
}
