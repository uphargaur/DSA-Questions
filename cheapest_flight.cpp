//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // phele grapg me convert karlete  convert karleta hu
        vector<pair<int,int>> adj[n];
        for (int i = 0; i < flights.size(); ++i)
        {
            int flight_from=flights[i][0];
            int flight_to=flights[i][1];
            int weight=flights[i][2];
            adj[flight_from].push_back({flight_to,weight});
        }
        // for (int i = 0; i < n; ++i)
        // {
        //      for (auto y:adj[i])
        //     {
        //         cout<<i<<" ->"<<y.first<<" ->"<<y.second<<" ";
        //          cout<<" \n";
        //     }
           
        // }
        
        //now we will use a queue
        //queue me kya aayuega <stops> / <distnace> / source node
        queue <pair<int,pair<int,int>>> q1;
        vector<int> distance(n,1e9);
        distance[src]=0;
        q1.push({0,{0,src}});
        while(!q1.empty())
        {
            auto it =q1.front();q1.pop();
            int curr_stops=it.first;
            int curr_distance=it.second.first;
            int curr_source=it.second.second;
            if(curr_stops>K)
            {
                continue;
            }
            //now ;ets ittriate over whole adj postions
            for (auto x: adj[curr_source])
            {
                int adj_weight=x.second;
                int adj_source=x.first;
                int weight=adj_weight+curr_distance;
                if(weight<distance[adj_source] && curr_stops<=K)
                {
                    q1.push({curr_stops+1,{weight,adj_source}});
                    distance[adj_source]=weight;
                }
            }

        }
        // for (auto x:distance)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        if(distance[dst]==1e9)
        {
          
            return -1;
        }
         return distance[dst];

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends