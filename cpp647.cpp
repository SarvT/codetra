class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), sol = 0;
        s = "$" + s + "^";
        for (int i = 1; i <= n; i++) {
            int cnt=0;
            while (s[i - cnt] == s[i + cnt]) cnt++;
            sol+=cnt;
            cnt=0;
            while (s[i - cnt - 1] == s[i + cnt]) cnt++;
            sol+=cnt;
        }
        return sol;
    }
};
