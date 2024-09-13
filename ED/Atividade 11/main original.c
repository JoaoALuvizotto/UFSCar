#include <stdio.h>
#include "fila.h"

void inverter(Fila* fila);
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
    
    inverter(fila);
    No *imprimir = fila->primeiro;
    while (imprimir != NULL)
    {
        printf("%d", imprimir->dado);
        if (imprimir->link != NULL)
            printf(" ");

        imprimir = imprimir->link;
    }
    printf("\n");
    destruir(fila);
    return 0;
}

void inverter(Fila* fila)
{
    int removido;
    if (vazia(fila))
    {
        return;
    }
    else
    {
        remover(fila, &removido);
        inverter(fila);
        inserir(fila, removido);
    }
    
    
}