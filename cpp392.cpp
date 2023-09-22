class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        int i=0, j=i;
        while(i<t.length()){
            if(s[j] == t[i]){
                j++;
            }
            i++;
            if(j >= s.length()) return true;
        }
        return false;
    }
};
