//Joao Augusto Luvizotto RA:823078
#include <stdio.h>

void tracos(int tracinhos);
void numregua(int tregua, int tracinhos);
int main()
{
    int tregua, ttracos;

    scanf("%d", &tregua);
    scanf("%d", &ttracos);

    numregua(tregua, ttracos);
    return 0;
}
//faz os riscos maiores da regua ex: ----- 0
void numregua(int tregua, int tracinhos)
{
    for (int i = 0; i <= tregua; i++)
    {
        for (int j = 0; j < tracinhos; j++)
            printf("-");
        
        printf(" %d\n", i);
        
        if (i != tregua)
            tracos(tracinhos);
    }
         
}
//faz todos os tracos menores da regua
void tracos(int tracinhos)
{
    if (tracinhos <= 1)
        return;
    else
    {   
        tracos(tracinhos-1);
        
        for (int i = 1; i < tracinhos; i++)
            printf("-");
        
        printf("\n");
        
        tracos(tracinhos-1);
    }
    

}