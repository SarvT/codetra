//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int y=0, z=n-1, cnt=0, i=0, j=n-1;
	    while(y<n&&z>=0){
	        int sum = mat1[y][i]+mat2[z][j];
	        if(sum==x){
	            cnt++;
	            i++;
	            j--;
	        }
	        else if(sum>x) j--;
	        else if(sum<x) i++;
	        if(i>n-1){
	            y++;
	            i=0;
	        }
	        if(j<0){
	            z--;
	            j=n-1;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends
