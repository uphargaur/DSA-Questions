#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
vector <int > getfactors(int n)
{
	vector <int > ans;
	ans.push_back(1);
	for (int i = 2; i < n; ++i)
	{
		if(n%i==0)
			{ans.push_back(i);}

	}
	ans.push_back(n);
	return ans;
}
int main() {
    
    int t;
    cin>>t;
    while (t>0)
            {
                int n ; cin>>n;
                map <char,int> mp;
                int max_weight=0;
                string word;cin>>word;
                for (int i = 0; i < n; ++i)
                {
                	mp[word[i]]++;
                }
                int max_frequency=0,max_repeat=0;
                map<int ,int > freq;
                for(auto x:mp)
                {
                	freq[x.second]++;
                }
                for(auto x:freq)
                {
                	int temp_weight=x.first*x.second;
                	if(temp_weight>max_weight)
                	{
                		max_weight=temp_weight;
                	}
                	if(x.second>=max_frequency)
                		{max_frequency=x.second;
                		max_repeat=x.first;}
                }
                vector <int > factors=getfactors(n);
                int min_distance=n+1;
                int ans_frequency;
                for (int i = 0; i < factors.size(); ++i)
                {
                	int temp_distance=factors[i]-max_weight;
                	if(temp_distance<0){temp_distance*=-1;}
                	if( min_distance>temp_distance)
                	{
                		min_distance=temp_distance;
                		ans_frequency=factors[i];
                		// cout<<factors[i];
                	}
                }
               cout<<max_weight<<" " <<min_distance<<" "<<ans_frequency<<endl;
                
                
            t--;
            }
}