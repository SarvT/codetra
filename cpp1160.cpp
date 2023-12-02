// not worked
// i thought about an approach after sorting everything we will check in the vector if it contains the items or not
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        sort(chars.begin(), chars.end());
        for(auto it:words) sort(it.begin(), it.end());
        vector<string> s;
        s.emplace_back("");
        for(int i=1; i<chars.size();i++){
            s.emplace_back(s[i-1]+s[i]);
        }
        int cnt=0;
        for(auto it:words){
            if(count(s.begin(), s.end(), it)) cnt++;
        }
        return cnt;
    }
};


// worked
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26, 0);
        for (char c : chars) counts[c - 'a']++;
        
        int ans = 0;
        for (string word : words) {
            vector<int> wordCount(26, 0);
            for (char c : word) wordCount[c - 'a']++;
            
            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (counts[i] < wordCount[i]) {
                    good = false;
                    break;
                }
            }
            
            if (good) ans += word.size();
        }
        
        return ans;
    }
};
