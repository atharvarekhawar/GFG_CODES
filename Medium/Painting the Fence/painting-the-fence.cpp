//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    #define MOD 1000000007
    private:
    int add(int a,int b){
        return ((a%MOD)+(b%MOD))%MOD;
    }
    int mul(int a,int b){
        return ((a%MOD) * 1LL * (b%MOD))%MOD;
    }
    long long solve(int n,int k,vector<int>&dp){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,mul(k,k-1));
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n] = add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
        
        return dp[n];
    }
    public:
    long long countWays(int n, int k){
        vector<int>dp(n+1,-1);
        long long ans = solve(n,k,dp);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends