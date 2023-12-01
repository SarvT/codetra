// worked
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(string s:word1){
            for(char c:s)s1.push_back(c);
        }
        for(string s:word2){
            for(char c:s)s2.push_back(c);
        }
        if(s1==s2) return true;
        return false;
    }
};

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(string s:word1)s1+=s;
        for(string s:word2)s2+=s;
        if(s1==s2) return true;
        return false;
    }
};
