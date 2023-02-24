
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    map <string ,int> mpp;
    private :
     void dfs()
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector <vector<string>> ans;
        queue <string > q1;
        set <string> s1(wordList.begin(),wordList.end());
        q1.push(beginWord);
        //level ki baat karllewte hai 
        mpp[beginWord]=1;
        s1.erase(beginWord);
        while(!q1.empty())
        {

            string word =q1.front();
            q1.pop();
            int level= mpp[word];

            for (int i = 0; i < word.length(); ++i)
                {
                    char original =word[i];

                    for( char j = 'a'; j<= 'z'; j++)
                    {
                        word[i]=j;
                        if(s1.count(word) > 0)
                        {
                            // cout<<word<<endl;
                            // temp.push_back(word);
                            q1.push(word);
                            mpp[word]=level+1;
                            s1.erase(word);
                        }

                    }
                    word[i]=original;
                    
                }

        }
         for(auto x : mpp)
                {
                    cout<<x.first<<" "<<x.second<<endl;
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
        vector<vector<string>> ans = obj.findLadders(startWord, targetWord, wordList);
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