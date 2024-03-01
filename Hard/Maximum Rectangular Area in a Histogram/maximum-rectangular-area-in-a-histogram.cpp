//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        //find left smaller element fot every i
        vector<int>prevSmall(n);
        stack<int>st;
        for(int i=0;i<n;++i){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmall[i]=st.top()+1;
            }else{
                prevSmall[i]=0;
            }
            st.push(i);
        }
        
        //find right smaller element fot every i
        vector<int>nextSmall(n);
        st = stack<int>();
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSmall[i]=st.top()-1;
            }else{
                nextSmall[i]=n-1;
            }
            st.push(i);
        }
        
        
        //find max Area considering every i in the array
        long long maxArea = INT_MIN;
        
        for(int i=0;i<n;++i){
            long long currArea = ((nextSmall[i]-prevSmall[i])+1)*arr[i];
            maxArea = max(maxArea,currArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends