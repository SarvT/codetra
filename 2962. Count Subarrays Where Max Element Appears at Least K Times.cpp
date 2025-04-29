class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = -1;
        for (int i = 0; i < nums.size(); ++i)maxi = nums[i] > maxi ? nums[i] : maxi;
        long ans = 0, curr = 0, l = 0, r = 0;
        for (; r < nums.size(); ++r) {
            curr += nums[r] == maxi ? 1 : 0;
            while (curr >= k)curr -= nums[l++] == maxi ? 1 : 0;
            ans += l;
        }
        return ans;
    }
};
