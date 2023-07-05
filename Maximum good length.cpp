You are given a matrix A of size N*M. Any length 'L' can be called good length if there is at least one square matrix of size L*L in A such that all elements in that square matrix are greater than or equal to L. You need to output the maximum good length for given matrix.

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
    public:
        int maxGoodLength(vector<vector<int>>&a)
        {
            // Write your code here.
            int maxGoodLength = 0;
            int N = a.size();
            int M = a[0].size();
            
            int length = min(N, M);
            int currentLength = length+i;
            for (int i = 0; i < currentLength; i++) {
                for (int j = 0; j < currentLength; j++) {
                    currentLength = length+i;
                    
                   if(a[i][j]<currentLength){
                        i++;
                        j++;
                        currentLength = length+i;
                   } else {
a[i][j]<currentLength
                }
            }
        
            return maxGoodLength;
}

};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,i,j;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        int ans=ob.maxGoodLength(a);
        cout<<ans<<endl;
    }
}

// } Driver Code Ends
