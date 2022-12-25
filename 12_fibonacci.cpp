#include<iostream>
#include<vector>
using namespace std;

int stampaNterms(int n, bool print_prev){
    // 	print_prev serve per stampare in modo adeguato:
	//	altrimenti a ogni chiamata stamperebbe tutto
	//	Per esempio, con n=4 sarebbe 0101012: un sacco di ripetizioni inutili
    if (n==1){
        if (print_prev) cout<<"0 "; 
        return 0;
    } else if (n==2){
        stampaNterms(n-1, print_prev);
        if (print_prev) cout<<"1 ";
        return 1;
    } else {
        int res=stampaNterms(n-1, print_prev) + stampaNterms(n-2, false);
        if (print_prev) cout << res << " ";
        return res;
    }
}


int main() {
	
    // Stampiamo i primi #terms elementi della sequenza di Fibonacci 
	// ci sono vari modi per creare questa funzione
	
    int terms;
    cout << "Inserisci il numero di termini:\n";
    cin >> terms;

    cout << "Il " << terms << "^ termine della sequenza e' " << stampaNterms(terms, false) << endl;
    
    // Versione brutale ricorsiva
    cout << "\nVersione 1:\n";
    stampaNterms(terms, true);

    // Versione iterativa
    cout << "\nVersione 2:\n";
    vector<int> fibvec(terms);
    fibvec[0] = 0; fibvec[1] = 1;
    for (int i = 2; i < terms; i++){
        fibvec[i] = fibvec[i-1] + fibvec[i-2];
    }
    for(int i = 0; i < terms; i++){
        cout << fibvec[i] << " ";
    }

    // versione O(1) spazio e O(terms) tempo
    cout<<"\nVersione 3:\n";
    int a = 0, b = 1, c;
    if (terms == 1) cout << a;
    else if(terms==2) cout << a << " " << b;
    else {
        cout << a << " " << b << " ";
        for (int i = 0; i < terms-2; i++){
            cout << a + b << " ";
            b = b + a; a = b - a;
            // 	Modo alternativo, piu' compatto:
			//	c = a + b; a = b; b = c;
        }
    }
    // esempio: terms=45 mostra la lentezza del primo metodo


}
