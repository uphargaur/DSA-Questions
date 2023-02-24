//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void find_shape(int nrow ,int ncol ,vector<pair<int ,int>> &temp_vec,vector<vector<int>> &visited,vector <vector <int > > & grid)
{
   visited[nrow][ncol]=1;
    int delrow[4]={1,-1,0,0};
    int delcol[4]={0,0,-1,1};

    // cout<<"row: " <<row<<" "<<col<<endl;
    for (int i = 0; i < 4; i++)
    {
        int row=nrow+delrow[i];
        int col=ncol+delcol[i];
        if(row>=0 && row< grid.size() && col>=0 && col< grid[0].size() && visited[row][col]==0 && (grid[row][col]==1 ))
        {
            visited[row][col]=1;
             find_shape(row,col,temp_vec,visited,grid);
             temp_vec.push_back(make_pair(row,col));
    // cout<<" \n i and j : "<<i<<" "<<row<<" "<<col<<endl;
           
             

        }
    }

}
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int count;
        vector <vector <int > > visited(grid.size(),vector <int > (grid[0].size(),0));
        int n=grid.size(),m=grid[0].size();
        set <vector<pair<int ,int>>> s1;
         for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) 
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                    {
                        // visited[i][j]=1; 
                    vector<pair<int ,int>> temp_vec;  //cout<<i<<" "<<j<<endl;
                     temp_vec.push_back(make_pair(i,j));
                     find_shape(i,j,temp_vec,visited,grid);
                     int base_x=temp_vec[0].first,base_y=temp_vec[0].second;
                     for (int i = 0; i < temp_vec.size(); ++i)
                     {
                         temp_vec[i].first-=base_x;
                         temp_vec[i].second-=base_y;
                     }
                    //  for(auto x:temp_vec)
                    // {x.first=x.first-base_x;
                    // x.second= x.second-base_y;}
                     s1.insert(temp_vec);                       
                    }
                    // cout<<visited[i][j]<<" ";
            }
           
        }
        // for(auto x:s1)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y.first<<y.second<<endl;
        //     }
        // }

            return s1.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends