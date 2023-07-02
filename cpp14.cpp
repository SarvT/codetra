// Leet
// Not worked

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n<=1) return strs[0];
        string ans = "";
        int i=0;
        while(i<n){
            if(strs[0][i]!=strs[1][i])break;
            if(strs[0][i]==strs[1][i]){
                ans.push_back(strs[1][i]);
            }
            i++;
        }

        for(int i=2;i<n; i++){
            if((strs[i].find(ans, 0, strs[i].size()) != 0)) return "";
        }
        return ans;
    }
};


// Worked
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n<=1) return strs[0];
        sort(strs.begin(), strs.end());
        string ans = "";
        string f=strs[0], l=strs[n-1];

        for(int i=0;i<min(f.size(), l.size()); i++){
            if(f[i]!=l[i]) return ans;
            ans += f[i];
        }
        return ans;
    }
};
