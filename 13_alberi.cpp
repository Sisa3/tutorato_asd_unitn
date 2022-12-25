#include <iostream> 
#include <fstream> 
#include <vector>
using namespace std;

  /*    
  *   Costruiamo un albero binario di ricerca:
  *   ogni nodo dell'albero ha al massimo 2 figli (left, right)
  *   e left.value < node.value < rigth.value.
  *   Il file di input contiene 
  *   > N = numero nodi [da 1 a N]
  *   e poi N righe con
  *   > nodo.value left.value right.value
  *   il simbolo "0" indica che non ha figlio sx/dx 
  */

void init_input(){
    ofstream alberi_input("13_input_alberi.txt");
    alberi_input << "20 \n" <<
                    "1 0 0\n" <<
                    "2 1 3\n" <<
                    "3 0 4\n" <<
                    "4 0 0\n" <<
                    "5 2 7\n" <<
                    "6 0 0\n" <<
                    "7 6 9\n" <<
                    "8 0 0\n" <<
                    "9 8 0\n" <<
                    "10 5 15\n" <<
                    "11 0 0 \n" <<
                    "12 11 14\n" <<
                    "13 0 0\n" <<
                    "14 13 0\n" <<
                    "15 12 18\n" <<
                    "16 0 17\n" <<
                    "17 0 0 \n" <<
                    "18 16 19\n" <<
                    "19 0 20\n" <<
                    "20 0 0\n";
    alberi_input.close();
}

struct my_tree {
    int value;
    my_tree* left;
    my_tree* right;

    my_tree(int n, my_tree* _left = nullptr, my_tree* _right = nullptr) {
        value = n;
        left = _left;
        right = _right;
    }
    void set_left(my_tree* _left){
        left = _left;
    }
    void set_right(my_tree* _right){
        right = _right;
    }
    int get_value(){
        return value;
    }

    my_tree* get_left(){
        if (left == nullptr) return NULL;
        return left;
    }
    my_tree* get_right(){
        if (right == nullptr) return NULL;
        return right;
    }

    void print(){
        cout << value;
        if(left != nullptr){
            cout << " -> "; left->print();
        }
        if(right != nullptr){
            cout << " -> "; right->print();
        }

    }
};

void find_path_1(my_tree& radice, int dest, vector<int>& path){
    // Nota: se esiste, il percorso da radice a dest e' unico
    // Provo a passare attraverso il nodo radice
    path.push_back(radice.get_value());
    if(radice.get_value() == dest){
        cout << "Path = ";
        for(int i = 0; i < path.size(); i++) cout << path[i] << " ";
        cout << endl;
    }
    if(radice.get_left() != NULL){
        find_path_1(*radice.get_left(), dest, path);
    }
    if(radice.get_right() != NULL){
        find_path_1(*radice.get_right(), dest, path);
    }
    path.pop_back();
    return;
}

void find_path_2(my_tree& radice, int dest, vector<int>& path){
    if(radice.get_value() == dest){
        path.push_back(radice.get_value());
        cout << "Path = ";
        for(int i = 0; i < path.size(); i++) cout << path[i]<<" ";
        cout << endl;
        return;
    }
    if(radice.get_value() > dest && radice.get_left() != NULL){
        // go to left
        path.push_back(radice.get_value());
        find_path_2(*radice.get_left(), dest, path);

    }
    if(radice.get_value()<dest && radice.get_right() != NULL){
        // go to right
        path.push_back(radice.get_value());
        find_path_2(*radice.get_right(), dest, path);

    }
    return;
}

int main () {
    
    init_input();
    ifstream in("13_input_alberi.txt");
    int N;
    in >> N;
    // Creiamo un vector con tutti i nodi, inizialmente senza figli,
    // che poi collegheremo in modo opportuno
    vector<my_tree> foresta;
    for(int i = 1; i <= N; i++){
        foresta.push_back(my_tree(i));
    }
    int value, left, right;
    for (int i = 0; i < N; i++){
        in >> value >> left >> right;
        if(left != 0) foresta[i].set_left(&foresta[left-1]);
        if(right != 0) foresta[i].set_right(&foresta[right-1]);
    }

    int radice = 10;
    cout << "Il mio albero (in dfs):\n\t";
    foresta[radice-1].print();

    int dest = 25;
    vector<int> path;
    cout << "\nCerchiamo il percorso dalla radice all'elemento " << dest << endl;
    find_path_1(foresta[radice-1], dest, path);
    cout << "\nCerchiamo il percorso dalla radice all'elemento " << dest << " [versione 2]" << endl;
    find_path_2(foresta[radice-1], dest, path);
    
    return 0;
}
