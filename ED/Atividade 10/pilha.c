//Joao Augusto Luvizotto RA:823078
#include <stdlib.h>
#include "pilha.h"
//Inicializa a Pilha
Pilha* inicializar(int maximo)
{
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->vetor = (char*) malloc(sizeof(int) * maximo);

    pilha->max = maximo;
    pilha->topo = 0;

    return pilha;
}
//Verifica se a pilha esta vazia
int vazia(Pilha* pilha)
{
    if (pilha->topo == 0)
        return 1;
    
    return 0;
}
//Insere os caracteres na pilha
int inserir(Pilha* pilha, char dado)
{
    if (pilha->topo < pilha->max)
    {
        pilha->vetor[pilha->topo] = dado;
        pilha->topo++;
        return 1;
    }
    return 0;

}
//Verifica a situacao da pilha
int verificar(Pilha* pilha, char dados[])
{
    for (int i = 0; dados[i] != '\0'; i++)
    {
        //insere na pilha somente se for uma abertura de parenteses colchetes ou chaves
        if (dados[i] == '(' || dados[i] == '[' || dados[i] == '{')
        {
            inserir(pilha, dados[i]);
        }
        else
        {
            //caso a entrada nao seja uma abertura e a pilha estiver vazia isso ja significa que ela nao satisfaz o usuario
            if (vazia(pilha))
                return 0;
                //Caso a entrada nao seja uma abertuda e no topo da pilha nao feche o determinado par ela tambem nao satisfaz
            if ((pilha->vetor[pilha->topo-1] == '(' && dados[i] != ')') || (pilha->vetor[pilha->topo-1] == '{' && dados[i] != '}') 
                || (pilha->vetor[pilha->topo-1] == '[' && dados[i] != ']'))
            {
                return 0;
            }
            //caso o topo da pilha com a entrada seja um par valido, se e removida a parte aberta que estava no topo da pilha
            //fechando assim aquele par
            else
            {
                pilha->topo--;
            }
        }
    }
    //apos passar por tudo isso, se a pilha estiver vazia significa q ela satisfez as nossas condicoes
    if (vazia(pilha))
    {
        return 1;
    }
    //caso sobre algum par aberto significa que ela nao satisfez as condicoes e esta incompleta
    return 0;
}
//Remove um item da pilha
int remover(Pilha* pilha, char dado)
{
    if (!vazia(pilha))
    {
        pilha->topo--;
        return 1;
    }   

    return 0;
    
}
//desaloca a memoria da pilha
void destruir(Pilha *pilha)
{
    free(pilha->vetor);
    free(pilha);
}