//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static compare(Job first , Job second){
        return first.profit > second.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,compare);
        
        vector<int>store(n+1,-1);
        int profit = 0;
        int jobs = 0;
        
        for(int i=0;i<n;++i){
            if(store[arr[i].dead]==-1){
                store[arr[i].dead] = arr[i].id;
                profit+=arr[i].profit;
                jobs++;
            }
            else{
                int j = arr[i].dead - 1;
                while(j>0 && store[j]!=-1){
                    j--;
                }
                if(j>0){
                    store[j] = arr[i].id;
                    profit+=arr[i].profit;
                    jobs++;
                }
            }
        }
        
        vector<int>res;
        res.push_back(jobs);
        res.push_back(profit);
        
        return res;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends