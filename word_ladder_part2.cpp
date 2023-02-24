//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue <vector <string> > q1;
        set <string> s1;
        for (auto x: wordList)
        {
        	s1.insert(x);
        }
        vector <string> v1;
        v1.push_back(beginWord);
        s1.erase(beginWord);
        q1.push(v1); 
        int level=0;
        vector<string> level_pushed;
        while(!q1.empty())
	        {
	        	auto temp = q1.front();q1.pop();
	        	string word = temp.back();
	        	if(temp.size()>level)
	        	{
	        		level++;
	        		for(auto x: level_pushed)
	        		{s1.erase(x); }
	        		level_pushed.clear();
	        	}
	        	if(word==endWord)
	        	{
	        		ans.push_back(temp);
	        	}
	        	for (int i = 0; i < word.length(); ++i)
	        	{
	        		char original =word[i];

	        		for( char j = 'a'; j<= 'z'; j++)
	        		{
	        			word[i]=j;
	        			if(s1.count(word) > 0)
	        			{
	        				// cout<<word<<endl;
	        				temp.push_back(word);
	        				q1.push(temp);
	        				level_pushed.push_back(word);
	        				temp.pop_back();
	        			}

	        		}
	        		word[i]=original;
	        		
	        	}
	        	

	        }

	        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends