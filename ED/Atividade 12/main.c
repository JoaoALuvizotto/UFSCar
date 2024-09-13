#include <stdio.h>
#include <string.h>
#include "deque.h"


int main()
{
    int numcomand, numelementos, dado;
    char comando[8];
    Deque *deque;

    scanf("%d %d", &numcomand, &numelementos);

    deque = inicializar(numelementos);

    for (int i = 0; i < numcomand; i++)
    {
        scanf("%s", comando);

        if (strcmp(comando, "insereI")  == 0)
        {   
            scanf("%d", &dado);
            if(!InsereI(deque, dado))
                printf("cheia\n"); 
        }
        else if(strcmp(comando, "insereF") == 0)
        {
            scanf("%d", &dado);
            if(!InsereF(deque, dado))
                printf("cheia\n");
        }
        else if (strcmp(comando, "removeI") == 0)
        {
            if(!RemoveI(deque, &dado))
                    printf("vazia\n");
                else
                    printf("%d\n", dado);
        }
        else if (strcmp(comando, "removeF") == 0)
        {
             if(!RemoveF(deque, &dado))
                    printf("vazia\n");
                else
                    printf("%d\n", dado);
        }
        
    }
    CABOOOM(deque);
    return 0;
}

