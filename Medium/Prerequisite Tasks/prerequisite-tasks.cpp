//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>inDegree(N,0);
        vector<vector<int>>store(N);
        queue<int>q;
        int count = 0;

        for(auto pre:prerequisites){
            inDegree[pre.first]++;
            store[pre.second].push_back(pre.first);
        }

        for(int i=0;i<N;++i){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int task = q.front();
            q.pop();
            count++;

            for(auto it:store[task]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        return count==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends