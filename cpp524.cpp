class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<char,vector<int>> mp;
        int n = s.length();
        for(int i=0;i<n;i++)mp[s[i]].push_back(i);
        string ans = "";
        for(int i=0;i<dictionary.size();i++){
            int h = -1, cnt = 0;
            for(int j=0;j<dictionary[i].size();j++){
                vector<int> vec = mp[dictionary[i][j]];
                int it = lower_bound(vec.begin(),vec.end(),h) - vec.begin();
                if(it==vec.size()){
                    cnt++;
                    break;
                }
                if(vec[it]==h)it++;
                if(it==vec.size()){
                    cnt++;
                    break;
                }
                h = vec[it];
            }
            if(cnt==0){
                if(dictionary[i].size()>=ans.size()){
                    if(dictionary[i].size()>ans.size()) ans = dictionary[i];
                    else if(dictionary[i]<ans) ans = dictionary[i];
                }
            }
        }
        return ans;
    }
};
