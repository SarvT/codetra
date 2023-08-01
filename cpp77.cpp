// leet
// worked
class Solution {
public:
    void rec(int n, int k, int l, vector<int>& v,vector<vector<int>>& res){
        if(v.size()==k){
            res.emplace_back(v);
            return;
        }
        for(int i=l; i<=n; i++){
            v.emplace_back(i);
            rec(n, k, i+1, v, res);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v1;
        vector<vector<int>> sol;
        rec(n, k, 1, v1, sol);
        return sol;
    }
};
