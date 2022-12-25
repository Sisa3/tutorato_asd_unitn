#include <iostream> 
using namespace std;

// Possiamo provare a costruire manualmente una lista

struct node {
    int value;
    node* next; 
};

bool isEmpty (node* lista) {
  return (lista == NULL);
}

void init(node* lista) {
  lista = NULL;
}

void print_lista (node* lista) {
  node * first = lista;
  while (first!=NULL) {
    cout << " --> " << first->value ;
    first = first -> next;
  }
  cout << endl;
}

int top(node* lista) {
    int n;
    if (isEmpty(lista)){
        n = -1;
    } else {
        n = lista -> value;
  }
  return n;
}

void push_front (int n, node* &lista) {
    node * np = new node;
    np -> value = n;
    np -> next = lista;
    lista = np;  
}

int pop_front (node* &lista) {
    int value = lista->value;
    lista = lista->next;  
    return value;
}


int main () 
{
    node* lista = NULL;
    node * np = new node;
    np -> value = 5;
    np -> next = NULL;
    lista = np;
    
    node * np2 = new node;
    np2 -> value = 7;
    np2 -> next = np;
    lista = np2;
    

    print_lista(lista);

    cout << "L'elemento in cima e': " << top(lista) << endl;

    cout << "Aggiungi un nuovo elemento: " << endl;
    int n;
    cin >> n;

    push_front(n, lista);
    print_lista(lista);
    pop_front(lista);
    print_lista(lista);

    return 0;
}

