not worked
class Solution {
  public:
    vector<long long> dp;
    int rec(int n){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n]=(nthFibonacci(n-1)+nthFibonacci(n-2))%1000000007;
        return dp[n];
    }
    int nthFibonacci(int n){
        // code here
        dp.assign(n+1,-1);
        return rec(n);
    }
};



worked
class Solution {
  public:
    const int MOD = 1000000007;
    vector<long long> memo;
    long long fibonacci(int n) 
    {
        if (n <= 1) 
        {
        return n;
        }

        if (memo[n] != -1) 
        {
            return memo[n];
        }

        memo[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % MOD;
        return memo[n];
    }
    int nthFibonacci(int n){
        // code here
        memo.assign(n+1,-1);
        return fibonacci(n);
    }
};
