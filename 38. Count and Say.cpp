class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        int ct=1;
        string ans="";
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) ct++;
            else{
                ans+=to_string(ct);
                ans+=s[i-1];
                ct=1;
            }
        }
        ans+=to_string(ct);
        ans+=s[s.size()-1];
        return ans;
    }
};
