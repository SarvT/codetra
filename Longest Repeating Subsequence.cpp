int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    vector<int> dp(n+1, 0);
		    vector<int> prv(n+1, 0);
		    for(int i=1; i<=n; i++){
		        for(int j=1; j<=n; j++){
		            if(str[i-1] == str[j-1] && i!=j) dp[j] = 1+prv[j-1];
		            else dp[j] = max(dp[j-1], prv[j]);
		        }
		        prv = dp;
		    }
		    return dp[n];
		}
