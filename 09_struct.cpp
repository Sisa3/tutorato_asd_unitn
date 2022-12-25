#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

void init_inputtxt(){
  	// Construisce un file di input con alcuni titoli, autori e prezzi di libri
    ofstream library_input("input.txt");
    library_input << "7" << endl 
    << "Algoritmi Analisi Geometria Algebra Fisica Galois Galois" << endl
    << "Montresor Pagani Sernesi Caranti Puppin DeGraaf DeGraaf" << endl
    << "15 18 44 20 19 12 13" << endl;
    library_input.close();
}

struct book {
	// Struttura dati in cui salveremo le info dei nostri libri
	// Ogni 'book' possiedera' le seguenti caratteristiche
    double cost;
    string title;
    string author;

	// Posso creare funzioni interne alla mia struttura
    book(string _title, string _author, double _cost){
        title = _title;
        author = _author;
        cost = _cost;
    }
    
    int cost_cent(){ return cost*100;}
};

void print(vector<book> library) {
	// Stampa le informazioni contenute in un vector di libri
    out << "----------------------------------------------------------------------" << endl;
    out << "La mia libreria:" << endl;
    for (int i = 0; i < library.size(); i++) {
        out << "Title: " << library[i].title << ",  \t author: " << library[i].author << ",\t cost: " << library[i].cost << endl;
    } 
    out << "----------------------------------------------------------------------" << endl;
}

void init_library(vector<book>& library, vector<string> titles, vector<double> costs, vector<string> authors, int N) {
	// A partire da dei vettori di titoli, costi e autori, crea i libri e li salva nel vettore library
    for (int i = 0; i < N; i++) {
        book b = book(titles[i], authors[i], costs[i]);
		/*
		*	 Ci sono due modi per creare i book:
		*	book b = book(titles[i], authors[i], costs[i]);
		* 	o equivalentemente
		*	 b.title = titles[i];
        *	b.cost = costs[i];
        *	b.author = authors[i];
		*/
        library.push_back(b);
    }
}

// Definisco delle operazioni di confronto tra libri

bool operator < (book b1, book b2) {
    return b1.cost < b2.cost;
}

bool operator == (book b1, book b2){
     return (b1.title == b2.title) && (b1.author==b2.author);
}



int main() {
    
    init_inputtxt();
    int N;
    vector<book> library;
    in >> N;
    
    vector<string> titles(N);
    vector<double> costs(N);
    vector<string> authors(N);

    for (int i = 0; i < N; i++) in >> titles[i];
    for (int i = 0; i < N; i++) in >> authors[i];
    for (int i = 0; i < N; i++) in >> costs[i];
    
    
    init_library(library, titles, costs, authors, N);
    
    print(library);

    out << "Gli ultimi due libri sono uguali? " << endl;
    out << "Risposta: " << (library[N - 1] == library[N - 2] ? "true" : "false") << endl; 
    out << "Infatti: (";
    out << library[N - 2].title << " " << library[N - 2].author << " " << library[N - 2].cost << ") VS (";
    out << library[N - 1].title << " " << library[N - 2].author <<" " << library[N - 1].cost << ")" << endl << endl;

    int i = 2, j = 3;
    out << "Quale libro costa di piu' tra " << library[i].title << " e " << library[j].title << "?" << endl;
    out << "Il prezzo di " << library[i].title << " e' " << (library[i] < library[j] ? "<" : ">=") << " di quello di " 
        << library[j].title << ", infatti " << library[i].cost << (library[i] < library[j] ? "<" : ">=") << library[j].cost << endl;

    sort(library.begin(), library.end());       // serve algorithm
    out << "\n---> Ora la libreria e' ordinata:\n";

    print(library);
    
    out<< "Convertiamo i prezzi dei libri in centesimi \n";
    for (book mybook : library){
        out<<mybook.cost<<" euro --> "<<mybook.cost_cent()<<" centesimi\n";
    }

    in.close();
    out.close();
    return 0;
}
