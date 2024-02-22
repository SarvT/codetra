//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int []dp = new int[t.length() + 1];
      for(int j = 0 ; j < dp.length ; j++)dp[j] = 0;
      dp[0] = 1;
      int mod = (int)Math.pow(10, 9) + 7;
      for(int i = 0 ; i < s.length()  ; i++){
             int []curr = new int[t.length() + 1];
             curr[0] = 1;
            for(int j = 0 ; j < t.length()  ; j++){
                if(s.charAt(i) == t.charAt(j))curr[j + 1] = (int)(((long)dp[j + 1] + dp[j]) % mod);
                else curr[j + 1] = dp[j + 1];
            }
            dp = curr;
        }
        return dp[dp.length - 1];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
