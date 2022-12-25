
#include <iostream>
#include <vector>       // per utilizzare i vector
#include <stack>        // per utilizzare gli stack
#include <queue>        // per utilizzare le code
#include <algorithm>    // per utilizzare altre funzioni
using namespace std;

bool abs_compare(int a, int b){
	// nuova funzione che permette di confrontare tra di loro due interi a, b
    return (abs(a) < abs(b));
}

int main() { 
    // VETTORI

    // Dichiaro un array di nome v, e specifico che conterra' elementi `int`
    vector<int> v; 

    //  La funzione push_back inserisce un elemento in fondo all'array (incrementandone la dimensione)
    v.push_back(25); 
    v.push_back(20);
    v.push_back(-30);
    for(int i = 0; i < v.size(); i++){  
        // La funzione size() ritorna il numero di elementi all'interno dell'array
		// Per accedere all' i-esimo elemento, uso v[i]
        cout << v[i] << endl;   		
    } cout << "------------------------" << endl;
	
	/*
	*	Se voglio creare un vector con N elementi gia' inzializzati al valore intero x (definito precedentemente)
	*	vector<int> vec(N, x);
	*/

    // MATRICI

	// Le matrici possono essere viste come vector che contengono altri vector
    vector<vector<int>> matrix;    
    for(int i = 0; i < 5; i++){
        vector<int> tmp(5); 		
		// Voglio riempire le righe con dei vettori di 5 elementi
		// Nella posizione M[i][j] inserisco la somma i+j
        for(int j = 0; j < 5; j++){
          tmp[j] = i + j; 
        }
        matrix.push_back(tmp);
    }
	
	/* 
	*	Se conosco gia' la dimensione della matrice che devo creare (R x C)
	*	posso crearla tramite comando
	*	vector<vector<int>> matrix(R, vector<int>(C));
	*	Se voglio creare una matrice di R righe, ciascuna formata da colonne di C elementi pari a x (definito precedentemente) uso
	*	vector<vector<int>> matrix(R, vector<int>(C, x));
	*/

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){ 		// questo ciclo stampa tutta la riga i-esima
            cout << matrix[i][j] << " ";
        }
        cout << endl; 						// manda a capo dopo aver stampato la riga
    } cout << "------------------------" << endl;

    // STACK

	// struttura LIFO
    stack<int> s;
    s.push(5); 				// La funzione push() inserisce un elemento in cima allo stack
    s.push(6); 
    s.push(7); 
    cout << "Lo stack ha dimensione " << s.size() << endl;

    while(!s.empty()){ 		// La funzione empty() restituisce true se lo stack è vuoto, false altrimenti
        cout << "L'elemento in cima allo stack e': " << s.top() << endl; 
        s.pop(); 			// La funzione pop() rimuove l'elemento in cima allo stack
        cout << "Lo stack ora ha dimensione " << s.size() << endl;
    } cout << "------------------------" << endl;

    // QUEUE

	// struttura FIFO
    queue<int> q;
    q.push(8); 				// La funzione push() inserisce un elemento in fondo alla coda
    q.push(9); 
    q.push(10); 
    q.push(11); 
    cout << "La coda ha dimensione " << q.size() << endl;
    
    while(!q.empty()){ 
        cout << "L'elemento in cima alla coda e': " << q.front() << endl; 
        q.pop();
        cout << "La coda ora ha dimensione " << q.size() << endl;
    } cout << "------------------------" << endl;

    // altre funzioni utili

    // sort
    sort(v.begin(),v.end());
    for (int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << endl;
    
    // reverse
    reverse(v.begin(),v.end());
    for (int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << endl;

    // min
    vector<int>::iterator min_pos=min_element(v.begin(), v.end());
    cout << "Il minimo e' " << *min_pos << " in posizione " << distance(v.begin(),min_pos) << endl;
    
    // max
    vector<int>::iterator max_pos=max_element(v.begin(), v.end(), abs_compare);
    cout << "Il massimo in valore assoluto e' " << *max_pos << " in posizione " << distance(v.begin(),max_pos) << endl;

    // binary search
    vector<int> w;
    for (int i=-4; i<5; i++) w.push_back(i);
    cout << "il vettore w = [";
    for (int i=0; i<w.size(); i++) cout << w[i] << " "; cout << "]" << endl;
    int elem = 3;
    if (binary_search(w.begin(), w.end(), elem))    cout << "Ho trovato " << elem << endl;
    else cout << "Non ho trovato " << elem << endl;

    // copy
    vector<int> u1 = v;
    vector<int> u2(v.size());
    copy(v.begin(), v.end(), u2.begin());
}
