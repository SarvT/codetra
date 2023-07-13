// gfg

bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[arr[i]]++;
        vector<int> ans(n,0);
        for(auto it :mpp){
            ans[it.second]++;
        }
        
        for(int i=0;i<n;i++){
            if(ans[i]>1) return false;
        }
        return true;
    }
