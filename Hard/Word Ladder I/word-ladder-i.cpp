//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({startWord,1});

        s.erase(startWord);

        while(!q.empty()){
            auto temp = q.front();
            string word = temp.first;
            int len = temp.second;

            q.pop();

            if(word == targetWord) return len;

            for(int i=0;i<word.length();++i){
                for(int j=0;j<26;++j){
                    string temp = word;
                    temp[i] = 'a'+j;
                    if(s.find(temp)!=s.end()){
                        q.push({temp,len+1});
                        s.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends