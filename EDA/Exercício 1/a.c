#include <stdio.h>

void swap(int vetor[], int ind1, int ind2)
{
    int aux = vetor[ind1];
    vetor[ind1] = vetor[ind2];
    vetor[ind2] = aux;
}

void construirHeap(int vetor[], int k)
{
    for (int i = 1; i < k; i++)
    {
        int pai = (i-1)/2;
        while (vetor[pai] < vetor[i])
        {
            swap(vetor, pai, i);
            pai = (pai-1)/2;
        }
        
    }
    
}

void inserirHeap(int vetor[], int i, int dado)
{
    vetor[i] = dado;
    int pai = (i - 1) / 2;
    while (vetor[pai] < vetor[i])
    {
        swap(vetor, pai, i);
        i = pai;
        pai = (pai - 1) / 2;
    }
}

/*void inserirHeap(int vetor[], int i, int dado)
{
    vetor[i] = dado;
    int filho = i;
    int pai = (filho - 1) / 2;
    while (filho > 0 && vetor[pai] < vetor[filho])
    {
        swap(vetor, pai, filho);
        filho = pai;
        pai = (filho - 1) / 2;
    }
}*/


void deletarHeap(int vetor[], int k)
{
    swap(vetor, 0, k-1);
    int pai = 0;
    int fesq = 2 * pai + 1;
    int fdir = 2 * pai + 2;
    while (fesq < k-1)
    {
        int maior = pai;
        if (vetor[fesq] > vetor[maior])
        {
            maior = fesq;
        }
        if (fdir < k-1 && vetor[fdir] > vetor[maior])
        {
            maior = fdir;
        }
        if (maior != pai)
        {
            swap(vetor, maior, pai);
            pai = maior;
            fesq = 2 * pai + 1;
            fdir = 2 * pai + 2;
        }
        else
        {
            break;
        }
    }
}


int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        inserirHeap(vetor, i, i);
    }
    //construirHeap(vetor, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    /*for (int i = 10; i > 0; i--)
    {
        deletarHeap(vetor, i);
        printf("\n");
        for (int i = 0; i < 7; i++)
        {
            printf("%d ", vetor[i]);
        }
    }*/
    


    return 0;
}