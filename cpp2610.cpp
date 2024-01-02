
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1);
        vector<vector<int>> ans;
        for (auto chr : nums) {
            if (freq[chr] >= ans.size()) ans.push_back({});
            ans[freq[chr]].push_back(chr);
            freq[chr]++;
        }
        
        return ans;
    }
};
