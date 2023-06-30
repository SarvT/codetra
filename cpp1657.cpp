class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp1, mp2;
        vector<int> v1, v2;
        if(word1.size()==word2.size())
        {
            for(auto it:word1) mp1[it]++; 
             for(auto it:word2) mp2[it]++;
            for(int i=0;i<word2.size();i++)
            {
             if (word2.find(word1[i]) != std::string::npos) v1.push_back(mp1[word1[i]]);
            else return false;
                 if (word1.find(word2[i]) != std::string::npos) v2.push_back(mp2[word2[i]]);
    
                else return false;
            
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            if(v1==v2)return true;
            else return false;
        }
        else return false;
    }
};
