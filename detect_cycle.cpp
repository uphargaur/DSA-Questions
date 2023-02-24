//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector  <int >  visited(V,0);
       queue <pair<int,int>> q1;
       for (int i = 0; i < V; ++i)
       {
       	if(visited[i]==0)
       	{
       		q1.push(make_pair(i,i));
       		 visited[i]=1;
		       while(!q1.empty())
		       {
		       	auto index = q1.front();
		       	q1.pop();
		       	int current=index.first,previous=index.second;
		       	// cout<<current<<" ";
		       	for(auto x: adj[current])
		       	{
		       		if(visited[x]==1 &&x!=previous)
		       		{
		       			return true;
		       		}
		       		if(visited[x]==0 )
		       		{
		       			q1.push(make_pair(x,current));
		       			visited[x]=1;
		       		}
		       	}
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