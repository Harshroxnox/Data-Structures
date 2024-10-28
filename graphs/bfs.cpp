#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void breadthFirstSearch(vector<vector<int>> & graph, int start){
    queue<int> q;

    cout << start << "  ";
    for(int i=0; i<graph[start-1].size(); i++){
        q.push(graph[start-1][i]);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << "  ";

        for(int i=0; i<graph[curr-1].size(); i++){
            q.push(graph[curr-1][i]);
        }
    }
    cout << "\n";
}


int main(){

    // Adjacency List for our graph. Node 1 connections is at index 0. Total of 6 nodes.
    vector<vector<int>> graph = {{2,3}, {4}, {5}, {6}, {}, {}};

    breadthFirstSearch(graph, 1);

    return 0;
}