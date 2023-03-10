//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
        void bfs(int index,vector <int > &visited, vector<int> adj[],stack <int> &s1)
        { 
            for (auto x: adj[index])
            {
                 if(visited[x]==0)
                    {
                        visited[x]=1;
                        bfs(x,visited,adj,s1);
                        
                    }
            }
            s1.push(index);
        }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector <int > visited(V,0);
        vector <int > ans(V,0);
        stack <int> s1;
	    for (int i = 0; i < V; ++i)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                bfs(i,visited,adj,s1);
                // s1.push(i);
            }
        }
        int j=0;
        while(!s1.empty())
        {
            ans[j]=s1.top();j++;
            s1.pop();
        }
        for(auto x: ans)
        {
            cout<<x<<" ";
        }
        return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends