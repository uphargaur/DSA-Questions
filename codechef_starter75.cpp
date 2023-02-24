#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
                
               int n;cin>>n;
               string str;
               cin>>str;
               vector<int > continous_one;
               int count=0;
               for (int i = 0; i < str.length(); ++i)
               {
               		if(str[i]=='1')
               		{
               			count++;
               			if (i==str.length()-1)
               			{
               				continous_one.push_back(count);
               			}
               		}

               		else
               		{
               			if(count!=0)
               			{continous_one.push_back(count);}
               			count=0;
               		}
               }
               if(continous_one.size()==0)
               {
               	cout<<0<<endl;
               }
               else{
               // for(auto x: continous_one)
               // {
               // 	cout<<x<<" ";
               // }
               // cout<<endl;
               int prt2=0,part3=0;
               
               if(continous_one.size()!=0)
               {
               	prt2=continous_one[0];
               }
               continous_one[0]=0;
               sort(all(continous_one));
               if(continous_one.size()>1)
               {
               	 part3=continous_one[continous_one.size()-1];
               }
               // cout<<part3<<prt2<<endl;
               int size=continous_one.size()-1;
                if(str[0]=='1' )
               {
               	cout<<max(prt2+part3,continous_one[size])<<endl;
               }
               	else
               	{
               		cout<<max(continous_one[size],prt2)<<endl;
               	}

               
               
         }
                
                
            t--;
            }
}