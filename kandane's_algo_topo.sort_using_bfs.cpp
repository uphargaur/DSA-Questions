//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
      vector <int > adj[V];
       for (int i = 0; i < m; ++i)
       {
           vector <int> temp= prerequisites[i];
           adj[temp[1]].push_back(temp[0]);
       }
       vector <int> ans ;
        queue <int > q1;
        vector <int > indegree(V,0);
         vector <int > visited(V,0);
        for (int i = 0; i < V; ++i)
        {
            for(auto x: adj[i])
            {
                indegree[x]++;
            }
        }
        for (int i = 0; i < V; ++i)
        {
            if(indegree[i]==0)
            {
                ans.push_back(i);
                q1.push(i);
                visited[i]=1;
            }

        }
        while(!q1.empty())
        {
            int temp =q1.front();
            q1.pop();
            for(auto x: adj[temp])
            {
                indegree[x]--;
                if(indegree[x]==0 && visited[x]==0)
                {
                    ans.push_back(x);
                    q1.push(x);
                    visited[x]=1;
                }


            }
            //chcek if the indegree turns out to be zero   

        }
        for(auto x : ans)
        {
            cout<<x<<" ";
        }
        vector <int> empty;
        if(ans.size()==V)
        return ans;
        else
        return empty;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends