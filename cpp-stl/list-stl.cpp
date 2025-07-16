#include <iostream>
#include <list>
// STL list is doubly linked list implementation
using namespace std;

int main(){

    list<int> l;

    l.push_back(1);
    l.push_front(2);

    for(int i:l){
        cout << i << " ";
    }
    cout << endl;

    l.erase(l.begin());
    cout << "After erase " << endl;
    for(int i:l){
        cout << i << " ";
    }
    cout << endl;

    cout << "Size of list: " << l.size() << endl;

    // list l copied into new list n
    list<int> n(l); 
    // list with 5 elements that are all 100 
    list<int> a(5, 100);
    
    cout << "List n : " << endl;
    for(int i:n){
        cout << i << " ";
    }
    cout << endl;

    cout << "List a : " << endl;
    for(int i:a){
        cout << i << " ";
    }
    cout << endl;
}