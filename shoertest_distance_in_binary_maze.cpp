//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       
       int ans=0;
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<int> > distance(grid.size(),vector <int> (grid[0].size(),123456));
       // for (int i = 0; i < distance.size(); ++i)
       //  {
       //   cout<<i<<" ->";
       //   for(auto y: distance[i])
       //   {cout<<y<<" ";}
       //   cout<<endl;
       //  }
       queue<pair<pair<int,int>,int>> q1;
       q1.push({{source.first,source.second},0});
       distance[source.first][source.second]=0; 
       // priority_queue <int ,vector <int >, greater<int>  > pq;
       while(!q1.empty())
       {
            auto x=q1.front();
            q1.pop();
            int current_row=x.first.first;
            int current_col=x.first.second;
            int current_cost=x.second;
            // for (int i = 0; i < distance.size(); ++i)
            // {
            //  cout<<i<<" ->";
            //  for(auto y: distance[i])
            //  {cout<<y<<" ";}
            //  cout<<endl;
            // }
            // cout<<"row->"<<current_row<<"col-> "<<current_col<<endl;
            
            //aage
            if(current_row+1 <n && grid[current_row+1][current_col]==1)
                {
                    int weight=current_cost+1;
                    // cout<<"niche\n";
                    if(distance[current_row+1][current_col]>weight)
                    {
                        distance[current_row+1][current_col]=weight;
                        q1.push({{current_row+1,current_col},weight});
                    }
                }
                //piche
             if(current_row-1 >=0 &&grid[current_row-1][current_col]==1)
                {
                    // cout<<"upar\n";
                    int weight=current_cost+1;
                    if(distance[current_row-1][current_col]>weight)
                    {
                        distance[current_row-1][current_col]=weight;
                        q1.push({{current_row-1,current_col},weight});
                    }
                }
                //upar
              if(current_col+1 <m &&grid[current_row][current_col+1]==1)
                {
                    int weight=current_cost+1;
                    // cout<<"aage "<<weight<<" \n";
                    if(distance[current_row][current_col+1]>weight)
                    {
                        distance[current_row][current_col+1]=weight;
                        q1.push({{current_row,current_col+1},weight});
                    }
                }
                //niche
              if(current_col-1 >=0 && grid[current_row][current_col-1]==1)
                {
                    int weight=current_cost+1;
                    if(distance[current_row][current_col-1]>weight)
                    {
                        // cout<<"piche "<<weight<<" \n";
                        distance[current_row][current_col-1]=weight;
                        q1.push({{current_row,current_col-1},weight});
                    }
                }

       }
       // for (int i = 0; i < distance.size(); ++i)
       //      {
       //       cout<<i<<" ->";
       //       for(auto y: distance[i])
       //       {
       //          if(y==108)
       //      {cout<<0<<" ";}
       //      else
       //          {cout<<y<<" ";}
       //  }
       //       cout<<endl;
       //      }

       
       // cout<<distance[destination.first][destination.second];
       if(distance[destination.first][destination.second]!=123456)
            {
                return distance[destination.first][destination.second];
            }


       return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends