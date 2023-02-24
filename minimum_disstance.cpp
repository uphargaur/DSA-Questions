//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class comparebaji
{
public:
    bool operator()(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
    {
        return p1.second>p2.second;
    }

};

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int no_row=heights.size();
        int no_col=heights[0].size();
        priority_queue<pair<pair<int,int>,int> ,vector<pair<pair<int,int>,int>>,comparebaji> pq;
        pq.push({{0,0},0});
        vector<vector<int>> distance (no_row,vector<int> (no_col,1e9));
        distance[0][0]=0;
        while(!pq.empty())
        {
            auto x= pq.top();
            pq.pop();
            int cur_row=x.first.first;
            int cur_col =x.first.second;
            int difference= x.second;
            if(cur_row==no_row-1 && cur_col==no_col-1)
            {
                return difference;
            }
            int dr[]={-1,1,0,0};
            int dc[]={0,0,1,-1};
            for (int i = 0; i < 4; ++i)
            {
                int nrow=cur_row+dr[i];
                int ncol=cur_col+dc[i];
                if(nrow>=0 && nrow<no_row && ncol>=0 && ncol<no_col )
                {
                    // cout<<"nrow ->"<<nrow<<" ncol ->"<<ncol<<endl;
                    int ncost=max(abs(heights[nrow][ncol]-heights[cur_row][cur_col]),difference);
                    if(distance[nrow][ncol] >ncost)
                    {
                        distance[nrow][ncol]=ncost;
                        pq.push({{nrow,ncol},ncost});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends