#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
                
               int n; cin>>n;
               vector <int > v1(n,0);
               int flag=0;
               vector <int> even;
               vector <int> odd;
               for (int i = 0; i < n; ++i)
               {
                   cin>>v1[i];
                   if(v1[i]&1)
                   	{
                   		odd.push_back(i+1);
                   	}
                   else
                   {
                   	even.push_back(i+1);}
                   
               }
               if(odd.size()>=3)
               {
               	cout<<"YES\n";
               	cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2]<<"\n";

               }
               else if(odd.size()==1 || (odd.size()==2 && even.size()>1))
               {
               	cout<<"YES\n";
               	cout<<odd[0]<<" "<<even[1]<<" "<<even[0]<<"\n";
               }
               else
               {
               	cout<<"NO\n";
               }

                
                
            t--;
            }
}