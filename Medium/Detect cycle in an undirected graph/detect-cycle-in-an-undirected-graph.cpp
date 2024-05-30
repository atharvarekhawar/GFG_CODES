//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solve(int node,vector<int> adj[],vector<bool>&visited,vector<int>&parent){
        visited[node]=true;
        
        for(auto it:adj[node]){
            if(!visited[it]){
              parent[it] = node;
              if (solve(it, adj, visited, parent)) {
                  return true;
              }
            }
            else if(it!=parent[node]){
                return true;
            }
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<int>parent(V,-1);
        
        for(int i=0;i<V;++i){
            if(!visited[i]){
                bool ans = solve(i,adj,visited,parent);
                
                if(ans) return true;
            }
        }
        
        
        return false;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends