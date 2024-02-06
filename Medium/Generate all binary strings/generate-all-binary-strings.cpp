//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(vector<string>&res,string curr,int n){
        if(n==0){
            res.push_back(curr);
            return;
        }
        
        solve(res,curr+'0',n-1);
        
        if(curr[curr.size()-1]!='1'){
            solve(res,curr+'1',n-1);
        }
        
        
    }
    vector<string> generateBinaryStrings(int num){
        vector<string>res;
        string curr ="";
        solve(res,curr,num);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends