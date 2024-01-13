class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0}, ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']--;
            count[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) ans += max(0, count[i]);
        
        return ans;
    }
};
