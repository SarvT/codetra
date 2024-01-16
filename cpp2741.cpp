class Solution {
public:
    int specialPerm(vector<int>& nums) {
    int n = nums.size(), mod = 1000000007;
    unordered_map<long long, int> mp;

    function<int(int, int)> dfs = [&](int prev, int mask) {
        if (mask == (1 << n) - 1) return 1;
        long long key = (long long)prev << 20 | mask;
        if (mp.count(key)) return mp[key];

        int count = 0;
        for (int i = 0; i < n; i++)
            if (!(mask & (1 << i)) && (nums[i] % prev == 0 || prev % nums[i] == 0))count = (count + dfs(nums[i], mask | (1 << i))) % mod;
        return mp[key] = count;
    };

    return dfs(1, 0);
    }
};
