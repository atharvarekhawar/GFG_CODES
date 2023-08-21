//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int findLow(int A[],int N){
        int maxi = INT_MIN;
        for(int i=0;i<N;i++){
            maxi = max(maxi,A[i]);
        }
        return maxi;
    }
    int findHigh(int A[],int N){
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        return sum;
    }
    int checkPages(int A[], int N,int mid){
        int students=1;
        int currPages=0;
        
        for(int i=0;i<N;i++){
            if(currPages + A[i] <= mid){
                currPages+=A[i];
            }
            else{
                students++;
                currPages = A[i];
            }
        }
        return students;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N){
            return -1;
        }
        int low = findLow(A,N);
        int high = findHigh(A,N);
        int res;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            
            int students = checkPages(A,N,mid);
            
            if(students > M){
                low = mid+1;
            }
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends