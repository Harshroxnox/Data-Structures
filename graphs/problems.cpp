#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Implementation of path finding algorithm using dfs(recursion)
// This is for directed acyclic graph for a cyclic graph this could get traped in infinite loop.
bool hasPathDFS(vector<vector<int>> & graph, int src, int dsc){
    if(src == dsc){
        return true;
    }

    if(graph[src-1].empty()){
        return false;
    }

    for(int i=0; i<graph[src-1].size(); i++){
        if(hasPathDFS(graph, graph[src-1][i], dsc)){
            return true;
        }
    }
    return false;
}


// Implementation of path finding algorithm using bfs(iterative)
// This is for directed acyclic graph for a cyclic graph this could get traped in infinite loop.
bool hasPathBFS(vector<vector<int>> graph, int src, int dsc){
    queue<int> q;
    if(src == dsc){
        return true;
    }

    if(graph[src-1].empty()){
        return false;
    }

    for(int i=0; i<graph[src-1].size(); i++){
        q.push(graph[src-1][i]);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == dsc){
            return true;
        }

        for(int i=0; i<graph[curr-1].size(); i++){
            q.push(graph[curr-1][i]);
        }
    }
    return false;
}


int main(){
    // Acyclic directed graph 1 based indexing of nodes
    vector<vector<int>> graph = {{6,2}, {3,4}, {5}, {}, {4}, {3,7}, {}};

    cout << "Finding Path(By DFS) b/w 2, 5" << endl;
    bool ans = hasPathDFS(graph, 2, 5);
    cout << ans << endl;

    cout << "Finding Path(By BFS) b/w 2, 6" << endl;
    bool ans2 = hasPathBFS(graph, 2, 6);
    cout << ans2 << endl;

    return 0;
}
