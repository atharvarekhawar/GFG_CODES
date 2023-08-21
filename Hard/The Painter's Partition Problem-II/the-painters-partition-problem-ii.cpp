//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  long long findLow(int arr[],int N){
        long long maxi = INT_MIN;
        for(int i=0;i<N;i++){
            maxi = max(maxi,1ll*arr[i]);
        }
        return maxi;
    }
    long long findHigh(int arr[],int N){
        long long sum=0;
        for(int i=0;i<N;i++){
            sum+=1ll*arr[i];
        }
        return sum;
    }
    long long checkTime(int arr[], int N,long long mid){
        long long painters=1;
        long long currTime=0;
        
        for(int i=0;i<N;i++){
            if(currTime + arr[i] <= mid){
                currTime+=arr[i];
            }
            else{
                painters++;
                currTime = arr[i];
            }
        }
        return painters;
        
    }
    long long minTime(int arr[], int n, int k)
    {
        long long low = findLow(arr,n);
        long long high = findHigh(arr,n);
        long long res;
        
        while(low<=high){
            long long mid = low+(high-low)/2;
            
            int painters = checkTime(arr,n,mid);
            
            if(painters > k){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends