#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
                int n; cin>>n;
               vector <long long int > v1(n,0);
               long long int flag=0;
               for (long long int i = 0; i < n; ++i)
               {
                   cin>>v1[i];
               }
               vector <long long int> cumulative_sum(n+1,0);
                for (long long int i = 1; i <= n; ++i)
                {
                    cumulative_sum[i]=cumulative_sum[i-1]+v1[i-1];
                    // cout<<cumulative_sum[i]<<" ";
                }
               sort(all(cumulative_sum));
               long long int max_gcd=0;
                for (int i = 1; i < n; ++i)
                {
                    // cumulative_sum[i]%=2;
                    // cout<<cumulative_sum[i]<<" ";
                     long long int g1=gcd(cumulative_sum[n]-cumulative_sum[i],cumulative_sum[i]);
                     max_gcd=max(g1,max_gcd);
                }
                cout<<max_gcd<<endl;
                // cout<<cumulative_sum[n/2]<<" "<<cumulative_sum[n]-cumulative_sum[n/2]<<" ";
                // cout<<n;
                //odd ka sorted mamlahai ek hi case possible hai
                // ;
                // if(n&1)
                // {
                //     cout<<gcd(cumulative_sum[n]-cumulative_sum[(n+1)/2],cumulative_sum[(n+1)/2])<<endl;
                // }
                // else
                //     {
                        // int g1=gcd(cumulative_sum[n]-cumulative_sum[(n+1)/2],cumulative_sum[(n+1)/2]);
                        // if(cumulative_sum.size()>3)
                        // {int g2=gcd(cumulative_sum[n]-cumulative_sum[(n/2)],cumulative_sum[(n/2)]);
                        // int g3=gcd(cumulative_sum[n]-cumulative_sum[(n-1)/2],cumulative_sum[(n-1)/2]);
                        // cout<<max(max(g1,g2),g3)<<endl;}
                        //  // cout<<g2<<endl;}
                        // else
                        //     cout<<g1<<endl;
                    // }

                // for (int i = 0; i < n-2; ++i)
                // {
                //     if(cumulative_sum[i]==0 && cumulative_sum[i+3]==1)
                //     {
                //         cout<<"YES\n";i++;
                //         cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                //         flag=-1;
                //         break;
                //     }
                //     if(cumulative_sum[i]==1 && cumulative_sum[i+3]==0)
                //     {
                //         cout<<"YES\n";i++;
                //         cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                //         flag=-1;
                //         break;
                //     }
                // }
                // if(flag==0)
                // {cout<<"NO\n";}
                
            t--;
            }
}