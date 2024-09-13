//Joao Augusto Luvizotto RA:823078
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

void mergesort(int vetor[], int aux[], int imin, int imax);
void merge(int vetor[], int aux[], int imin, int imid, int imax);
void swap(int vetor[], int i, int j);
int buscabinaria(int vetor[], int tamanho, int procurar);

int main()
{
    int pot, t_garrafas;

    scanf("%d", &pot);

    int *pots = (int*) malloc(sizeof(int) * pot), *aux = (int*) malloc(sizeof(int) * pot);

    for (int i = 0; i < pot; i++)
        scanf("%d", &pots[i]);
    
    scanf("%d", &t_garrafas);

    int *garrafas = (int*) malloc(sizeof(int) * t_garrafas);

    for (int i = 0; i < t_garrafas; i++)
        scanf("%d", &garrafas[i]);

    mergesort(pots, aux, 0, pot-1);

    

    for (int i = 0; i < t_garrafas; i++)
    {
        int indbusca = buscabinaria(pots, pot, garrafas[i]);
        if (indbusca != -1)
        {
            printf("%d\n", pots[indbusca]);
        }
        else
            printf("descartar\n");
        
    }
    

}
//algoritmo de ordenacao 
void mergesort(int vetor[], int aux[], int imin, int imax)
{
    if (imax <= imin)
        return;
    
    int imid = imin + ((imax - imin) / 2);
    
    mergesort(vetor, aux, imin, imid);
    mergesort(vetor, aux, imid+1, imax);
    merge(vetor, aux, imin, imid, imax);
}
//ordena os vetores menores e os coloca no maior
void merge(int vetor[], int aux[], int imin, int imid, int imax)
{
    int i = imin, j = imid+1;
    for (int k = imin; k <= imax; k++)
        aux[k] = vetor[k];
    for (int k = imin; k <= imax; k++)
        if (i > imid)
            vetor[k] = aux[j++];
        else if(j > imax)
            vetor[k] = aux[i++];
        else if(aux[j] < aux[i])
            vetor[k] = aux[j++];
        else
            vetor[k] = aux[i++];
}

void swap(int vetor[], int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}
//faz a busca do item necessario
int buscabinaria(int vetor[], int tamanho, int procurar)
{
    int imin = 0, imax = tamanho-1, imid = imin + ((imax - imin)/2);

    while (imin <= imax)
    {
        imid = imin + (imax - imin)/2;

        if (vetor[imid] == procurar)
            return imid;
        else if (vetor[imid] < procurar)
            imin = imid+1;
        else
            imax = imid-1;
    }
    if (vetor[imax] < procurar)
    {
        return imax;
    }
    else
        return -1;
    
    
    
       
}