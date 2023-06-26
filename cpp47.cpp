// Leet
// Worked
class Solution {
public:
    void rec(vector<int>& nums, vector<vector<int>>& sol, vector<int> v1, vector<int> v2){
        if(v1.size() == nums.size()){
            if(find(sol.begin(), sol.end(), v2) == sol.end())
                sol.emplace_back(v2);
            return;
        } 
        for(int i=0; i<nums.size(); i++){
            if(find(v1.begin(), v1.end(), i)==v1.end()){
                v1.emplace_back(i);
                v2.emplace_back(nums[i]);
                rec(nums, sol, v1, v2);
                v1.pop_back();
                v2.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> v1;
        vector<int> v2;
        rec(nums, sol, v1, v2);
        return sol;
    }
};
