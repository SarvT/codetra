class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0,a prefixZeros = 0, currentSum = 0, totalCount = 0;
        
        for (int end = 0; end < nums.size(); ++end) {
            currentSum += nums[end];
            
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) prefixZeros = 0;
                else prefixZeros += 1;
                
                currentSum -= nums[start];
                start += 1;
            }
            if (currentSum == goal) totalCount += 1 + prefixZeros;
        }
        
        return totalCount;
    }
};
