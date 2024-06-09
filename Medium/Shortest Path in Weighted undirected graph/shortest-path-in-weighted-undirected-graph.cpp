//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        
        dist[1]=0;
        parent[1]=1;
        
        pq.push({0,1}); //{distance,node}
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            
            int node = temp.second;
            int distance = temp.first;
            
            for(auto it:adj[node]){
                if(distance + it.second < dist[it.first]){
                    dist[it.first] = distance + it.second;
                    parent[it.first] = node;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        
        vector<int>res;
        int node = n;
        
        while(parent[node] != node){
            res.push_back(node);
            node = parent[node];
        }
        
        res.push_back(1);
        res.push_back(dist[n]);
        
        reverse(res.begin(),res.end());
        
        return res;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends