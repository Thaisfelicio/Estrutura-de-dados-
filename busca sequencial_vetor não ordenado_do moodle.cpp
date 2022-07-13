#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int X[10], n, i, achou;
    //clrscr();
    //carregando os números no vetor, vetor com números NÃO ORDENADOS
    for (i = 0; i<= 9; i++)
    {
        cout<<"Digite o " << i+1 << "º número: ";
        cin>> X[i];
    }
    //digitando o número a ser buscado no vetor
    cout<<"Digite o número a ser buscado no vetor: ";
    cin>>n;
    //buscando o número digitado no vetor
    achou = 0;
    i = 0;
    
    while (i <= 9 && achou == 0)
        {
            if (X[i] == n)
                achou = 1;
            else
                i++;
        }
        
        if (achou == 0)
            cout<<"Número não encontrado no vetor";
        else
            cout<<"Número encontrado na posição " << i + 1;
        getch();
}
