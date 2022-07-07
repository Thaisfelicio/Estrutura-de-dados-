//Implementação do exemplo de lista simples ordenada

#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct Noh{
    int numero;
    Noh *proximo;
}Noh;

typedef struct Lista{
    Noh *inicio, *fim;
    int tamanho;
}Lista;

int menu()
{
    int opcao;
    
    do{
        
        cout<<endl << "MENU DE OPÇÕES" << endl;
        
        cout<< " 1 - Inserir na lista"<< endl;
        cout<< " 2 - Imprimir toda a lista"<<endl;
        cout<< " 3 - Remover da lista" <<endl;
        cout<< " 4 - Esvaziar a lista"<< endl;
        cout<< " 5 - Sair" <<endl <<endl;
        
        cout<< " Digite sua escolha: ";
        cin>> opcao;
        
        if ( opcao < 1 || opcao > 5)
            cout<< " \t Escolha inválida!" <<endl;
    }
    while ( opcao < 1 || opcao > 5);
    
    return opcao;
}

bool eVazia(Lista *lst)
{
    if(lst -> inicio == NULL)
        return true;
    return false;
}

void inserir(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo -> numero = numero;
    
    if (eVazia(lst))
    {
        novo -> proximo = NULL;
        lst -> inicio = novo;
        lst -> fim = novo;
    }
    else
    {
        Noh *pAnterior = NULL;
        Noh *pAux = lst -> inicio;
        
        while(pAux != NULL && novo -> numero < pAux -> numero) // se mudar o menor (<) muda de descrescente para crescente
        {
            pAnterior = pAux;
            pAux = pAux -> proximo;
        }
        if (pAnterior == NULL)
        {
            novo -> proximo = lst -> inicio;
            lst -> inicio = novo;
        }
        else if (pAux == NULL)
        {
            lst -> fim -> proximo = novo;
            lst -> fim = novo;
        }
        else 
        {
            pAnterior -> proximo = novo;
            novo -> proximo = pAux;
        }
    }
    lst -> tamanho++;
}

void imprime(Lista *lst)
{
    if (!eVazia(lst))
    {
        Noh* pAux = lst -> inicio;
        
        while (pAux != NULL)
        {
            cout<< pAux -> numero<<" "; //impressão do nó atual
            pAux = pAux -> proximo;
        }
        cout<< endl <<" Tamanho da lista: " << lst -> tamanho << endl;
        cout<< endl << endl;
    }
    else
    cout<< endl <<" Lista vazia ..." << endl << endl;
}

void esvaziar (Lista *lst)
{
    if (!eVazia(lst))
    {
        Noh *pAux;
    
        while(lst -> inicio != NULL)
        {
        pAux = lst -> inicio;
        lst -> inicio = lst -> inicio -> proximo;
        delete(pAux);
        }
    }
    else
        cout<< endl << " Lista vazia ..." << endl << endl;
}


//void remover (Lista *lst, int valor)

int main()
{
    Lista lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;
    
   int escolha, numero;
   
   do{
       escolha = menu();
       
       switch(escolha)
       {
           case 1:
            cout<< " Digite o numero a ser inserido na lista: ";
            cin>> numero;
            inserir(&lista, numero);
           break;
           
           case 2:
            cout<< " Imprimindo a lista ...";
            imprime(&lista);
           break;
           
           /*case 3:
            cout<< " Digite o numero a ser removido da Lista: ";
            cin>> numero;
            remover(&lista, numero);
           break;
           */
           case 4:
            cout<< " Esvaziando a lista ...";
            esvaziar(&lista);
           break;
           
           default:
            cout<< " Saindo ..." << endl;
       }
   }while(escolha != 5);
}
