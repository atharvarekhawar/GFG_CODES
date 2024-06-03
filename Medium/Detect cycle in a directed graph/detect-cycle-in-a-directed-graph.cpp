//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs (int node, vector<int> adj[],vector<bool>&visited,vector<bool>&pathVisited){
        visited[node]=true;
        pathVisited[node]=true;
        for(int i=0;i<adj[node].size();++i){
            if(pathVisited[adj[node][i]]==true) return true;
            if(!visited[adj[node][i]] && dfs(adj[node][i],adj,visited,pathVisited)){
                return true;
            }
        }
        pathVisited[node] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<bool>pathVisited(V,false);
        
        for(int i=0;i<V;++i){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathVisited)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends