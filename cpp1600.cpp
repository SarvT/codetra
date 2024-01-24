class ThroneInheritance {
public:
    map<string,map<string,int>> mp;
     int cnt=0;
     string str;
     map<string,int> mp1,mp2;
    ThroneInheritance(string kingName) {
        map<string,int> l;
        mp[kingName]=l;
        mp2[kingName]=cnt++;
        str=kingName;
    }
    
    void birth(string parentName, string childName) {
        map<string,int> q=mp[parentName];
        q[childName]++;
        mp[parentName]=q;
        mp2[childName]=cnt++;
    }
    
    void death(string name) {
        mp1[name]++;
    }
    void func(string parentName,vector<string> &vecStr)
    {
        vecStr.push_back(parentName);
        vector<pair<int,string>> vec;
        for(auto j : mp[parentName])vec.push_back({mp2[j.first],j.first});
         sort(vec.begin(),vec.end());
        for(auto i : vec) 
        func(i.second,vecStr);
    }
    vector<string> getInheritanceOrder() {
        vector<string> vecStr;
        func(str,vecStr);
         
        vector<string> ans;
        for(auto i : vecStr)
        if(mp1[i]==0)
        ans.push_back(i);

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
