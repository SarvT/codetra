int LCS(string &s,string &s1, int n,int m)
  {
    // int dp[1001][1001]={0};
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int i=1;i<n+1;i++)
      {
          for(int j=0;j<n+1;j++)
          {
              if(s[i-1]==s1[j-1])
              {
                 dp[i][j]=1+dp[i-1][j-1];
              }
              else
              {
                  dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
              }
          }
      }
      return dp[n][n];
  }
    int minimumNumberOfDeletions(string s) { 
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.length();
       int len=LCS(s,s1,n,n);
       return n-len;
       
    } 
