//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector <int > ans;
        queue <int> q1;
        vector <int > indegree(V,0);
        //reverse the direction of the edges
        vector <int > radj[V];
        for (int i = 0; i < V; ++i)
        {
            for (auto x : adj[i])
            {
                radj[x].push_back(i);
                // indegree[i]++;
            }
        }
        //once the edgs are reversed ,run the topo sort and if there is a cycel then it will never have
        //have its indegree as zero
     //calcukate the indegree of all the nodes
     
     for (int i = 0; i < V; ++i)
        {
            indegree[i]=adj[i].size();
            if(indegree[i]==0)
            {
                q1.push(i);
            }
        }
        while(!q1.empty())
        {
            int temp = q1.front();q1.pop();
            ans.push_back(temp);
            for(auto x: radj[temp])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q1.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
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