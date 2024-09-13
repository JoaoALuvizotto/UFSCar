#include <stdio.h>
#include <stdlib.h>

typedef struct Coordenada 
{
    int row;
    int column;
    int value;
} coordenada;


int comparaCoordenadas(const void* a, const void* b);
int procurarCoordenadas(int A[], int C[], int R[], int iprocurado, int jprocurado, int hrow, int hcolomn);

int main()
{
    int num, hrow, hcolomn;

    scanf("%d", &num);

    coordenada* vetor = (coordenada*) malloc(sizeof(coordenada)* num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &vetor[i].row, &vetor[i].column, &vetor[i].value);
    }
    
    hrow = vetor[0].row;
    for (int i = 0; i < num; i++)
    {
        if (vetor[i].row > hrow)
            hrow = vetor[i].row;
    }
    hrow++;

    hcolomn = vetor[0].column;
    for (int i = 0; i < num; i++)
    {
        if (vetor[i].column > hcolomn)
            hcolomn = vetor[i].column;
    }
    hcolomn++;

    qsort(vetor, num, sizeof(coordenada), comparaCoordenadas);

    int* A = (int*) malloc(sizeof(int) * num);
    int* C = (int*) malloc(sizeof(int) * num);
    int* R = (int*) malloc(sizeof(int) * hrow+1);

    int l_atual = -1;
    
    for (int i = 0, h = 0; i < num; i++)
    {
        A[i] = vetor[i].value;
        C[i] = vetor[i].column;

        if (vetor[i].row != l_atual)
        {
            l_atual = vetor[i].row; 

            for (int j = h; j <= vetor[i].row; j++)
            {
                R[h] = i;
                h++;
            } 
        }
    }
     R[hrow] = num;

    int iprocurado, jprocurado;
    while (1)
    {
        scanf("%d %d", &iprocurado, &jprocurado);
        if (iprocurado == -1)
            break;
        
        printf("(%d,%d) = %d\n", iprocurado, jprocurado, procurarCoordenadas(A, C, R, iprocurado, jprocurado, hrow, hcolomn));
        

    }
    
    free(A);
    free(C);
    free(R);
    free(vetor);
    return 0;
}

int procurarCoordenadas(int A[], int C[], int R[], int iprocurado, int jprocurado, int hrow, int hcolomn)
{

    if (jprocurado > hcolomn - 1 || iprocurado > hrow - 1)
        return 0;

    if (R[iprocurado] == R[iprocurado + 1])
        return 0;
    else
        for (int b = R[iprocurado]; b <= R[iprocurado + 1] - 1; b++)
            if (C[b] == jprocurado)
                return A[b];
    
    return 0;
}


int comparaCoordenadas(const void* a, const void* b) 
{
    const coordenada* coordenaA = (const coordenada*)a;
    const coordenada* coordenaB = (const coordenada*)b;
    if (coordenaA->row != coordenaB->row) {
        return coordenaA->row - coordenaB->row;
    } 
    else {
        return coordenaA->column - coordenaB->column;
    }
}