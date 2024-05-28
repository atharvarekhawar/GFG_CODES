//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(vector<vector<int>> &adj,map<int,bool>&visited,int i){
      visited[i]=true;
      for(int j=0;j<adj[i].size();++j){
          if(adj[i][j]==1 && !visited[j]){
              solve(adj,visited,j);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        map<int,bool>visited;
        
        for(int i=0;i<V;++i){
            if(!visited[i]){
                solve(adj,visited,i);
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends