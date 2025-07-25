class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code
        int currMax = arr[0] , maxSum = arr[0], currMin = arr[0] , minSum = arr[0], totalSum = arr[0];
        int n = arr.length;
        for(int i=1;i<n;i++){
            currMax = Math.max(arr[i],currMax+arr[i]);
            maxSum = Math.max(maxSum,currMax);
            
            currMin = Math.min(arr[i],currMin+arr[i]);
            minSum = Math.min(minSum,currMin);
            
            totalSum += arr[i];
        }
        
        if(totalSum == minSum) return maxSum;
        else return Math.max(maxSum,totalSum-minSum);
    }
};
