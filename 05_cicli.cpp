#include<iostream>
using namespace std;

int main(){

	*/
	*	Ciclo WHILE:
	*	esegui una certa azione finche' la condizione rimane vera
	*/
	int a = 10;
    cout << "Inizio il while con a = " << a << endl;
	while (a > 0){
		cout << " a = " << a << endl;
		a--;
	}
    cout << "Ora a = " << a << endl;

	*/
	*	Ciclo FOR:
	*	esegui una certa azione,, iterando un contatore in un certo range
	*/
    int i;
    cout << "Inizio ciclo for: " << endl;
	for(int i = 0; i < 10; i++){
		cout << " i = " << i << endl;
	}
    cout << "Ora i = " << i << endl;

    
	return 0;
}
