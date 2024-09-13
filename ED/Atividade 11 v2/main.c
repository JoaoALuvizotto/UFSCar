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
    /*No *imprimir = fila->primeiro;
    while (imprimir != NULL)
    {
        printf("%d", imprimir->dado);
        if (imprimir->link != NULL)
            printf(" ");

        imprimir = imprimir->link;
    }
    printf("\n");*/
    destruir(fila);
    return 0;
}

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