unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=-1;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==k) ans=max(ans,(j-i+1));
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(mp.find(s[i]));
                }
                i++;
            }
            j++;
        }
        return ans;
