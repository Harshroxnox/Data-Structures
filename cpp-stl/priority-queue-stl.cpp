#include <iostream>
#include <queue>

using namespace std;
// STL priority queue is heap implementation by default it's max heap 
int main(){
    // max heap
    priority_queue<int> maxi;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    cout << "maxi size -> " << maxi.size() << endl;
    int n = maxi.size();
    for(int i=0; i<n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    //-----------------Doing the same thing with min heap we should just get reverse order---------------

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    cout << "mini size -> " << mini.size() << endl;
    n = mini.size();
    for(int i=0; i<n; i++){
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "Is mini empty --> " << mini.empty() << endl;
    return 0;
}