// Leet
// Not worked
class Solution {
public:
    
    void rec(vector<int>& candidates, vector<int>& ans, int target, int sum, int i, int n, vector<vector<int>> &res){
        // if(i<=n){
        //     return;
        // }
        if(sum>target) return;
        // sum+=candidates[i];
        if(sum == target){
            res.push_back(ans);
            return;
        }
        ans.push_back(candidates[i]);
        rec(candidates, ans, target, sum, i+1, n, res);
        sum-=candidates[i];
        ans.pop_back();
        // ans.push_back(candidates[i]);
        rec(candidates, ans, target, sum, i, n, res);
        // ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size()-1;
        vector<int> ans;
        vector<vector<int>> res;
        rec(candidates, ans, target, 0, 0, n, res);
        return res;
    }

// Worked
class Solution {
public:
    
    void rec(vector<int>& candidates, vector<int> ans, int target, int sum, int i, int n, vector<vector<int>> &res){
        // if(i<=n){
        //     return;
        // }
        if(sum>target) return;
        if(sum == target){
            res.push_back(ans);
            return;
        }

        for(int j=i; j<n; j++){
            ans.push_back(candidates[j]);
            sum+=candidates[j];
            rec(candidates, ans, target, sum, j, n, res);
            ans.pop_back();
            sum-=candidates[j];

        }
        // ans.push_back(candidates[i]);
        // rec(candidates, ans, target, sum, i, n, res);
        // ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ans;
        vector<vector<int>> res;
        rec(candidates, ans, target, 0, 0, n, res);
        return res;
    }
};
};
