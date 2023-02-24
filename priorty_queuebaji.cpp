#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int  ll;
using namespace std;

class comparebaji
{
public:
    bool operator()(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
    {
        return p1.second<p2.second;
    }

};

int32_t main()  {
    
    int t;
    cin>>t;
    while (t>0)
            {
                
              int n;cin>>n;
              vector<pair<pair<int,int>,int>> v1;
               priority_queue<pair<pair<int,int>,int> ,vector<pair<pair<int,int>,int>>,comparebaji> pq;
               for (int i = 0; i < n; ++i)
               {
                int m,n,cost;cin>>m>>n>>cost;
                   pq.push({{m,n},cost});
               }
              while(!pq.empty())
              {
                cout<<pq.top().second<<endl;
                pq.pop();
              }
                
                
            t--;
            }
}