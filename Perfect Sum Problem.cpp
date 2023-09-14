class Solution{

	public:
	int mod=1e9+7;
	int clas(int arr[], int n, int sum, int level, vector<vector<int>> &dp){
	    if (level==n) return sum==0;
	    if (dp[level][sum]!=-1) return dp[level][sum];
	    
	    int take=0;
	    
	    for(int i=level; i<n; i++){
	        if(sum>=arr[i]) take+=clas(arr, n, sum-arr[i], i+1, dp);
	        
	    }
	    return dp[level][sum] = take%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return clas(arr, n, sum, 0, dp);
        
	}
	  
};

// worked
class Solution{

	public:
	int mod=1e9+7;
	int countsub(int arr[], int n, int sum,vector<vector<int>>&dp){
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(n==0 && sum>0) return 0;
        if(n==1){
            if(sum==0){
                if(arr[0]==0) return 2;
                else return 1;
            }
            else {
                if(arr[0]==sum) return 1;
                else return 0;
            }
        }
        else if(n==0 && sum==0) return 1;
        int ans=countsub(arr,n-1,sum,dp)%mod;
        if(arr[n-1]<=sum){
            ans+=countsub(arr,n-1,sum-arr[n-1],dp);
            ans%=mod;
        }
        return dp[n][sum]=ans;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return countsub(arr,n,sum,dp)%mod;
        
	}
	  
};
