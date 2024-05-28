//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void solve(int node,vector<int> adj[],map<int,bool>&visited,vector<int>&res){
        res.push_back(node);
        visited[node]=true;
        
        for(int j=0;j<adj[node].size();++j){
            if(!visited[adj[node][j]]){
                visited[adj[node][j]]=true;
                solve(adj[node][j],adj,visited,res);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>res;
        map<int,bool>visited;
        
        for(int i=0;i<V;++i){
            if(!visited[i]){
                solve(i,adj,visited,res);
            }
        }
        
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends