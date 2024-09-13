#include <stdio.h>
#include "pilha.h"

#define TAM 100001
int main()
{
    int qtdrep;
    char caracteres[TAM];
    Pilha* pilha;

    scanf("%d\n", &qtdrep);
//Recebe as cadeias de caracteres
    for (int i = 0; i < qtdrep; i++)
    {
        scanf("%s", caracteres);
        pilha = inicializar(TAM);

        if (verificar(pilha, caracteres))
        {
            printf("S\n");
        }
        else
            printf("N\n");
        
        destruir(pilha);
        
    }
    
    



}