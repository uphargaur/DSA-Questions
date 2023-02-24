//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void bfs(vector < vector <int > > &visited,vector<vector<char>>& grid,int row ,int column)
    {
        
        visited[row][column]=1;
        for (int i = 0; i < 2; ++i)
        {
            for(int j =-1; j< 2;j++)
            {
               int nrow=row+i;
               int  ncol= column+j;
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol <grid[0].size() && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol]=1;
                    // cout<<"mai vhala \n";
                     bfs(visited,grid,nrow,ncol);
                }
            }
        }
        
        
    }

  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        //grid ka size 
        int row = grid.size(),  column =grid[0].size();
        //making visited array
        vector < vector <int > > visited(grid.size(),vector <int > (column,0));
        //count to count no of times ittration is called
        int count=0;
        // for (int i = 0; i < grid.size(); ++i)
        // {
        //     for(int j =0; j< grid[i].size() ; j++)
        //     {
        //         if(grid[i][j]='1')
        //         {
        //             visited[i][j]=0;
        //         }
        //         else
        //              {visited[i][j]=1;}

        //     }
        // }
          for (int i = 0; i < grid.size(); ++i)
        {
            for(int j =0; j< grid[i].size() ; j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    count++;
                    bfs(visited,grid,i,j);
                    
                }
                

            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends