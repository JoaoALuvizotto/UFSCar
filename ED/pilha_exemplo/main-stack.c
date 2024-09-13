#include <stdio.h>
#include "pilha.h"

int main() {

	pilha impares = inicializar(100);
	inserir(impares, 11);
	
	pilha pares = inicializar(1000);
	inserir(pares, 10);
	
	remover( impares );
	
	destruir(pares);
	
	if(impares->maximo == 1000)
		printf("qualquer coisa");
	
	int e;
	if (! topo(impares, &e) )
		printf("esta vazia");
	else {
		printf("nao esta vazia e seu topo eh: %d", e);
	}
	
	return 0;
}
