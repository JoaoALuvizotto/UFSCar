// João Augusto Luvizotto
// RA:823078
// Atividade 02 - Estrutura de Dados - Poções(Embalagem)  
#include <stdio.h>
#include <stdlib.h>

#define NUM_EMBALAGENS 10000
#define NUM_GARRAFAS 1000000

int busca_binaria(long vetor[], long pot, int tam_vetor);
void insertion(long vetor[], long qtd_elementos);
void troca(long vetor[], long indice1, long indice2);

int main()
{
    long embalagens[NUM_EMBALAGENS], *garrafas = (long *)malloc(sizeof(long) * NUM_GARRAFAS), qtdGarrafas = 0, qtdembalagens = 0, *embalados = (long *)malloc(sizeof(long) * NUM_GARRAFAS);

    scanf("%ld", &qtdembalagens);

    for (int i = 0; i < qtdembalagens; i++)
        scanf("%ld", &embalagens[i]);

    scanf("%ld", &qtdGarrafas);
    
    for (int i = 0; i < qtdGarrafas; i++)
        scanf("%ld", &garrafas[i]);
    
    insertion(embalagens, qtdembalagens);

    
    for (int i = 0, j = 0; i < qtdGarrafas; i++, j++    )
    {   
        if (busca_binaria(embalagens, garrafas[i], qtdembalagens) == -1)
            embalados[j] = 0;
        
        else
            embalados[j] = embalagens[busca_binaria(embalagens, garrafas[i], qtdembalagens)];

    }

    for (int i = 0; i < qtdGarrafas; i++)
    {
        if (embalados[i] == 0)
        {
            printf("descartar\n");
            continue;
        }
        
        printf("%ld\n", embalados[i]);
    
    }    

    free(embalados);
    free(garrafas);
        
    return (0);

}

int busca_binaria(long vetor[], long pot, int tam_vetor)
{
    int indmax = tam_vetor-1, indmin = 0, indmid = 0;

    while (indmax >= indmin)
    {
        indmid = indmin + ((indmax - indmin) / 2);

        if (pot > vetor[tam_vetor-1])
            return(-1);

        if (pot > vetor[indmid])
            indmin = indmid + 1;

        else if (pot < vetor[indmid])
            indmax = indmid - 1;
        
        else
            return indmid;
        
    }
    return (indmin);

}
void insertion(long vetor[], long qtd_elementos)
{
    for (int i = 1; i < qtd_elementos; i++)
    {
        int k = i;
        while(k > 0 && vetor[k-1] > vetor[k])
        {
            troca(vetor, k-1, k);
            k--;
        }   
        
    }
    
}
void troca(long vetor[], long indice1, long indice2)
{
    int aux = 0;
    aux = vetor[indice1];
    vetor[indice1] = vetor[indice2];
    vetor[indice2] = aux;
}
