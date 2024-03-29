class Solution {
public:
    int minimumLength(string s) {
        int i =0, j = s.size()-1;
        while(i<j){
            if(s[i] == s[j]){
                char ch = s[i];
                while(i<s.size() && s[i] == ch)i++;
                while(j>=0 && s[j] == ch)j--;
            }
            else return (j-i+1);
        }
        return j-i == 0 ? 1 : 0;
    }
};
