//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        vector<int>dist(100000,INT_MAX);
        dist[start] = 0;
        
        queue<pair<int,int>>q;
        q.push({start,0});
        
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int node = temp.first;
            int steps = temp.second;
        
            for(auto it:arr){
                int nextNumber = (node*it)%100000 ;
                if(steps+1 < dist[nextNumber]){
                    dist[nextNumber] = steps+1;
                    if(nextNumber==end) return steps+1;
                    q.push({nextNumber,steps+1});
                }
            }
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends