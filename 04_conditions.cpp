#include<iostream>
using namespace std;

int main() {
  
    int a, b;
    cout << "Inserisci due interi a e b:" << endl;
    cin >> a >> b;
    
    /*
    *   IF-ELSE:
    *   if (condizione) { 
    *       // esegui questo se la condizione e' valida
    *   } else {
    *       // esegui questo se la condizione non e' valida
    *   }
    */

    if (a > b){
        cout << "a e' maggiore di b" << endl;
    } else {
        cout << "a e' minore o uguale a b" << endl;
    }

    /*
    *   SWITCH:
    *   Funziona come una catena di if-else:
    *   switch (check) {					// controllo il valore di check
	*     	case (valore_1):				// if (check == valore_1) ...
	*			// sei nel caso 1
	* 			break;						// esci dallo switch
	* 		case (valore_2):
	*			// sei nel caso 2
	* 			break;
	* 		case (valore_3):
	*			// sei nel caso 3
	* 			break;
	*		default:
	*			// quando non rientri negli altri casi, puoi inserire un caso di default (opzionale)
	*	}
	*
	*/

    char operazione;
    cout << "Inserisci un'operazione tra le quattro seguenti: + - * /
    cin >> operazione;
    switch (operazione) { 
        case ('+'):                       	// con char e' necessario usare ', mentre con le stringhe si usa "
            cout << "a + b = " << a + b << endl;
            break; 
        case ('-'):
            cout << "a - b = " << a - b << endl;
            break;  
        case ('*'):
            cout << "a * b = " << a * b << endl;
            break;  
        case ('/'):
            if(b != 0) {
                cout << "a / b = " << a / b << endl;
            } else {
                cout << "Non e' possibile dividere per 0.\n";
            }
            break;  
        default:    // opzionale 
            cout << "Input non valido \n";
        } 



    return 0;
}
