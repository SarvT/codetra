// Leet
// Worked

class Solution {
public:
    
    void rec(vector<int>& candidates, vector<int> ans, int target, int sum, int i, int n, vector<vector<int>> &res){


        // if(sum>target) return;
        if(sum == target){
            res.emplace_back(ans);
            return;
        }
        for(int j=i; j<n; j++){
            if(j != i && candidates[j] == candidates[j-1]) continue;
            if(sum + candidates[j] > target) break;
            ans.emplace_back(candidates[j]);
            sum+=candidates[j];
            rec(candidates, ans, target, sum, j+1, n, res);
            ans.pop_back();
            sum-=candidates[j];
            // rec(candidates, ans, target, sum, i+1, n, res);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> vis = {0};
        vector<int> ans;
        vector<vector<int>> res;
        rec(candidates, ans, target, 0, 0, n, res);
        // vector<vector<int>> res1=res;

        return res;
    }
};
