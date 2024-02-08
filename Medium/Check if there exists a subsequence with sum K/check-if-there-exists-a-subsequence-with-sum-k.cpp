//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(vector<int>&arr,vector<vector<int>>&dp,int &count,int sum,int i){
        if(i>=arr.size()){
            if(sum==0){
               count++;
            }
            return 0;
        }
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        if(arr[i]<=sum){
            dp[i][sum] = solve(arr,dp,count,sum-arr[i],i+1);
        }
        
        dp[i][sum]+=solve(arr,dp,count,sum,i+1);
        
        
        return dp[i][sum];
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int count = 0;
        solve(arr,dp,count,k,0);
        return count>0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends