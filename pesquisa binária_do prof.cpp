#include <iostream>
#include <conio.h>

int pesquisa (int *vetor, int inicio, int fim, int busca)
{
    int meio = (inicio + fim)/2;
    
    if (inicio > fim)
        return -1;
        
    if (vetor[meio] == busca)
        return meio;
        
    if (vetor[meio] < busca)
        return pesquisa(vetor, meio + 1, fim, busca);
    else 
        return pesquisa(vetor, inicio, meio - 1, busca);
    
}

int main ()
{
   
    int pesquisa();
}

