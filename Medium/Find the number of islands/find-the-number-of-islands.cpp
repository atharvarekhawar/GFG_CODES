//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int islands = 0;
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!visited[i][j] && grid[i][j]=='1'){
                    q.push({i,j});
                    visited[i][j] = true;
                    
                    while(!q.empty()){
                        auto node = q.front();
                        q.pop();
                        
                        int row = node.first;
                        int col = node.second;
                        
                        
                        if(row-1>=0 && grid[row-1][col]!='0' && !visited[row-1][col]){
                            q.push({row-1,col});
                            visited[row-1][col] = true;
                        }
                        if(row+1<m && grid[row+1][col]!='0' && !visited[row+1][col]){
                            q.push({row+1,col});
                            visited[row+1][col] = true;
                        }
                        if(col-1>=0 && grid[row][col-1]!='0' && !visited[row][col-1]){
                            q.push({row,col-1});
                            visited[row][col-1] = true;
                        }
                        if(col+1<n && grid[row][col+1]!='0' && !visited[row][col+1]){
                            q.push({row,col+1});
                            visited[row][col+1] = true;
                        }
                        if(row-1>=0 && col-1>=0 && grid[row-1][col-1]!='0' && !visited[row-1][col-1]){
                            q.push({row-1,col-1});
                            visited[row-1][col-1] = true;
                        }
                        if(row-1>=0 && col+1<n && grid[row-1][col+1]!='0' && !visited[row-1][col+1]){
                            q.push({row-1,col+1});
                            visited[row-1][col+1] = true;
                        }
                        if(row+1<m && col-1>=0 && grid[row+1][col-1]!='0' && !visited[row+1][col-1]){
                            q.push({row+1,col-1});
                            visited[row+1][col-1] = true;
                        }
                        if(row+1<m && col+1<n && grid[row+1][col+1]!='0' && !visited[row+1][col+1]){
                            q.push({row+1,col+1});
                            visited[row+1][col+1] = true;
                        }
                    }
                    
                    islands++;
                }
            }
        }
        
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends