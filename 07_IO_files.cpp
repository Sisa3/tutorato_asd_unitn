#include<fstream>
using namespace std;

int main(){
    ifstream in ("input.txt");						// file di input
	ofstream out ("inner_folder\\output.txt");		// file di output
    /* 	I file devono essere nella stessa cartella del programma
	* 	in alternativa, bisogna specificare il percorso:
    * 	o come "inner_folder\\output.txt"
    * 	o come "C:\\Users\\Utente\\Desktop\\inner_folder\\output.txt"
	*/

	int a;
	in >> a; 			
	// Leggo dall'inpupt in e inserisco ciò che leggo nella variabile a
	// Vengono considerati come separatori ' ', '\t', '\n'.
	// Attenzione al Tipo di variabile in cui viene salvato il valore: devono essere coerenti!

	out << "Ciao! La variabile a ora vale " << a;
	// Stampo nell'output out 
	
	in.close();
	out.close();
    
	return 0;
}
