//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) 
    {
        vector<vector<int>> distance(n,vector<int>(n,1e8));
        for (int i = 0; i < m; ++i)
        {
            distance[edges[i][0]][edges[i][1]]=edges[i][2];
            distance[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        //vector kha se kha tak jarhi
        for (int via = 0; via < n; ++via)
        {
            distance[via][via]=0;
            for (int i = 0; i < n; ++i)
            {
               for (int j = 0; j < n; ++j)
                {
                    int weight=distance[i][via]+distance[via][j];
                    if( distance[i][via]!=1e8 || distance[via][j]!=1e8 )
                    {
                        distance[i][j]=min(distance[i][j],weight);
                    }
                }
            }

        }
        //checking via wala
        int min=1e8;
        int min_city=-1;
            for (int i = 0; i < n; ++i)
            {
                int count=0;
               for (int j = 0; j < n; ++j)
                {
                    if(distance[i][j]<=distanceThreshold)
                    {
                        count++;
                    }
                }
                if(count<=min)
                {
                    min=count;
                    min_city=i;
                }
            }
            
        return min_city;
        

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends