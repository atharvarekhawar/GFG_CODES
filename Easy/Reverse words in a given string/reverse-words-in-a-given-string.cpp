//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        reverse(S.begin(),S.end());
        
        int i=0;
        
        for(int k=0;k<S.length();k++){
            if(S[k]=='.' || k==S.length()-1){
                int j = k==S.length()-1?S.length()-1:k-1;
                while(i<j){
                    swap(S[i++],S[j--]);
                }
                i=k+1;
            }
        }
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends