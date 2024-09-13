#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct alunos
{
    double hestudos;
    double nmedias;
    int aprovacao;
} Alunos;

typedef struct data
{
    double distancia;
    int aprovacao;
} Data;

void construirHeap(Data *vetor, int k);
void inserirHeap(Data *vetor, int i, Data dado);
void deletarHeap(Data *vetor, int k);
void swap(Data *vetor, int ind1, int ind2);
int classificar(Alunos *alunos, int atreino, float mediateste, float horasteste, int k);

int main()
{
    int atreino, ateste, k;
    double mteste, hteste;

    scanf("%d %d %d", &atreino, &ateste, &k);

    Alunos *alunos = (Alunos *)malloc(sizeof(Alunos) * atreino);

    for (int i = 0; i < atreino; i++)
        scanf("%lf %lf %d", &alunos[i].nmedias, &alunos[i].hestudos, &alunos[i].aprovacao);

    for (int i = 0; i < ateste; i++)
    {
        scanf("%lf %lf", &mteste, &hteste);

        if (classificar(alunos, atreino, mteste, hteste, k))
            printf("Aluno %d: (%.2lf, %.2lf) = Aprovado\n", i, mteste, hteste);
        else
            printf("Aluno %d: (%.2lf, %.2lf) = Reprovado\n", i, mteste, hteste);
    }

    free(alunos);

    return 0;
}

int classificar(Alunos *alunos, int atreino, float mediateste, float horasteste, int k)
{
    Data *distancias = (Data *)malloc(sizeof(Data) * k);
    int aprovados = 0, reprovados = 0;

    for (int i = 0; i < k; i++)
    {
        distancias[i].distancia = pow(mediateste - alunos[i].nmedias, 2) + pow(horasteste - alunos[i].hestudos, 2);
        distancias[i].aprovacao = alunos[i].aprovacao;
    }

    construirHeap(distancias, k);


    for (int i = k; i < atreino; i++)
    {
        Data dist;
        dist.distancia = pow(mediateste - alunos[i].nmedias, 2) + pow(horasteste - alunos[i].hestudos, 2);
        dist.aprovacao = alunos[i].aprovacao;

        if (dist.distancia < distancias[0].distancia)
        {
            deletarHeap(distancias, k);
            inserirHeap(distancias, k-1, dist);
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (distancias[i].aprovacao == 1)
            aprovados++;
        else
            reprovados++;
    }

    free(distancias);

    if (aprovados > reprovados)
        return 1;

    return 0;
}

void construirHeap(Data *vetor, int k)
{
    for (int i = 1; i < k; i++)
        inserirHeap(vetor, i, vetor[i]);
}

void inserirHeap(Data *vetor, int i, Data dado)
{
    vetor[i] = dado;
    int pai = (i - 1) / 2;
    while (vetor[pai].distancia < vetor[i].distancia)
    {
        swap(vetor, pai, i);
        i = pai;
        pai = (pai - 1) / 2;
    }
}

void deletarHeap(Data *vetor, int k)
{
    swap(vetor, 0, k-1);
    int pai = 0;
    int fesq = 2 * pai + 1;
    int fdir = 2 * pai + 2;
    while (fesq < k-1)
    {
        int maior = pai;
        if (vetor[fesq].distancia > vetor[maior].distancia)
            maior = fesq;

        if (fdir < k-1 && vetor[fdir].distancia > vetor[maior].distancia)
            maior = fdir;

        if (maior != pai)
        {
            swap(vetor, maior, pai);
            pai = maior;
            fesq = 2 * pai + 1;
            fdir = 2 * pai + 2;
        }
        else
            break;
    }
}
void swap(Data *vetor, int ind1, int ind2)
{
    Data aux = vetor[ind1];
    vetor[ind1] = vetor[ind2];
    vetor[ind2] = aux;
}
