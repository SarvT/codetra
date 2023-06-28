class Solution {
public:
    void rec(string s, vector<vector<string>>& res, vector<string>& p, int i){
        if(i == s.size()){
            res.emplace_back(p);
            return;
        }
        for(int j=i; j<s.size(); ++j){
            if(isPali(s, i, j)){
                p.push_back(s.substr(i, j-i+1));
                rec(s, res, p, j+1);
                p.pop_back();
            }
        }
    }

    bool isPali(string s, int f, int l){
        while(f<=l){
            if(s[f++]!=s[l--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        rec(s, res, p, 0);
        return res;
    }
};
