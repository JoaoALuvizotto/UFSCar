//Joao Augusto Luvizotto RA:823078
#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

void quicksort(int vetor[], int vetor2[], int imin, int imax);
int partition(int vetor[], int imin, int imax, int pivo);
void swap(int vetor[], int i, int j);
/*a estrategia usada neste programa foi pegar um item de um vetor e usar este como pivo para a aplicacao do algoritmo
do quicksort no outro vetor*/
int main()
{
    int qtde, porcas[MAX], parafusos[MAX];

    scanf("%d", &qtde);

    for (int i = 0; i < qtde; i++)
        scanf("%d", &parafusos[i]);
    
    for (int i = 0; i < qtde; i++)
        scanf("%d", &porcas[i]);


    quicksort(parafusos, porcas, 0, qtde-1);


    for (int i = 0; i < qtde; i++)
    {
        printf("%d - %d\n", porcas[i], parafusos[i]);
    }
     
}
// algoritmo de ordenacao quicksort
void quicksort(int vetor[], int vetor2[], int imin, int imax)
{
    if (imax <= imin)
        return;

    int pivo = vetor2[imax];
        
    int i = partition(vetor, imin, imax, pivo);
    partition(vetor2, imin, imax, vetor[i]);

    quicksort(vetor, vetor2, imin, i - 1);
    quicksort(vetor, vetor2, i + 1, imax);
}
//partition que faz parte do quicksort, realiza a separacao entre os itens menores e maiores que o pivo
/*esta impletamentacao eh diferente da vista em aula, ela vai "jogando" para o final do vetor (realizando trocas 
entre as posicoes) os numeros maiores que o pivo e deixando antes do pivo os menores*/
int partition(int vetor[], int imin, int imax, int pivo)
{
    int i = imin - 1;

    for (int j = imin; j < imax; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            swap(vetor, i, j);
        }

        if (vetor[j] == pivo)
        {
            swap(vetor, j, imax);
            j--;
        }
        
        
    }
    swap(vetor, i+1, imax);
    
    return(i+1);
}

void swap(int vetor[], int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}