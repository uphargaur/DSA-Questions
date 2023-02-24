//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.


    void solve(vector<int> adj[],vector <int > &ans, vector <int > &visited ,int n)
    {
        if(ans.size()==visited.size())
        {
            return;
        }
        int temp=n;
        ans.push_back(temp);
        // cout<<temp;
        visited[temp]=1;
       for(auto x : adj[temp])
       {
        if(visited[x]==0)
            {
                solve(adj,ans,visited,x);
            }
        } 
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
       vector <int > ans;
       vector <int > visited (n,0);
       solve(adj,ans,visited,0);
      
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends