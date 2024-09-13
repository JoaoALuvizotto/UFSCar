#include <stdio.h>
#define MAX 500
void selectionsort(int vetor[], int n, int i);

int main()
{
    int vetor[MAX], qtdnum;

    scanf("%d", &qtdnum);
    
    for (int i = 0; i < qtdnum; i++)
        scanf("%d", &vetor[i]);

    selectionsort(vetor, qtdnum, 0);

    for (int i = 0; i < qtdnum; i++)
        printf("%d ", vetor[i]);

    return 0;
}

void swap(int v[], int a, int b)
{ 
    int t=v[a]; 
    v[a]=v[b]; 
    v[b]=t;
}

void selectionsort(int vetor[], int n, int i)
{
    if (i >= n-1)
    {
        return;
    }
    else
    {
        int min = i;
            for (int j = i+1; j < n; j++)
                if (vetor[j] < vetor[min])
                    min = j;
        
        swap(vetor,i,min);

        selectionsort(vetor, n, i+1);
    }
}