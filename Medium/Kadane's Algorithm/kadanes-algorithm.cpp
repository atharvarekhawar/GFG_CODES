//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long cs=0;
        long long ms=INT_MIN;
        bool flag=false;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                flag=true;
            }
        }
        
        if(flag){
            for(int i=0;i<n;i++){
            cs=cs+arr[i];
            if(cs<0){
                cs=0;
            }
            ms=max(cs,ms);
        }
        
        return ms;
        }
        else{
            for(int i=0;i<n;i++){
                
                if(arr[i]>ms){
                    ms=arr[i];
                    
                }
           else{ cs=cs+arr[i];
           
            ms=max(cs,ms);
           }
        }
        
        return ms;
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends