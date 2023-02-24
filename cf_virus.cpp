#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
#define ll long long 
const int mod=1000000007;
int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
            	int n;cin>>n;
            	int virus;cin>>virus;
                vector <ll> infected;
                for (int i = 0; i < virus; ++i)
                {
                	int x;cin>>x;
                	infected.push_back(x);
                }
                sort(all(infected));
                vector <ll> difference;
                int a=infected[0];
                int b=n-infected[virus-1];difference.push_back(a+b-1);
                for (int i = 1; i < virus; ++i)
                {
                	int x=infected[i]-infected[i-1];
                	difference.push_back(x-1);
                }
                //being greddy to sacve the maximum no of people
                sort(all(difference),std::greater<ll>());
                int ans=0;int cost=1;
                for(auto x : difference)
                {
                	// cout<<x<<" ";
                	int temp_difference= x-cost;
                	//considering a case when only one guy is saved 
                	//and rest get saheed
                	if(temp_difference==0)
                	{
                		ans+=1;
                	}
                	if(temp_difference>0)
                	{
                		ans+=temp_difference;
                	}
                	else
                		{break;}
                	// cout<<x<<" ";
                	cost+=4;
                }
                cout<<n-ans<<endl;

                
                
                
            t--;
            }
}