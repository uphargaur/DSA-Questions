//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){

		int n=matrix.size();
			for (int j = 0; j < n; ++j)
				{
					for (int i = 0; i < n; ++i)
					{
						if(matrix[i][j]==-1)
							matrix[i][j]=1e8;
					
					}
					
				}
		//kisse traversal start kar rhe mtlb via whom
		for (int k = 0; k < n; ++k)
		{
			//now i will find the distance of each array via i
			//let us suppose distacnce is calculated from j to i
				for (int j = 0; j < n; ++j)
				{
					for (int i = 0; i < n; ++i)
					{
						int weight_via_i =matrix[i][k]+matrix[k][j];
						if(matrix[i][j]>weight_via_i)
						{
							matrix[i][j]=weight_via_i;
						}
					}
					
				}
		}
		//
		for (int j = 0; j < n; ++j)
				{
					for (int i = 0; i < n; ++i)
					{
							if(matrix[i][j]==1e8)
							matrix[i][j]=-1;
					
					}
					
				}

	    

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends