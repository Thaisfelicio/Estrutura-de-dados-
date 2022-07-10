#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int X[10], np, i, inicio, fim, meio, achou;
    //clrscr();
    //carregando os números no vetor - ORDENADOS
        for (i = 0; i <= 9; i++)
        {
            cout<<"Digite o " << i + 1 << "º número: ";
            cin>> X[i];
        }
    //digitando o número a ser buscado no vetor
    
    cout<<"Digite o número a ser buscado no vetor: ";
    cin>> np;
    
    //buscando o número digitado no vetor
    achou = 0;
    inicio = 0;
    fim = 9;
    meio = (inicio + fim) / 2;
    
    while (inicio <= fim && achou == 0)
        {
            if (X[meio] == np)
                achou = 1;
            else
            {
                if (np < X[meio])
                  fim = meio - 1;
                else
                  inicio = meio + 1;
                  meio = (inicio + fim) / 2;
            }
        }
        if (achou == 0)
            cout<<"Número não encontrado no vetor";
        else
            cout<<"Número encontrado na posição " << meio + 1;
            
        getch();
}
