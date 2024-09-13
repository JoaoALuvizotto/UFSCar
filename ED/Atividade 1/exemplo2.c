#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <malloc.h>
#include <time.h> 

int bsequencial( long* vetor, long key, int n, int *count )
{
	int i = 0;
	*count += 1;
	while( (i < n) && (vetor[i] < key) ) {
		i++;
		*count += 1;
	}
	*count += 1;
	if ( (i < n) && (vetor[i] == key ) )
		return i;
	else
		return -1;
}

int bbinaria( long* vetor, long key, int n, int *count )
{
	int imax = n-1;
	int imin = 0;
	while( imax >= imin )
	{
		int imid = imin + ((imax - imin) / 2);
		*count += 1;
		if( key > vetor[imid] )
			imin = imid + 1;
		else {
			*count += 1;
			if( key < vetor[imid])
				imax = imid - 1;
			else
				return imid;
		}
	}	
	return -1;
}

int compare (const void * a, const void * b)
{
  return ( *(long*)a - *(long*)b );
}

int main( int argc, char* argv[] )
{
	assert(argc == 3);
	int n = atoi(argv[1]);
	int ntests = atoi(argv[2]);
	printf("Tamanho da entrada: %d\n", n);
	printf("Numero de testes: %d\n", ntests);
	
	assert( n > 0 );
	assert( ntests > 0 );
	long *V = (long*)malloc(sizeof(long)*n);
		
	srand (time(NULL));
	assert( LONG_MAX >= RAND_MAX );
	int i;
	for(i=0; i<n; i++)
		V[i] = rand() % RAND_MAX;
		
	qsort( V, n, sizeof(long), compare );
	
	printf("Execução de %d buscas sequenciais:\n", ntests);

	int acc = 0;
	for ( i=0; i<ntests; i++) {	
		int count = 0;
		bsequencial( V, V[rand() % n], n, &count);
		acc += count;
	}
	
	printf( "Comparações (media): %d\n\n", acc/ntests);	

	printf("Execução de %d buscas binárias:\n", ntests);

	acc = 0;
	for ( i=0; i<ntests; i++) {	
		int count = 0;
		bbinaria( V, V[rand() % n], n, &count);
		acc += count;
	}

	printf( "Comparações (media): %d\n", acc/ntests);	
	
	free(V);
	
	return 0;
}
