//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	private :
	int bfs(vector<vector<int>> &grid,vector<vector<int>>& visited,int &count)
	{
		int max_count=0;
		queue <pair<pair<int,int>,int > > q1;
		for (int i = 0; i < grid.size(); ++i)
	    	{
	    		for(int j=0; j<grid[0].size();j++)
	    		{
	    			if(grid[i][j]==2)
	    			{
	    				q1.push(make_pair(make_pair(i,j),count));
	    				visited[i][j]=1;
	    			}
	    		}
	    	}
	    	while(!q1.empty())
		{
			auto index=q1.front();q1.pop();
			int sr=index.first.first,sc=index.first.second,count=index.second;
			
				if(count>max_count)
				{
					max_count=count;
				}
					if(sr+1<grid.size() &&  visited[sr+1][sc]==0 && grid[sr+1][sc]==1 )
					{
						grid[sr+1][sc]=2;
						visited[sr+1][sc]=1;
						q1.push(make_pair(make_pair(sr+1,sc),1+count));

					}
					if(sr-1>=0 &&  visited[sr-1][sc]==0 && grid[sr-1][sc]==1 )
					{
						grid[sr-1][sc]=2;
						visited[sr-1][sc]=1;
						q1.push(make_pair(make_pair(sr-1,sc),1+count));
					}
					if(sc+1<grid[0].size() && visited[sr][sc+1]==0 && grid[sr][sc+1]==1  )
					{
						grid[sr][sc+1]=2;
						visited[sr][sc+1]=1;
						q1.push(make_pair(make_pair(sr,sc+1),1+count));
					}
					if(sc-1>=0  && visited[sr][sc-1]==0 && grid[sr][sc-1]==1)
					{
						grid[sr][sc-1]=2;
						visited[sr][sc-1]=1; 
						q1.push(make_pair(make_pair(sr,sc-1),1+count));
					}
			

		}


		// cout<<max_count;
		return max_count;

	}
public:
     int orangesRotting(vector<vector<int>>& grid) { 
       
    	vector<vector<int>> visited (grid.size(),vector<int > (grid[0].size(),0));
    	int count =0;
    	int max=bfs(grid,visited,count);
    	// cout<<max;
    	
    	for (int i = 0; i < grid.size(); ++i)
	    	{
	    		for(int j=0; j<grid[0].size();j++)
	    		{
	    			if(grid[i][j]==1)
	    			{
	    				return -1;
	    			}
	    		}
	    	}
	    	return max;
    }
}; // Code here

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";

	}
	return 0;
}
// } Driver Code Ends