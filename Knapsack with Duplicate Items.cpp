class Solution{
public:
int fn(int ind,int N, int W, int val[], int wt[],vector<vector<int>>& dp){
        if(ind ==N){
            // if(W>=wt[ind]){
            //     return val[ind];
            // }
            return 0 ;
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W] ;
        }
        int t=-1,nt=0 ;
        nt = 0+fn(ind+1,N,W,val,wt,dp);
        if(W>=wt[ind]){
            t = val[ind] + fn(ind,N,W-wt[ind],val,wt,dp);
        }
        
        return dp[ind][W] = max(t,nt);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return fn(0,N,W,val,wt,dp);

    }
};
