//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<int>> ans=grid;
        int flag=0;
        vector <vector <int > > visited(grid.size(),vector <int > (grid[0].size(),0));
        int n=grid.size(),m=grid[0].size();
        queue <pair<int,int >>q1;
        for (int i = 0; i < n; ++i)
        {
            visited[i][0]=1;
            visited[i][m-1]=1;
            if(grid[i][0]==1 )
            {
              ans[i][0]=0; 
              q1.push(make_pair(i,0));
            }
            if(grid[i][m-1]==1)
            {
                ans[i][m-1]=0;
                q1.push(make_pair(i,m-1));
            }
        }
        for (int i = 0; i < m; ++i)
        {
             visited[0][i]=1;visited[n-1][i]=1;
            if(grid[0][i]==1 )
            {
                ans[0][i]=0;
                q1.push(make_pair(0,i));  
            }
            if(grid[n-1][i]==1)
            {
                ans[n-1][i]=0;
                q1.push(make_pair(n-1,i)); 
            }
        }
        while(!q1.empty())
        {
            auto temp =q1.front();
            int row=temp.first;int col=temp.second;
            q1.pop();
              if(row+1 <(grid.size()-1) && visited[row+1][col]==0 && grid[row+1][col]==1)
        {
            ans[row+1][col]=0;
            visited[row+1][col]=1;
            q1.push(make_pair(row+1,col)); 
        }
        if(row-1 >0 && visited[row-1][col]==0 && grid[row-1][col]==1)
        {
            ans[row-1][col]=0;
            visited[row-1][col]=1;
            q1.push(make_pair(row-1,col));   
        }
        if(col+1 <(grid[0].size()-1) && visited[row][col+1]==0 && grid[row][col+1]==1)
        {
            ans[row][col+1]=0;
            visited[row][col+1]=1;
            q1.push(make_pair(row,col+1)) ;  
        }
        if(col >0 && visited[row][col-1]==0 && grid[row][col-1]==1)
        {
            ans[row][col-1]=0;
            visited[row][col-1]=1;
            q1.push(make_pair(row,col-1));   
        }          
        }
         for(int i = 0;i < n;i++) {
                        for(int j = 0;j < m;j++) {
                            if(ans[i][j]==1)
                            {
                                flag++;
                            }
                        }
                        }
                        return flag;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends