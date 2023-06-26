// Leet
// Not worked
class Solution {
public:
    void rec(vector<int>& nums, vector<vector<int>>& sol, vector<int> v1, vector<int> v1, int index, int level){
        if(index == nums.size()-1){
            sol.emplace_back(v1);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            if()
        v1.emplace_back(nums[index]);
        rec(nums, sol, v1, i, level+1);
        v1.pop();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> v1;
        vector<int> vis(nums.size(), 0);
        rec(nums, sol, v1, vis, 0, 0);
        return sol;
    }
};

// Worked
class Solution {
public:
    void rec(vector<int>& nums, vector<vector<int>>& sol, vector<int> v1){
        if(v1.size() == nums.size()){
            sol.emplace_back(v1);
            return;
        } 
        for(int i: nums){
            if(find(v1.begin(), v1.end(), i)==v1.end()){
                v1.emplace_back(i);
                rec(nums, sol, v1);
                v1.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> v1;
        rec(nums, sol, v1);
        return sol;
    }
};
