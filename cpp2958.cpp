class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, h = 0, n = nums.size(), maxi = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k)mp[nums[h++]]--;
            maxi=max(maxi,i-h+1);
        }
        return maxi;
    }
};
