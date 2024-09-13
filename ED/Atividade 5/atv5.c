//João Augusto Luvizotto RA:823078
#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 500
//declaracao das funcoes que serao utilizadas
int funcmaior(int qtdnum, int vetor[], int maior);
int funcmenor(int qtdnum, int vetor[], int menor);
int funcsoma(int qtdnum, int vetor[], int somatoria);
int funccrescente(int qtdnum, int vetor[]);
int funcdecrescente(int qtdnum, int vetor[]);
int funcpalindromo(int qtdnum, int vetor[], int cont);

int main()
{
    int qtdnum, num[NUM_MAX], maior, menor, soma = 0, crescente, decrescente, i = 0, espelhada = 0;

    scanf("%d", &qtdnum);
    
    for (int i = 0; i < qtdnum; i++)
    {
        scanf("%d", &num[i]);
    }

    maior = funcmaior(qtdnum-1, num, num[0]);
    menor = funcmenor(qtdnum-1, num, num[0]);
    soma = funcsoma(qtdnum-1, num, soma);
    crescente = funccrescente(qtdnum-1, num);
    decrescente = funcdecrescente(qtdnum-1, num);
    espelhada = funcpalindromo(qtdnum-1, num, i);
    
    printf("Soma: %d\n", soma);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Crescente: ");
    if (crescente)
        printf("sim\n");
    else
        printf("nao\n");
    printf("Decrescente: ");
    if (decrescente)
        printf("sim\n");
    else
        printf("nao\n");
    printf("Espelhada: ");
    if (espelhada)
        printf("sim\n");
    else
        printf("nao\n");
    
    
    return(0);
}
//pegando o maior numero
int funcmaior(int qtdnum, int vetor[], int maior)
{
    if (qtdnum >= 0)
    {
        if (vetor[qtdnum] > maior)
            maior = vetor[qtdnum]; 
        
        return funcmaior(qtdnum-1, vetor, maior);
    }
    else
        return(maior);

    
}
//pegando o menor numero
int funcmenor(int qtdnum, int vetor[], int menor)
{
    if (qtdnum >= 0)
    {
        if (vetor[qtdnum] < menor)
            menor = vetor[qtdnum]; 
        
        return funcmenor(qtdnum-1, vetor, menor);
    }
    else
        return(menor);
}
//somando todos os numeros
int funcsoma(int qtdnum, int vetor[], int somatoria)
{
    if (qtdnum >= 0)
    {
        somatoria += vetor[qtdnum];
        return funcsoma(qtdnum-1, vetor, somatoria);
    }
    else
        return(somatoria);
        
    
}
//verificando se o vetor e crescente 
int funccrescente(int qtdnum, int vetor[])
{
    if (qtdnum > 0)
    {
        if (vetor[qtdnum] > vetor[qtdnum-1])
            return funccrescente(qtdnum-1, vetor);
        else
            return(0);
    }
    else
        return(1);
    
}
//verificando se o vetor e deecrescente
int funcdecrescente(int qtdnum, int vetor[])
{
    if (qtdnum > 0)
    {
        if (vetor[qtdnum] < vetor[qtdnum-1])
            return funcdecrescente(qtdnum-1, vetor);
        else
            return(0);
    }
    else
        return(1);
    
}
//verificando se o vetor possui seu conteudo espelhado
int funcpalindromo(int qtdnum, int vetor[], int cont)
{
    if (cont < ((qtdnum+1)/2))
    {
        if (vetor[cont] == vetor[qtdnum])
            return funcpalindromo(qtdnum-1, vetor, cont+1);
        else
            return(0);
    }
    else
        return(1);
    
}