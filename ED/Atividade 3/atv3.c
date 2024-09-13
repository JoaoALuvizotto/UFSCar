//João Augusto Luvizotto 
//RA:823078
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunos
{
    char nome[15];
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
    Times *times = (Times*)malloc(1000 * sizeof(Times));
    int qtdAlunos, qtdTimes;

    scanf("%d %d", &qtdAlunos, &qtdTimes);

    for (int i = 0; i < qtdAlunos; i++)
    {
        scanf("%s %ld", alunos[i].nome, &alunos[i].habilidade);
    }

    bubblesort(alunos, qtdAlunos);
    //inicializando a variavel qtd jogador de cada time como zero pq se não inicializar fica com lixo
    for (int i = 0; i < qtdTimes; i++)
    {
        times[i].qtdJogadores = 0;
    }
    /*distribuindo os jogadores nos times */ 
    for (int i = 0, j = 0, y = 0; i < qtdAlunos; i++, j++)
    {
        /*para não colocar jogadores em mais times do que foi pedido*/
        if (j == qtdTimes)
        {
            j = 0;
            y++;
        }
        /*coloca os jogadores nos times e me da a quantidade jogadores de cada time (para não acessar indice errado dps)*/
        times[j].jogadores[y] = alunos[i];
        times[j].qtdJogadores++;  
    }
    /*ordena os times alfabeticamente*/
    for (int i = 0; i < qtdTimes; i++)
    {
        bubbleAlfa(times, i);
    }
    /*printa os times*/
    for (int i = 0; i < qtdTimes; i++)
    {
        printf("Time %d\n", i+1);
        for (int j = 0; j < times[i].qtdJogadores; j++)
        {
            printf("%s\n", times[i].jogadores[j].nome);
        }
        printf("\n");
    }
    
    return(0);
    /*libera a memória usada no vetor*/
    free(times);
}
/*ordena os alunos usando a habilidade dele como parâmetro*/
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
/*realiza a troca entre os alunos*/
void troca(Alunos vetor[], int indice1, int indice2)
{
    Alunos aux;

    aux = vetor[indice1];
    vetor[indice1] = vetor[indice2];
    vetor[indice2] = aux;

}
/*faz a ordenação alfabética de cada time vendo qual nome é menor, usando a strcmp para comparar qual 
nome que é menor (alfabeticamente primeiro)*/
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
/*realiza as trocas dos jogadores dos times*/
void trocaAlfa(Times vetor[], int indiceTime, int indice1, int indice2)
{
    Alunos aux;

    aux = vetor[indiceTime].jogadores[indice1];
    vetor[indiceTime].jogadores[indice1] = vetor[indiceTime].jogadores[indice2];
    vetor[indiceTime].jogadores[indice2] = aux;

}

