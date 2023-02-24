//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    	//lao convert it into adj matrix
    	vector< vector <pair<int,int> >> adj(n+1);
    	for (int i = 0; i < edges.size(); ++i)
    	{
    		int edge_to=edges[i][0];
    		int edge_from=edges[i][1];
    		int weight=edges[i][2];
    		adj[edge_from].push_back({edge_to,weight});
    		adj[edge_to].push_back({edge_from,weight});
    	}
    	// for (int i = 0; i < edges.size(); ++i)
        // {
        // 	cout<<i<<" ->";
        // 	for(auto y: adj[i])
        // 	{cout<<y.first<<" ";}
        // 	cout<<endl;
        // }
       	vector <int> ans;
        vector <int> parent(n+1);
        for (int i = 1; i <= n; ++i)
        {
        	parent[i]=i;
        }
        vector <int> cost_arr(n+1,24234);
        queue <pair<int,int> > q1;
        cost_arr[1]=0;
        q1.push({1,0});
        while(!q1.empty())
        {
        	auto current= q1.front();
        	int node=current.first;
        	int curr_weight=current.second;
        	q1.pop();
        	for (auto x: adj[node])
        	{
        		int weight=x.second+curr_weight;
        		int temp_node=x.first;
        		if(weight<cost_arr[temp_node])
        		{
        			cost_arr[temp_node]=weight;
        			parent[temp_node]=node;
        			q1.push({temp_node,weight});
        		}
        	}
        	
        }
        if(cost_arr[n]==242394)
		       {
		       	return {-1}; 
		       }
        int node1 = n;
        	while (parent[node1] != node1)
		        {
		            ans.push_back(node1);
		            node1 = parent[node1];
		        }
		       ans.push_back(1);
        // for(auto x: parent)
        // {
        // 	cout<<x<<" ";
        // }

		 reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends