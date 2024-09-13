#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct alunos
{
    float hestudos;
    float nmedias;
    int aprovacao;
    float distancia;
}Alunos;

int classificar(Alunos* alunos, int atreino, float mediateste, float horasteste, int k);

int comparar(const void *a, const void *b);

int main()
{
    int atreino, ateste, k;
    float mteste, hteste;

    scanf("%d %d %d", &atreino, &ateste, &k);

    Alunos* alunos = (Alunos*) malloc (sizeof(Alunos)*atreino);

    for (int i = 0; i < atreino; i++)
    {
        scanf("%f %f %d", &alunos[i].nmedias, &alunos[i].hestudos, &alunos[i].aprovacao);
    }
    
    for (int i = 0; i < ateste; i++)
    {
        scanf("%f %f", &mteste, &hteste);

        if (classificar(alunos, atreino, mteste, hteste, k))
        {
            printf("Aluno %d: (%.2f, %.2f) = Aprovado\n", i, mteste, hteste);
        }
        else
        {
            printf("Aluno %d: (%.2f, %.2f) = Reprovado\n", i, mteste, hteste);
        }
        
    }
    

    return 0;
}

int classificar(Alunos* alunos, int atreino, float mediateste, float horasteste, int k)
{
    int aprovados = 0, reprovados = 0;
    for (int i = 0; i < atreino; i++)
    {
        alunos[i].distancia = pow(mediateste - alunos[i].nmedias, 2) + pow(horasteste - alunos[i].hestudos, 2);
    }

    qsort(alunos, atreino, sizeof(Alunos), comparar);

    for (int i = 0; i < k; i++)
    {   
        if (alunos[i].aprovacao == 1)
        {
            aprovados++;
        }
        else
        {
            reprovados++;
        }
        
    }

    if (aprovados > reprovados)
    {
        return 1;
    }
    
    return 0;

}

int comparar(const void *a, const void *b)
{
    Alunos *aluno_a = (Alunos *)a;
    Alunos *aluno_b = (Alunos *)b;

    if (aluno_a->distancia > aluno_b->distancia)
        return 1;
    else if (aluno_a->distancia == aluno_b->distancia)
        return 0;    
    else return -1;
    
}