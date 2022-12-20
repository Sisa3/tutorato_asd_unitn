#include<iostream>
using namespace std;

int main() {
	/*
	*	Esistono diversi tipi di variabili:
	*	i principali sono int, double, float, char, string
	*/
    int a = 5;
    double b = 3.5;
    float c = 7.2;
    char d = 'a';
    string e = "Buongiorno!\n";
    
	/*
	*	I commandi cin e cout permettono di leggere un input e stampare un output
	*/
	
    cout << a << " ciao \t a te, " << b << ", \n" << c << ", " << d << " " << e << endl;

    int a, b;
    cout << "Inserire un intero a: ";
    cin >> a;
    cout << "\nInserire un intero b: ";
    cin >> b;
    
    cout << "Hai inserito a = " << a << " e b = "<< b << endl;

	
    return 0;
}
