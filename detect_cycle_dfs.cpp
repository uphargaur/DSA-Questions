//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool solve(vector<int> adj[],vector<int >&visited,int current,int previous)
    {
        visited[current]=1;
        for(auto x: adj[current])
        {
            if(visited[x]==1 && x!=previous)
            {
                // cout<<current<<"   "<<previous<<endl;
                return true;
            }
            if(visited[x]==0)
            {//make sure ki jab cycle detect hue tab hi return mare as when no cycle is detected in that
            //particular segment means ki there is no cycle at all
               if( solve(adj,visited,x,current)==true)
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int > visited(V,0);
        for (int i = 0; i < V; ++i)
        {
            if(visited[i]==0)
            {
                bool val=solve(adj,visited,i,-2);
                if(val==true)
                {
                    return true;
                }
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends