class Solution {
public:
    vector<string> a = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
    int n;
    void rec(int i, string &digits, string &s){
        if( i == n){
            ans.push_back(s);
            return;
        }
        int digit = digits[i] - '0';
        for(char c: a[digit]){
            s.push_back(c);
            rec(i+1, digits, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        n = digits.size();
        string s;
        rec(0, digits, s);
        return ans;
    }
};
