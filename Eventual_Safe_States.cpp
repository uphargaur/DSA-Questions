//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool dfs(int ver,vector <int > &visited,vector <int > &path_visit,vector <int > adj [])
    {
        for(auto x: adj[ver])
        {
            if(visited[x]==1 && path_visit[x]==1)
            {
                return true;
            }
            else if( visited[x]==0)
            {
                visited[x]=1;
                path_visit[x]=1;
                if(dfs(x,visited,path_visit,adj) ==true)
                {return true;}
                path_visit[x]=0;

            }
        }
        return false;
    }
    // Function to detect cycle in a directed graph.
   vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int > ans;
        vector <int>  visited(V,0);
        vector <int> path_visit(V,0);
        for (int i = 0; i < V; ++i)
        {
            if (visited[i]==0)
            {
                visited[i]=1;
                path_visit[i]=1;
              if(dfs(i,visited,path_visit,adj) ==true){path_visit[i]=1;}
                // {for(auto x: path_visit)cout<<x;}
                else {path_visit[i]=0;}
            }
        }
       for (int i = 0; i < V; ++i)
       {
           if(path_visit[i]==0)
           {
            ans.push_back(i);
           }
       }
       // cout<<ans.size()
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends