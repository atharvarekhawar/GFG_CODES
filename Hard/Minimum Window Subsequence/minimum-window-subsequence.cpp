//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int minLength = INT_MAX;
        string res = "";
        int l=0;
        int r=0;
        int k=0;
        
        while(r<m && k<n){
            if(str1[r]==str2[k]){
                ++k;
            }
            
            if(k==n){
                l=r;
                --k;
                while(l>=0 && k>=0){
                    if(str1[l]==str2[k]){
                        --k;
                    }
                    --l;
                }
                
                ++l;
                
                if(minLength > r-l+1){
                    minLength = r-l+1;
                    res = str1.substr(l,minLength);
                }
                
                k=0;r=l+1;
            }
            ++r;
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends