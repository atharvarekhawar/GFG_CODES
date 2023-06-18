//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    long long int solve(string &s ,int n, int k){
    	int start=0;
    	int end=0; 
    	long long int dist = 0;
    	long long int ans = 0;
    	int m[26]={0};
    	
        while(end < n){
            m[s[end]-'a']++;
            if(m[s[end]-'a']==1){
                dist++;
            }
            
            while(dist>k){
                m[s[start]-'a']--;
                if(m[s[start]-'a']==0){
                    dist--;
                }
                start++;
            }
            
            ans+=end-start+1;
            end++;
        }
        return ans;
    }
  public:
    long long int substrCount (string s, int k) {
        int n=s.length();
        return solve(s,n,k)-solve(s,n,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends