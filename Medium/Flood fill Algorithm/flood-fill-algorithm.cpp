//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    struct value{
        int row;
        int col;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        int startPixelColor = image[sr][sc];

        visited[sr][sc] = true;

        queue<value>q;
        q.push({sr,sc});

        while(!q.empty()){
            auto pixel = q.front();
            q.pop();

            int row = pixel.row;
            int col = pixel.col;

            visited[row][col] = true;
            
            if(image[row][col]!=startPixelColor) continue;

            image[row][col] = newColor;

            if(row-1>=0 && !visited[row-1][col] && image[row-1][col]==startPixelColor){
                q.push({row-1,col});
            }
            if(row+1<m && !visited[row+1][col] && image[row+1][col]==startPixelColor){
                q.push({row+1,col});
            }
            if(col-1>=0 && !visited[row][col-1] &&  image[row][col-1]==startPixelColor){
                q.push({row,col-1});
            }
            if(col+1<n && !visited[row][col+1] && image[row][col+1]==startPixelColor){
                q.push({row,col+1});
            }
        }

        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends