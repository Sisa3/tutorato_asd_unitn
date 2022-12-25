#include <iostream>
using namespace std;

/*
*	Una funzione e' una sequenza di step 
*	eseguiti a partire da un input
*	che restituiscono un output.
*	L'input e output possono anche essere vuoti.
*/

/* 	La firma di una funzione e' formata da: 
*   tipo_ritorno nome_funzione(argomento_1, argomento_2, ...) 
*		{... esecuzione step funzione ...}
* 	esempio:
*   	float sommma(int a, int b)
* 	-float e' il tipo di ritorno
*	-somma è il nome della funzione
* 	-int a, int b sono gli argomenti della funzione
*	 Gli argomenti della funzione possono essere passati in vari modi:
*	 ogni modalita' ha determinati svantaggi e vantaggi.
*	 La scelta della modalia' dipende dallo use-case.
*/

void passaggio_per_valore(int x){
    /* Quando un parametro viene passato per valore (o copia) a una funzione, 
    *  viene creata una copia di quell'oggetto che verrà utilizzata all'interno 
    *  della funzione senza influenzare l'oggetto originale.
    */
    x = 222;
    cout << "All'interno della funzione x vale: " << x << endl;
}

void passaggio_per_riferimento(int &x){
    /* Quando un parametro viene passato per riferimento a una funzione, viene 
    *  semplicemente passato un puntatore alla struttura dati. Qualsiasi 
    *  cambiamento all'oggetto all'interno della funzione chiamata, si rifletterà
    *  nell'oggetto originale. 
    */
    x = 33;
    cout << "All'interno della funzione x vale: " << x << endl;
}

void passaggio_per_puntatore(int * x){
    *x = 42;
    cout << "All'interno della funzione il puntatore (x) vale: " << x << " mentre il valore dell'elemento puntato e' " << *x << endl;
}

int main() { 
    // la prima funzione che viene eseguita è il main
    int val = 10;
    passaggio_per_valore(val);
    cout << "Dopo la chiamata per valore, non e' cambiato il valore originale di val: " << val << endl << endl;

    passaggio_per_riferimento(val);
    cout << "Dopo la chiamata per riferimento, e' cambiato il valore originale di val: " << val << endl << endl;
    
    passaggio_per_puntatore(&val);
    cout << "Dopo la chiamata con puntatore, e' cambiato il valore originale di val: " << val << endl << endl;

}
