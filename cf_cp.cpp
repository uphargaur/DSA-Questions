#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
                
               long long int n, x;cin>>n>>x;
               vector <int> v1;
               long long int even=0,odd=0;
               for (int i = 0; i < n; ++i)
               {
                   int a;cin>>a;
                   v1.push_back(a);
                   if(a&1)
                   {
                    odd++;
                   }
                   else
                   {
                    even++;
                   }
               }
               if(x&1)
               {
               // cout<<even<<endl;
                cout<<even/2 + even %2<<endl;
               }
               else if(!(x&1) && odd==0)
               {
                cout<<-1<<endl;
               }
               else if(odd!=0)
               {
                cout<<even<<endl;
               }
                    
            t--;
            }
               
               
}