#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
                //sara game a ka hai
                int a,b,c,d;cin>>a>>b>>c>>d;
                if(a==0)cout<<1<<endl;
                else
                {int ans=0;
                    ans+=min(b,c)*2;
                    b-=ans/2;c-=ans/2;
                    //baki ka khel
                    //khushi khusi me sab hojaega
                    if(a>= b+c+d)
                    {
                        cout<<a+b+c+d+ans<<endl;
                    }
                    else
                    {
                        cout<<(a*2)+1+ans<<endl;
                    }
                    // cout<<ans<<endl;
                }
                                
            t--;
            }
}
