//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	private :
	void bfs(vector<vector<int>> &visited,vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor)
	{
		queue <pair<int,int > > q1;
		q1.push(make_pair(sr,sc));
		visited[sr][sc] =1;
		while(!q1.empty())
		{
			auto current = q1.front();
			q1.pop();
			sr=current.first;sc=current.second;
			if(sr+1<image.size() &&  visited[sr+1][sc]==0 && image[sr+1][sc]==oldcolor )
			{
				image[sr+1][sc]=newColor;
				visited[sr+1][sc]=1;
				q1.push(make_pair(sr+1,sc));
			}
			if(sr-1>=0 &&  visited[sr-1][sc]==0 && image[sr-1][sc]==oldcolor )
			{
				image[sr-1][sc]=newColor;
				visited[sr-1][sc]=1;
				q1.push(make_pair(sr-1,sc));
			}
			if(sc+1<image[0].size() && visited[sr][sc+1]==0 && image[sr][sc+1]==oldcolor  )
			{
				image[sr][sc+1]=newColor;
				visited[sr][sc+1]=1;
				q1.push(make_pair(sr,sc+1));
			}
			if(sc-1>=0  && visited[sr][sc-1]==0 && image[sr][sc-1]==oldcolor )
			{
				image[sr][sc-1]=newColor;
				visited[sr][sc-1]=1; 
				q1.push(make_pair(sr,sc-1));
			}
		}
	}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
    	vector<vector<int>> visited (image.size(),vector<int > (image[0].size(),0));
    	int oldcolor =image[sr][sc];
    	image[sr][sc]=newColor;
    	visited[sr][sc]=1;
    	bfs(visited,image ,sr,sc,newColor,oldcolor);


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