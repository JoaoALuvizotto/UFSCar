#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 500

int funcmaior(int qtdnum, int vetor[]);
int funcmenor(int qtdnum, int vetor[]);
int funcsoma(int qtdnum, int vetor[], int soma);
int funccrescente(int qtdnum, int vetor[]);
int funcdecrescente(int qtdnum, int vetor[]);
int funcpalindromo(int qtdnum, int vetor[], int cont);

int main()
{
    int qtdnum, num[NUM_MAX], maior, menor, soma = 0, crescente = 0, decrescente = 0, espelhada = 0;

    scanf("%d", &qtdnum);
    
    for (int i = 0; i < qtdnum; i++)
    {
        scanf("%d", &num[i]);
    }

    maior = funcmaior(qtdnum, num);
    menor = funcmenor(qtdnum, num);
    soma = funcsoma(qtdnum, num, soma);
    crescente = funccrescente(qtdnum-1, num);
    decrescente = funcdecrescente(qtdnum-1, num);
    espelhada = funcpalindromo(qtdnum-1, num, 0);
    
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
int funcmaior(int qtdnum, int vetor[])
{
    if (qtdnum == 1)
    {
        return vetor[0];
    }
    else
    {
        int m = funcmaior(qtdnum-1, vetor);

        if (m > vetor[qtdnum-1])
            return m;
        else
            return vetor[qtdnum-1];
        
    }
        
    
}
int funcmenor(int qtdnum, int vetor[])
{
    if (qtdnum == 1)
    {
        return vetor[0];
    }
    else
    {
        int menor = funcmenor(qtdnum-1, vetor);

        if (menor > vetor[qtdnum-1])
            return vetor[qtdnum-1];
        else
            return menor;        
    }
    
    
}
int funcsoma(int qtdnum, int vetor[], int soma)
{
    if (qtdnum < 0)
    {
        return 0;
    }
    else
    {       
        soma += funcsoma(qtdnum-1, vetor, soma);
        soma += vetor[qtdnum-1];
        return soma;
    }
    
}
int funccrescente(int qtdnum, int vetor[])
{
    if (qtdnum < 0)
    {
        return 0;
    }
    else
    {
        int crescente = funccrescente(qtdnum-1, vetor);
        if (vetor[qtdnum] > vetor[qtdnum-1])
            return(1);
        else
            return(0);
        
    }  
}
int funcdecrescente(int qtdnum, int vetor[])
{
    if (qtdnum < 0)
    {
        return 0;
    }
    else
    {
        int crescente = funcdecrescente(qtdnum-1, vetor);
        if (vetor[qtdnum] < vetor[qtdnum-1])
            return(1);
        else
            return(0);
        
    }
    
}
int funcpalindromo(int qtdnum, int vetor[], int cont)
{
    if (cont >= (qtdnum+1)/2)
        return 0;
    else
    {
        int palindromo = funcpalindromo(qtdnum-1, vetor, cont+1);
        if (vetor[qtdnum-1] == vetor[cont+1])
            return 1;
        else
            return 0;   
    }
  
  
}