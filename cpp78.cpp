// Leet
// Worked
class Solution {
public:
    void traverse(vector<int>& nums, vector<vector<int>>& sol, vector<int>& v1, int i){
        if(i >= nums.size()){
            sol.emplace_back(v1);
            return;
        }
        v1.emplace_back(nums[i]);
        // if(tnt==0) v1.pop_back();
        traverse(nums, sol, v1, i+1);
        v1.pop_back();
        traverse(nums, sol, v1, i+1);
        // for(int j=i; j<nums.size(); j++){

        // }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> v1;
        traverse(nums, sol, v1, 0);
        return sol;
    }
};
