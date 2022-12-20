#include<iostream>
#include<math.h>    		// serve per la radice quadrata
using namespace std;

int main() {
    int a, b;
    cout << "Inserire a: ";
    cin >> a;
    cout << "Inserire b!=0: ";
    cin >> b;
    int somma = a + b;
    int differenza = a - b;
    int prodotto = a * b;
    int rapporto = a / b;
    int resto = a % b;
    int radice_a = sqrt(a);

    cout << "somma \t differenza \t prodotto \t rapporto \t resto \t radice_a" << endl;
    cout << somma << "\t " << differenza << "\t\t " << prodotto << "\t\t " << rapporto 
            << "\t\t " << resto << "\t " << radice_a << "\n";

    return 0;
}
