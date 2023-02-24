//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        //minimum queue bana leta hu
        vector <int > distance(100000,1e9);

        queue <pair<int,int>> q1;
        q1.push({start,0});
        while(!q1.empty())
        {
            auto it =q1.front();q1.pop();
            int curr_steps=it.second;
            int curr_no=it.first;
            // cout<<curr_no<<endl;

            if(curr_no==end)
            {
                return curr_steps;
                break;
            }
            for (int i = 0; i < arr.size(); ++i)
            {
                int new_no=curr_no*arr[i];
                new_no%=100000;
                if(curr_steps+1 <distance[new_no])
                {
                    q1.push({new_no,curr_steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends