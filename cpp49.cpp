// worked
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& word : strs) {
            string it = word;
            sort(it.begin(), it.end());

            if (mp.find(it) == mp.end()) mp[it] = {word};
            else mp[it].push_back(word);
        }
        vector<vector<string>> vec;
        for (const auto& group : mp) vec.push_back(group.second);

        return vec;
    }
};
