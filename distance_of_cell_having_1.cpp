//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	 vector<vector<int>> ans(grid.size(),vector <int >(grid[0].size(),0));
	 queue <pair<pair<int ,int > ,int>> q1;
	 vector<vector<int>>visited(grid.size(),vector <int >(grid[0].size(),0));
	 for (int i = 0; i < grid.size(); ++i)
	 {
	 	for (int j = 0; j < grid[0].size(); ++j)
	 	{
	 		if(grid[i][j]==1)
	 		{
	 			q1.push(make_pair(make_pair(i,j),0));
	 			visited[i][j]=1;
	 		}
	 	}
	 }
	 while(!q1.empty())
	 {
	 	auto temp = q1.front();q1.pop();
	 	int i=temp.first.first,j=temp.first.second;
	 	int count=temp.second;
	 	ans[i][j]=count;
	 	int nrow=grid.size();
	 	int ncol=grid[0].size();
	 	// cout<<i <<"  "<<j<<endl;
	 	
	 	//upar wali row
	 	if(i+1 < nrow && visited[i+1][j]==0 )
	 	{
	 		q1.push(make_pair(make_pair(i+1,j),count+1));
	 		visited[i+1][j]=1;
	 	}
	 	//piche wali row
	 	if(i-1 >= 0 && visited[i-1][j]==0 )
	 	{
	 		q1.push(make_pair(make_pair(i-1,j),count+1));
	 		visited[i-1][j]=1;
	 	}
	 	//niche wala collumn
	 	if(j+1 <ncol && visited[i][j+1]==0 )
	 	{
	 		q1.push(make_pair(make_pair(i,j+1),count+1));
	 		visited[i][j+1]=1;
	 	}
	 	//upar wala collumn
	 	if(j-1 >=0 && visited[i][j-1]==0 )
	 	{
	 		q1.push(make_pair(make_pair(i,j-1),count+1));
	 		 visited[i][j-1]=1;
	 	}
	 }






	 return ans;  
	}
};

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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends