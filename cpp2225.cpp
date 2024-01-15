// worked
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>wMp, lMp;
        for(auto it:matches){
                wMp[it[0]]++;
                lMp[it[1]]++;
        }
        vector<int> vec1, vec2;
        for(auto it:wMp)if(lMp.find(it.first)==lMp.end()) vec1.emplace_back(it.first);
        for(auto it:lMp)if(it.second==1)vec2.emplace_back(it.first);
        return {vec1,vec2};
    }
};
