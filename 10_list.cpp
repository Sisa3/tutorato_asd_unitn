#include <iostream> 
#include <list>
#include <vector> 
#include <string>
using namespace std;

int main () 
{
    // Lista: doubly-linked list

    list<int> emptylist;                // Crea una lista vuota
    list<int> basic(4, 101);            // 4 interi con valore 101. l={101,101,101,101}
    list<int> copylist(basic.begin(), basic.end()); // Copia di basic
    list<int> copylist2(basic);          // Un'altra copia di basic
    int myints[]={12, 34, 56, 78, 90};
    list<int> fromarray (myints, myints + (sizeof(myints) / sizeof(int)));
    
    vector<string> listnames = {"emptylist", "basic", "copylist", "copylist2", "fromarray"};
    vector<list<int>> listref = {emptylist, basic, copylist, copylist2, fromarray};

    // Ciclo apparentemente complesso che serve solo per stampare gli elementi nelle liste
    for(int i=0;i<listref.size();i++){
        cout << "The list '" << listnames[i] << "' contains: ";
        for(list<int>::iterator it = listref[i].begin(); it != listref[i].end(); it++){
            cout << *it << ' ';
        } cout << "." << endl;
    }
    
    cout << fromarray.empty() << " " << fromarray.size() << " "
         << fromarray.front() << " " << fromarray.back() << " "<< endl;
    fromarray.push_front(42);
    fromarray.push_back(42);
    fromarray.insert(fromarray.begin(),123); 
    cout << "The list 'fromarray' contains: ";
    for(list<int>::iterator it = fromarray.begin(); it != fromarray.end(); it++)
            cout << *it << ' ';
        
    fromarray.erase(--fromarray.end()); 
    fromarray.pop_back();
    fromarray.pop_front();
    cout << "\nThe list 'fromarray' contains: ";
    for(list<int>::iterator it = fromarray.begin(); it != fromarray.end(); it++)
            cout << *it << ' ';
 
    return 0;
}

