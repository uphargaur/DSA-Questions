//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
       vector <int > ans;
       vector <int > visited (n,0);
       stack <int> s1;
       s1.push(0);
       while(!s1.empty())
       {
        int temp= s1.top();
        s1.pop();
        
        if(visited[temp]==0)
        {
            ans.push_back(temp);
        visited[temp]=1;
        }
        for(int x = adj[temp].size()-1;x >=0;x--)
        {
            if(visited[adj[temp][x]]==0)
            {
                s1.push(adj[temp][x]);
            }
        }
       }
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