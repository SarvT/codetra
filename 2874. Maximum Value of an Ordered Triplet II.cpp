class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, maxii = 0, maxi = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, maxi * nums[k]);
            maxi = max(maxi, maxii - nums[k]);
            maxii = max(maxii, static_cast<long long>(nums[k]));
        }
        return res;
    }
};
