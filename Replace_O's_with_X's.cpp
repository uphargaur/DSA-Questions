//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

    void bfs(int row ,int col ,vector<vector<char>> &ans,vector<vector<char>> mat,vector <vector <int > > &visited)
    {
        if(row+1 <(mat.size()-1) && visited[row+1][col]==0 && mat[row+1][col]=='O')
        {
            ans[row+1][col]='O';
            visited[row+1][col]=1;
            bfs(row+1,col,ans,mat,visited);  
        }
        if(row-1 >0 && visited[row-1][col]==0 && mat[row-1][col]=='O')
        {
            ans[row-1][col]='O';
            visited[row-1][col]=1;
            bfs(row-1,col,ans,mat,visited);  
        }
        if(col+1 <(mat[0].size()-1) && visited[row][col+1]==0 && mat[row][col+1]=='O')
        {
            ans[row][col+1]='O';
            visited[row][col+1]=1;
            bfs(row,col+1,ans,mat,visited);  
        }
        if(col >0 && visited[row][col-1]==0 && mat[row][col-1]=='O')
        {
            ans[row][col-1]='O';
            visited[row][col-1]=1;
            bfs(row,col-1,ans,mat,visited);  
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(n,vector <char> (m,'X') );
        vector <vector <int > > visited (n,vector <int > (m,0));
        for (int i = 0; i < n; ++i)
        {
            visited[i][0]=1;
            visited[i][m-1]=1;
            if(mat[i][0]=='O' )
            {
              ans[i][0]='O'; 
              bfs(i,0,ans,mat,visited);
            }
            if(mat[i][m-1]=='O')
            {
                ans[i][m-1]='O';
                // bfs(i,m-1,ans,mat,visited) ;
                           
            }
        }
        for (int i = 0; i < m; ++i)
        {
             visited[0][i]=1;
            visited[n-1][i]=1;
            if(mat[0][i]=='O' )
            {
                ans[0][i]='O';
                 bfs(0,i,ans,mat,visited);  
            }
            if(mat[n-1][i]=='O')
            {
                ans[n-1][i]='O';
                 bfs(n-1,i,ans,mat,visited) ; 
            }
        }


        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends