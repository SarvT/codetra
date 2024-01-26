class Solution {
public:
    int func(int i , int j , int n , int m , int ma ,  vector<vector<vector<int>>> &dp ){
        long long mod = 1e9+7;
        int a, b, c, d;
        if(ma <0) return 0;
        if( i<0 || j<0 || i>=n || j>=m) return 1;
        if(dp[i][j][ma] !=-1) return dp[i][j][ma]; 
        a =  func(i+1 , j , n , m , ma-1 , dp);
        b =  func(i , j+1 , n , m , ma-1 , dp);
        c =  func(i-1 , j , n , m , ma-1 , dp);
        d =  func(i , j-1 , n , m , ma-1 , dp);
        return dp[i][j][ma] = ( (a%mod) +  (b%mod) +  (c%mod) + (d%mod)  )%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int> (maxMove+1, -1)));
        return func(startRow , startColumn , m , n ,maxMove , dp);
    }
};
