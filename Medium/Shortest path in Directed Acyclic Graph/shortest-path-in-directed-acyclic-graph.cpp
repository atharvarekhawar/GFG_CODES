//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topoDfs(int node, vector<pair<int,int>>adj[],stack<int>&st,vector<bool>&visited){
        for(auto it:adj[node]){
            if(!visited[it.first]){
                visited[it.first]=true;
                topoDfs(it.first,adj,st,visited);
            }
        }
        
        st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        stack<int>st;
        vector<bool>visited(N,false);
        vector<int>dist(N,1e9);
        
        vector<pair<int,int>>adj[N];
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        for(int i=0;i<N;++i){
            if(!visited[i]){
                visited[i]=true;
                topoDfs(i,adj,st,visited);
            }
        }
        
        dist[0]=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it:adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        
        for(int i=0;i<N;++i){
            if(dist[i]==1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends