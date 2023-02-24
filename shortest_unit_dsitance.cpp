//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(vector<int> &ans, vector<int> adj[ ],int index)
    {
        for (auto x: adj[index])
        {
            int temp_weight=ans[index]+1;
            if(temp_weight<ans[x])
            {
                ans[x]=temp_weight;
                dfs(ans,adj,x);
            }
        }
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector <int> adj[N];
       for(auto x: edges)
          {          adj[x[0]].push_back(x[1]);
                    adj[x[1]].push_back(x[0]);
        }
        vector <int> ans(N,92199);
        vector <int> visited(N,0);
        ans[src]=0;
        dfs(ans,adj,src);
        for (int i = 0; i < N; ++i)
        {
            if (ans[i]==92199)
            {
                ans[i]=-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends