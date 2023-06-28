class Solution {
public:
    void rec(vector<int>& nums, vector<int>& v, vector<vector<int>>& sol, int i){
        sol.emplace_back(v);
        for(int k=i; k<nums.size(); k++){
            if(k!=i && nums[k]==nums[k-1]) continue;
            v.emplace_back(nums[k]);
            rec(nums, v, sol, k+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> v;
        sort(nums.begin(), nums.end());
        rec(nums, v, sol, 0);
        return sol;
    }
};
