class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0, h=0, ans=0, n=s.length(), cnt=0;
        while(l<n){
            cnt += abs(s[l]-t[l]);
            while(cnt>maxCost){
                cnt -= abs(s[h]-t[h]);
                h++;
            }
            ans = max(ans, l-h+1);
            l++;
        }
        return ans;
    }
};
