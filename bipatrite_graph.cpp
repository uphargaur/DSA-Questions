//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int> color(V+1,-1);
	   queue<int> q1;
	   for (int i = 0; i < V; ++i)
	   {
	   	if(color[i]==-1)
	   	{
		   	q1.push(i);
		   	color[i]=0;
		    while(!q1.empty())
		    {
		    	int temp =q1.front();q1.pop();
		    	int temp_color= color[temp];
		    	for (auto x: adj[temp])
		    	{
		    		if(color[x]==temp_color)
		    		{
		    			return false;

		    		}
		    		if(color[x]==-1)
		    		{
		    			if(temp_color==1)
		    			{
		    				color[x]=0;
		    				q1.push(x);
		    			}
		    			if(temp_color==0)
		    			{
		    				color[x]=1;
		    				q1.push(x);
		    			}
		    		}
		    	}
		    } 
		   
	   	 }
	   }
	    for(auto y:color)
		    {
		    	cout<<y<<" ";
		    }cout<<endl;
	   return true;
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends