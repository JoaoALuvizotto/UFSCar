#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunos
{
    char nome[50];
    long int habilidade;
}Alunos;

typedef struct times_futebol
{
    Alunos jogadores[5000];
    int qtdJogadores;
}Times;

void bubblesort(Alunos vetor[], int qtdAlunos);
void troca(Alunos vetor[], int indice1, int indice2);
void bubbleAlfa(Times vetor[], int indiceTime);
void trocaAlfa(Times vetor[], int indiceTime, int indice1, int indice2);

int main()
{
    Alunos alunos[10000];
    Times *times = (Times *)malloc(1000 * sizeof(Times));
    int qtdAlunos, qtdTimes;

    scanf("%d %d", &qtdAlunos, &qtdTimes);

    for (int i = 0; i < qtdAlunos; i++)
    {
        scanf("%s %ld", alunos[i].nome, &alunos[i].habilidade);
    }

    bubblesort(alunos, qtdAlunos);
    /*printf("================================================================\n");
    
    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("%s %ld", alunos[i].nome, alunos[i].habilidade);
        printf("\n");
    }*/
    for (int i = 0; i < qtdTimes; i++)
    {
        times[i].qtdJogadores = 0;
    }
    
    for (int i = 0, j = 0, y = 0; i < qtdAlunos; i++, j++)
    {
        times[i % qtdTimes].jogadores[times[i % qtdTimes].qtdJogadores] = alunos[i];
        times[i % qtdTimes].qtdJogadores++;
    }

    for (int i = 0; i < qtdTimes; i++)
    {
        bubbleAlfa(times, i);
    }
    
    for (int i = 0; i < qtdTimes; i++)
    {
        printf("Time %d\n", i+1);
        for (int j = 0; j < times[i].qtdJogadores; j++)
        {
            printf("%s\n", times[i].jogadores[j].nome);
        }
        printf("\n");
    }

    free(times);
    return(0);    
}

void bubblesort(Alunos vetor[], int qtdAlunos)
{
    int trocou, i = 0;

    do
    {
        trocou = 0;
        for (int k = qtdAlunos-1; k > i; k--)
        {
            if (vetor[k-1].habilidade < vetor[k].habilidade)
            {
                troca(vetor,k-1,k);
                trocou = 1;
            }   
        }
        i++;
    } while (trocou && i < qtdAlunos);
    
}

void troca(Alunos vetor[], int indice1, int indice2)
{
    Alunos aux;

    aux = vetor[indice1];
    vetor[indice1] = vetor[indice2];
    vetor[indice2] = aux;

}

void bubbleAlfa(Times vetor[], int indiceTime)
{
    int trocou, i = 0;

    do
    {
        trocou = 0;
        for (int k = vetor[indiceTime].qtdJogadores-1; k > 0; k--)
        {
            if (strcmp(vetor[indiceTime].jogadores[k-1].nome, vetor[indiceTime].jogadores[k].nome) > 0)
            {
                trocaAlfa(vetor,indiceTime,k-1,k);
                trocou = 1;
            }       
        }
        i++;
    } while (trocou && i < vetor[indiceTime].qtdJogadores);
}

void trocaAlfa(Times vetor[], int indiceTime, int indice1, int indice2)
{
    Alunos aux;

    aux = vetor[indiceTime].jogadores[indice1];
    vetor[indiceTime].jogadores[indice1] = vetor[indiceTime].jogadores[indice2];
    vetor[indiceTime].jogadores[indice2] = aux;

}

