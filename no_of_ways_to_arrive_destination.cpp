//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class compatorbaji
{
public:
bool operator()(pair<int,int> p1, pair<int,int>p2)
{
    if(p1.first==p2.first)
    {
        return p1.second>p2.second;
    }
    return p1.first>p2.first;
}


};




class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        //phele toh adjacecy matricx bana leta hu
        vector<pair<int,int>>  adj[n];
        for (auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //ek visited wala kam karleta 
        vector<int> distance(n,1e8);
        //frequency count karletre
        vector<int > frequency(n,0);
        //priorty queue <    source, distance     >
        priority_queue<pair<int,int>,vector<pair<int,int>>,compatorbaji> pq;
        //starting the traversal baji 
        distance[0]=0;
        frequency[0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it = pq.top();pq.pop();
            int curr_distance=it.second;
            int curr_node=it.first;
            for(auto x: adj[curr_node])
            {
                int new_cost=x.second;
                int new_node=x.first;
                int weight = new_cost+curr_distance;
                if(weight==distance[new_node])
                {
                    frequency[new_node]+=frequency[curr_node];

                }
                else if(weight<distance[new_node])
                {
                    frequency[new_node]=frequency[curr_node];
                    distance[new_node]=weight;
                    pq.push({new_node,weight});
                }
            }
        }
        // for (auto it : frequency)
        // {
        //     cout<<it<<" ";
        // }
    return frequency[n-1];


    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends