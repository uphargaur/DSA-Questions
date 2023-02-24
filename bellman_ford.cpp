//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int s) {
        
        vector <int> distance(V,1e8);
        distance[s]=0;
        for (int i = 0; i < V-1; ++i)
        {
            for(auto it : edges)
            {
                int node_from=it[0];
                int weight=it[2];
                int node_to=it[1];
                if(distance[node_from]!=1e8 && distance[node_to]>distance[node_from]+weight)
                {
                    distance[node_to]=distance[node_from]+weight;
                }
            }
        }
         for(auto it : edges)
            {
                int node_from=it[0];
                int weight=it[2];
                int node_to=it[1];
                if(distance[node_from]!=1e8 && distance[node_to]>distance[node_from]+weight)
                {
                    return{-1};
                }
            }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends