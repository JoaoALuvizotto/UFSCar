//João Augusto Luvizotto RA:823078
#include <stdio.h>
#include "fila.h"

void inverter(Fila* fila, int print);
int main()
{
    int qtdnum, numero;
    Fila* fila = inicializar();

    scanf("%d", &qtdnum);

    for (int i = 0; i < qtdnum; i++)
    {
        scanf("%d", &numero);
        inserir(fila, numero);
    }
    
    inverter(fila, 0);
    destruir(fila);
    return 0;
}
//Inverte e ao mesmo tempo printa o item que foi inserido novamente
void inverter(Fila* fila, int print)
{
    int removido;
    if (vazia(fila))
    {
        return;
    }
    else
    {
        remover(fila, &removido);
        inverter(fila, 1);
        printf("%d", removido);
        if (print)
            printf(" ");  
        else
            printf("\n");
        inserir(fila, removido);
    }
    
    
}