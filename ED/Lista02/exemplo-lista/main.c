#include <stdio.h>
#include "lista.h"

int main() {

	lista numeros = inicializar();
	iterador i = primeiro(numeros);
	i = inserirDepois( i, 10);
	i = inserirDepois( i, 20);
	i = inserirDepois( i, 30);
	i = inserirDepois( i, 10);
	i = inserirDepois( i, 30);
	i = inserirDepois( i, 20);
	i = inserirDepois( i, 20);
	i = inserirDepois( i, 30);
	
	for( iterador it = primeiro(numeros); 
	valido(it); it = proximo(it) ) {
		printf("Elemento %d\n", elemento(it));
	}
	
	printf("\n\n");
	
	for( iterador it = procuraPrimeiro(numeros, 20);
	 valido(it); it = procuraProximo(it, 20) ) {
		printf("Encontrado %d\n", elemento(it));
	}
	
	return 0;
}
