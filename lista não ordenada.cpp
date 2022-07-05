//Implementação de exemplo de lista não ordenada

#include<iostream>

using namespace std;

typedef struct Noh {
    int numero;
    Noh *proximo;
}Noh;

typedef struct Lista {
    Noh *inicio, *fim;
    int tamanho;
}Lista;

int menu()
{
    int opcao;
    
    do {
        cout<< endl<< "MENU DE OPCOES"<<endl;
        cout<<"1 - Inserir no inicio da lista"<<endl;
        cout<<"2 - Inserir no fim da lista"<<endl;
        cout<<"3 - Imprimir toda a lista"<<endl;
        cout<<"4 - Remover da lista"<<endl;
        cout<<"5- Esvaziar a lista"<<endl;
        cout<<"6 - Sair"<<endl<<endl;
        
        cout<< "Digite sua escolha: ";
        cin>> opcao;
        
        if(opcao < 1 || opcao > 6)
        cout<< "\tEscolha invalida!"<< endl;
    } while (opcao < 1 || opcao > 6);
    
    return opcao;
}

bool eVazia(Lista *lst)
{
    if (lst->inicio == NULL)
        return true;
    return false;
}

void inserirInicio(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo -> numero = numero;
    
    if(eVazia(lst))
    {
        novo->proximo == NULL;
        lst->inicio = novo;
        lst->fim = novo;
    }
    else
    {
        novo->proximo = lst->inicio;
        lst->inicio = novo;
    }
    lst->tamanho++;
}

void inserirFim(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo -> numero = numero;
    novo -> proximo = NULL; 
    
    if(eVazia(lst))
    {
        lst->inicio = novo;
        lst->fim = novo;
    }
    else
    {
        lst-> fim -> proximo = novo;
        lst-> fim = novo;
    }
    lst->tamanho++;
}

void imprime (Lista *lst)
{
    cout<< endl << " Tamanho da lista: " << lst->tamanho << endl;
    if (eVazia(lst))
        cout << "Lista vazia!" <<endl;
    else
    {
        Noh* pAux = lst->inicio;
        
        while (pAux != NULL)
        {
            cout<< pAux->numero<< " "; //impressão do nó atual
            pAux = pAux-> proximo;
        }
        cout<< endl << endl;
    }
}

int main ()
{   //Lista em maiusculo é a struct, em minusculo é a variavel, pode ter outro nome.
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
            cout<< "Digite o numero a ser inserido no inicio da lista: ";
            cin>> numero;
            inserirInicio(&lista, numero);
            break;
            
            case 2:
            cout<< "Digite o numero a ser inserido no fim da lista: ";
            cin>> numero;
            inserirFim(&lista, numero);
            break;
            
            case 3:
            cout<< " Imprimindo a lista ...";
            imprime(&lista);
            break;
            
            case 4:
            cout<< " Digite  o numero a ser removido da lista: ";
            break;
            
            case 5:
            cout<< " Esvaziando a lista ...";
            break;
            
            default:
            cout<< "Saindo..."<<endl;
            
        }
    }while (escolha != 6);
}

