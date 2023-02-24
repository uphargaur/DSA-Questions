//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    void toposort(vector <pair<int , int>> adj[ ],vector <int > &visited ,int index,stack<int> &s1)
    {
        visited[index]=1;
       
        for(auto x:adj[index])
        {
            if(visited[x.first]==0)
            {
                toposort(adj,visited,x.first,s1);
            }
        }
         s1.push(index);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //convert the gicen matrix into a graoph into a adjacency matrix
        vector <pair<int , int>> adj[N];
        for (int i = 0; i < M; ++i)
        {
            int edge_from=edges[i][0];
            int edge_to=edges[i][1];
            int weight= edges[i][2];
            adj[edge_from].push_back({edge_to,weight});

        }
     //lets make a distance array
     vector <int > distance(N, 12229);
      vector <int > visited(N,0);
     //apply topo on the gicen adj matrix and take the stack
     stack <int > s1;
     for (int i = 0; i < N; ++i)
     {
         if(visited[i]==0)
         {
            toposort(adj,visited,i,s1);
         }
     }
     distance[0]=0;
     while(!s1.empty())
     {
        int temp = s1.top();s1.pop();
        // cout<<temp;
        for(auto x: adj[temp])
        {
            int node=x.first;
            int weight=x.second;
            if (distance[temp]+weight < distance[node])
            {
                distance[node]=distance[temp]+weight;
            }
        }
     }
     for (int i = 0; i < N; ++i)
     {
         if(distance[i]== 12229)
         {
            distance[i]=-1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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