#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int  ll;
using namespace std;
class compare()
bool compataornaji(vector<vector <int >> v1 , vector<vector <int >> v2)
{
    return v1[2] >v2[2];
}

int32_t main()  {
    
    int t;
    cin>>t;
    while (t>0)
            {
                int count=0;
                
              int n,k;cin>>n>>k;
              vector<vector <int >> no(n,vector<int> v1(4));
              for (int i = 0; i < n; ++i)
              {
                 cin>>no[0][i];
              }
              for (int i = 0; i < n; ++i)
              {
                 cin>>no[1][i];
                 no[2][i]=no[1][i]+no[0][i];
              }
              sort(no.begin(),no.end(),compataornaji)



                
                
            t--;
            }
}