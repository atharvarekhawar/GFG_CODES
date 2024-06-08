//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>dist(N,INT_MAX);
        vector<int>adj[N];
        
       
            for(auto edge:edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
        
        
        
        queue<pair<int,int>>q;
        dist[src]=0;
        q.push({src,0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int node = temp.first;
            int weight = temp.second;
            
            for(auto it:adj[node]){
                if(weight+1 < dist[it]){
                    dist[it] = weight+1;
                    q.push({it,weight+1});
                }
            }
        }
        
        for(int i=0;i<N;++i){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends