// João Augusto Luvizotto
//RA: 823078
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct renas
{
    char nome[100];
    int peso;
    int idade;
    float altura;
}Renas;

void bubblesort(Renas vetor[], int totalRenas);
void troca(Renas vetor[], int indice1, int indice2);

int main()
{
    int totalRenas, trenoRenas;
    Renas renas[1000];

    scanf("%d %d", &totalRenas, &trenoRenas);
    
    for(int i = 0; i < totalRenas; i++)
        scanf("%s %d %d %f", renas[i].nome, &renas[i].peso, &renas[i].idade, &renas[i].altura);

    bubblesort(renas, totalRenas);
    printf("CENARIO\n");
    for (int i = 0; i < trenoRenas; i++)
    {
        printf("%d - %s\n", i+1, renas[i].nome);
    }

    return(0);
}
/*Ordena as Renas de acordo o que foi pedido no exercício*/
void bubblesort(Renas vetor[], int totalRenas)
{
    int trocou = 0, i = 0;

    do
    {
        for (int k = totalRenas-1; k > i; k--)
        {
            if (vetor[k-1].peso < vetor[k].peso)
            {
                troca(vetor, k-1, k);
                trocou = 1;
            }
            else if (vetor[k-1].peso == vetor[k].peso && vetor[k-1].idade > vetor[k].idade)
            {
                troca(vetor, k-1, k);
                trocou = 1;
            }
            else if (vetor[k-1].peso == vetor[k].peso && vetor[k-1].idade == vetor[k].idade && vetor[k-1].altura > vetor[k].altura)
            {
                troca(vetor, k-1, k);
                trocou = 1;
            }
            else if (vetor[k-1].peso == vetor[k].peso && vetor[k-1].idade == vetor[k].idade && vetor[k-1].altura == vetor[k].altura && strcmp(vetor[k-1].nome, vetor[k].nome) > 0)
            {
                troca(vetor, k-1, k);
                trocou = 1;
            }
            
        }
        i++;
    } while (trocou && i < totalRenas);
    
    
}
/*Troca as Renas de lugar */
void troca(Renas vetor[], int indice1, int indice2)
{
    Renas aux;

    aux = vetor[indice1];
    vetor[indice1] = vetor[indice2];
    vetor[indice2] = aux;
}