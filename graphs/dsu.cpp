#include <bits/stdc++.h>

using namespace std;

// Also known as union find algorithm
// Path compression and rank based disjoint set union data structure on avg O(1)
// If we don't do path compression or rank then O(logn)

class DSU {
  private:
  vector<int> parent, rank;

  public:
  DSU(int n){
    parent.resize(n);
    rank.resize(n, 0);
    for (int i=0; i<n; i++) 
      parent[i] = i;
  }

  int find_set(int v){
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b)
      if(rank[a] < rank[b])
        swap(a, b);
      parent[b] = a;
      if(rank[a] == rank[b])
        rank[a]++;
  }
};

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
  DSU dsu(n);
  vector<bool> ans(queries.size(), false);
  // for maintaining order of queries
  for(int i=0; i<queries.size(); i++){
    queries[i].push_back(i);
  }

  // sorting queries and edgelist by limit and dist
  sort(queries.begin(), queries.end(), [](vector<int> & left, vector<int> & right){
    return left[2] < right[2];
  });

  sort(edgeList.begin(), edgeList.end(), [](vector<int> & left, vector<int> & right){
    return left[2] < right[2];
  });

  int j=0;
  for(int i=0; i<queries.size(); i++){
    int limit = queries[i][2];
    // building the graph
    while(j<edgeList.size() && edgeList[j][2] < limit){
      dsu.union_set(edgeList[j][0], edgeList[j][1]);
      j++;
    }
    // check if path exists
    if(dsu.find_set(queries[i][0]) == dsu.find_set(queries[i][1])){
      ans[queries[i][3]] = true;
    }
  }

  return ans;
}

int main(){
  // leetcode 1697 checking existence of edge length limited paths
  vector<vector<int>> edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
  vector<vector<int>> queries = {{0,1,2},{0,2,5}};

  vector<bool> ans = distanceLimitedPathsExist(3, edgeList, queries);

  cout << "Output: \n";
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}