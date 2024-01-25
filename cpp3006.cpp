class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(s.size()<a.size()||s.size()<b.size())return { };
        vector<int>veca,vecb;
        for(int i=0;i<=s.size()-a.size();i++){
            if(s.substr(i,a.size())==a)veca.push_back(i);
        }
        for(int i=0;i<=s.size()-b.size();i++){
            if(s.substr(i,b.size())==b)vecb.push_back(i);
        }
        vector<int>res;
         for(auto it:veca){
             auto i=lower_bound(vecb.begin(),vecb.end(),it-k);
             if(i!=vecb.end()&&abs(*i-it)<=k)res.push_back(it);
         }
       return res;
    }
};
