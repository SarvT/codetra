class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // paths[paths.size()-1][paths[0].size()-1]
        unordered_set<string> ust;
        for (int i = 0; i < paths.size(); i++) ust.insert(paths[i][0]);
        
        for (int i = 0; i < paths.size(); i++) {
            string s = paths[i][1];
            if (ust.find(s) == ust.end()) return s;
        }
        
        return "";
    }
};
