// not worked
class Solution
{
    public:
    int maxi=0;
    void tnt(int arr[], int n, int l, int m, int maxi){
        if(l>=n-1){
            maxi = max(m, maxi);
            return;
        }
        for(int i=l; i<n; i+2){
            maxi+=arr[i];
            tnt(arr, n, i, m, maxi);
            maxi-=arr[i];
            
        }
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        tnt(arr, n, 0, 0, maxi);
        return maxi;
    }
};


// worked
class Solution
{
    public:
    int tnt(int i, int arr[], vector<int>&dp){
        if(i==0) return arr[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=arr[i]+tnt(i-2, arr, dp);
        int ntake=tnt(i-1, arr, dp);
        return dp[i]=max(take, ntake);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n, -1);
        return tnt(n-1, arr, dp);
    }
};
