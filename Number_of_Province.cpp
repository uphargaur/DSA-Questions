//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private :
    void dfs(vector <int > &visited , vector <int > adj[ ],int index)
    {
        visited[index]=1;
        for(auto x: adj[index])
        {
            if(visited[x]==0)
            dfs(visited,adj,x);
        }
    }

  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector <int > adj1[V];
        vector <int > visited (V,0);
        for (int i = 0; i < V; ++i)
        {
            for(int j =0 ; j< V ; j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adj1[i].push_back(j);
                    adj1[j].push_back(i);
                }
            }
        }
        int count=0;
        for (int i = 0; i < V; ++i)
        {
            if(visited[i]==0)
            {
                dfs(visited,adj1,i);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends