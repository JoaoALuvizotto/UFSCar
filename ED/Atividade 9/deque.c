//Joao Augusto Luvizotto RA:823078
#include <stdlib.h>
#include "deque.h"
/*este deque foi implementado com a utilizacao de um vetor circular, pois o utilizando confere ao codigo eficiencia
e evita desperdicio de memoria*/
//inicializa o deque
Deque* inicializar(int maximo)
{
    Deque* novo = (Deque*) malloc(sizeof(Deque));
    novo->vetor = (int*) malloc(sizeof(int) * maximo);

    novo->max = maximo;
    novo->comeco = novo->final = -1;

    return novo;
}
//verifica se o deque esta vazio
int vazio(Deque* novo)
{
    if (novo->comeco == -1 && novo->final == -1)
        return 1;
    else
        return 0;   
}
//verifica se o deque esta cheio
int cheio(Deque* novo)
{
    if ((novo->final + 1) % novo->max == novo->comeco)
        return 1;
    else
        return 0;
}
//insere no inicio do deque
int InsereI(Deque* novo, int dado)
{
    if (cheio(novo)) // se esta cheia
        return 0;
    if (vazio(novo)) //se estiver vazia
    {
        novo->comeco = novo->final = 0;
        novo->vetor[novo->comeco] = dado;
    }
    else //se ela tiver algum item
    {
        novo->comeco = (novo->comeco + novo->max -1) % novo->max;
        novo->vetor[novo->comeco] = dado;
    }
    return 1;
}
//insere no final do deque
int InsereF(Deque* novo, int dado)
{
    if (cheio(novo))
        return 0;
    if (vazio(novo))
    {
        novo->comeco = novo->final = 0;
        novo->vetor[novo->final] = dado;
    }
    else
    {
        novo->final = (novo->final + 1) % novo->max;
        novo->vetor[novo->final] = dado;
    }
    return 1;
}
//remove do inicio do deque
int RemoveI(Deque* novo, int* dado)
{
    if(vazio(novo))
        return 0;

    *dado = novo->vetor[novo->comeco]; 
    
    if (novo->comeco == novo->final)
        novo->comeco = novo->final = -1;
    else
    //realiza esta conta para saber o novo comeco do vetor
        novo->comeco = (novo->comeco + 1) % novo->max;
    
    return 1;
}
//remove do final do deque
int RemoveF(Deque* novo, int* dado)
{
    if (vazio(novo))
        return 0;
    
    *dado = novo->vetor[novo->final];
    
    if (novo->comeco == novo->final)
        novo->comeco = novo->final = -1;
    else
    //realiza esta conta para saber o novo final do vetor
        novo->final = (novo->final + novo->max - 1) % novo->max;
    
    return 1;
}
//funcao que desaloca o deque
void CABOOOM(Deque* novo)
{
    free(novo->vetor);
    free(novo);
}