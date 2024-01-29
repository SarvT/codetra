class Solution {
public:
    long long sumScores(string s) {
        vector<int>z(s.length(),0);
        long long int ans=0;
        int l=0, r=0;
        for(int i=1;i<s.length();i++){
            if(i<=r)z[i]=min((r-i+1),(z[i-l]));
            while(i+z[i]<s.length() && s[z[i]]==s[i+z[i]])z[i]++;
            if(r<i+z[i]-1){
                l=i;
                r=i+z[i]-1;
            }
            ans+=z[i];
        }
        ans+=s.length();
        return ans;
    }
};
