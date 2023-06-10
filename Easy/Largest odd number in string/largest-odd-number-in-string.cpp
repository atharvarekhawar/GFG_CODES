//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        int n=s.length()-1;

        for(int i=n;i>=0;i--){
            int curr=s[i]-'0';
            if(curr%2 != 0){
               return s.substr(0,i+1);
            }
        }
        return "";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends