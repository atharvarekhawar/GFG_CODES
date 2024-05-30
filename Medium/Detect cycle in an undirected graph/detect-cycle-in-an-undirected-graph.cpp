//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        int parent = -1;
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<V;++i){
            if(!visited[i]){
                visited[i]=true;
                q.push({i,parent});
            }
            
            while(!q.empty()){
             int node = q.front().first;
             parent = q.front().second;
             q.pop();
            
             for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it,node});
                }
                else{
                    if(visited[it]==true && it!=parent){
                        return true;
                    }
                }
             }
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