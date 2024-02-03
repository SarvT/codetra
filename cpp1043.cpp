class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size(), maxSum=INT_MIN;
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int length=0, sum=0, maxElement=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                length++;
                maxElement=max(maxElement,arr[j]);
                sum=(length*maxElement)+dp[j+1];
                maxSum=max(sum, maxSum);
                dp[i]=maxSum;
             }
        }

    return dp[0];
    }
};
