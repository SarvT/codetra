class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, int> mp(n, 0);
        int n=mat.size(), m=mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i[j]==1]) mp[i]++;
            }
        }
        vector<int> sol;
        // sort(mp.begin(), mp.end());
        // for(auto i:mp){
        // }
        for(int i=0; i<n; i++){
            if(k==0) break;
            sol.emplace_back();
        }
    }
};


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrengths;
        for (int i = 0; i < mat.size(); ++i) {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back({strength, i});
        }
        
        sort(rowStrengths.begin(), rowStrengths.end());
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowStrengths[i].second);
        }
        
        return result;
    }
};
