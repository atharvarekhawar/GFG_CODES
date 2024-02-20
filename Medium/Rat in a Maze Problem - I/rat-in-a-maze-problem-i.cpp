//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<string>&res,vector<vector<int>> &m,vector<vector<bool>>&visited,string &path,int n,int row,int col){
         if(row<0 || row>=n || col<0 ||col>=n){
            return;
         }
         
         if(row==n-1 && col==n-1){
             res.push_back(path);
             return;
         }
         
         if(m[row][col] == 0){
             return;
         }
         
         if(visited[row][col]==true){
             return;
         }
         
         visited[row][col]=true;
         
         path+='U';
         solve(res,m,visited,path,n,row-1,col);
         path.pop_back();
         path+='D';
         solve(res,m,visited,path,n,row+1,col);
         path.pop_back();
         path+='R';
         solve(res,m,visited,path,n,row,col+1);
         path.pop_back();
         path+='L';
         solve(res,m,visited,path,n,row,col-1);
         path.pop_back();
         
         visited[row][col] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<string>res;
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return res;
        }
        string path="";
        solve(res,m,visited,path,n,0,0);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends