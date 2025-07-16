#include <iostream>
#include <set>

using namespace std;
// STL Set implementation is binary search tree 
// no modification only insert or remove elements
// duplicate elements are not present in set 
// Removed elements come in order if we don't want this then we can use unordered set(faster)

int main(){
    set<int> s;

    // insert, search and delete in BST is O(logn)
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(1);
    s.insert(3);
    s.insert(0);

    for(int i:s){
        cout << i << " ";
    }
    cout << endl;

    // iterator is at first element 
    set<int>::iterator it = s.begin();
    // now it is at second element i.e 1 
    it++;

    // removing 1 
    s.erase(it);

    for(int i:s){
        cout << i << " ";
    }
    cout << endl;

    cout << "Is 5 present : " << s.count(5) << endl;

    // find will return that element's iterator
    set<int>::iterator itr = s.find(5);
    cout << "Value present at itr : " << *itr << endl;

    // Printing values from 5 i.e itr
    for(auto it = itr; it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}