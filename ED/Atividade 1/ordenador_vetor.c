#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 1000

void troca(long int vetor[], int aux1, int aux2);

int main()
{
    long long int qtdComp = 0, qtdTroca = 0;
    long int vetor[TAM_VETOR];

    srand(time(NULL));

    for (int i = 0; i < TAM_VETOR; i++)
        vetor[i] = rand() % RAND_MAX;
    
    clock_t start, end;
	double cpu_time_used = 0;
	start = clock();
	for (int i = 1; i < TAM_VETOR; i++)
    {
        int k = i;
        while (k > 0 )
        {   
            if (vetor[k-1] > vetor[k])
            {  
                troca(vetor, k-1, k);
                qtdComp++; 
                qtdTroca++;
                k--;
            }
            else
            {
                qtdComp++;
                k = 0;
            }
        }
    }
	end = clock();
	cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;

    /*for (int i = 0; i < TAM_VETOR; i++)
        printf("%ld ", vetor[i]);*/
    
    printf("\n");
    printf("qtd comparacoes: %lld\n qtd Trocas: %lld \n", qtdComp, qtdTroca);
	printf( "Tempo médio: %lf\n\n", cpu_time_used);	
}

void troca(long int vetor[], int aux1, int aux2)
{
    int armazena = 0;

    armazena = vetor[aux1]; 
    vetor[aux1] = vetor[aux2];
    vetor[aux2] = armazena;
}

