#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    if(a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	   int v[n];
	   unordered_map<int,int>mp;
	   
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        mp[v[i]]++;
	    }
	    
	    vector<pair<int,int>>store;
	    
	    for(auto i:mp){
	        store.push_back(i);
	    }
	    
	    sort(store.begin(), store.end(),compare);
	    
	    
	    for(auto i:store){
	         for(int j=0; j<i.second; j++){
                  cout<<i.first<<" ";
              }
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}