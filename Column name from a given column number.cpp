worked
string ans;
        while(n){
            int c=(n-1)%26;
            ans.push_back(char('A'+c));
            n=(n-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;

