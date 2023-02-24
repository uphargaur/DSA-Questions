//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
    	int ans=0,flag=0;
        queue <pair<string,int>> q1;
       unordered_set<string> s1;
        for (int i = 0; i < wordList.size(); ++i)
        {
        	s1.insert(wordList[i]);
        	// cout<<wordList[i]<<endl;
        }
        // start larn rhe tha se
        q1.push({startWord,1});
        while(!q1.empty())
        {
        	if(flag==-1){break;}
        	auto x=q1.front();q1.pop();
        	
        	string str=x.first;int level=x.second;

        	if(str==targetWord)
		        		{
		        			ans=level;
		        			flag=-1;break;
		        		}
        	for (int i = 0; i < str.size(); ++i)
        	{
        		if(flag==-1){break;}
        		string temp_str =str;
        		for (char j = 'a'; j <='z' ; ++j)
		        	{
		        		
		        		temp_str[i]=j;
		        		if(s1.find(temp_str) != s1.end())
		        		{
		        			// level=level+1;
		        			s1.erase(temp_str);
		        			q1.push({temp_str,level+1});
		        			// cout<<temp_str<<endl;
		        		}
		        		
		        	}
        	}
        	

        }

        return ans; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends