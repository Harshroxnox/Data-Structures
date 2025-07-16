#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    // Binary Search
    cout << "Search for 5: " << binary_search(v.begin(), v.end(), 5) << endl;
    cout << *lower_bound(v.begin(), v.end(), 2) << endl;
    // lower_bound gives itr of next bigger element than key present in array 
    cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    cout << *upper_bound(v.begin(), v.end(), 5)  << endl;

    int a =3;
    int b = 5;

    cout << "max -> " << max(a,b) << endl;
    cout << "min -> " << min(a,b) << endl;
    swap(a, b);

    cout << "a -> " << a << endl;

    string s = "car";
    reverse(s.begin(), s.end());
    cout << s << endl;

    rotate(v.begin(), v.begin()+1, v.end());
    cout << "After rotate: " << endl;
    for(int i: v){
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());   
    cout << "After sort: " << endl;
    for(int i: v){
        cout << i << " ";
    }
    cout << endl;

}