if(arr[0]==0) return -1;
        int n=arr.size();
        
        vector<int> dp(n,1e9);
        dp[0]=0;
        
        
        for(int ind=0;ind<n;ind++){
            if(arr[ind]==0) continue;
             
            for(int i=1;i<=arr[ind];i++){
               if((ind+i)>=n) break;
            dp[ind+i]=min(dp[ind+i],1 + dp[ind]);
        }
        }
        
        if(dp[n-1]==1e9) return -1;
        return dp[n-1];
