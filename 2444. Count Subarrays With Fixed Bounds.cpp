class Solution {
public:
    int countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastMinIdx = -1, lastMaxIdx = -1, lastInvalidIdx = -1;
        long long res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) lastInvalidIdx = i;
            if (nums[i] == minK) lastMinIdx = i;
            if (nums[i] == maxK) lastMaxIdx = i;

            int validStart = min(lastMinIdx, lastMaxIdx);
            res += max(0, validStart - lastInvalidIdx);
        }

        return res;
    }
};
