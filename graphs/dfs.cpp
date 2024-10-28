#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void depthFirstSearch(vector<vector<int>> & graph, int start){
    stack<int> s;

    cout<< start << "  ";

    for(int i=0; i<graph[start-1].size(); i++){
        s.push(graph[start-1][i]);
    }

    while(!s.empty()){
        int curr = s.top();
        s.pop();
        for(int i=0; i<graph[curr-1].size(); i++){
            s.push(graph[curr-1][i]);
        }

        cout<< curr << "  ";
    }
    cout << "\n";
}


int main(){

    // Adjacency List for our graph. Node 1 connections is at index 0. Total of 6 nodes.
    vector<vector<int>> graph = {{2,3}, {4}, {5}, {6}, {}, {}};


    depthFirstSearch(graph, 1);
    

    return 0;
}