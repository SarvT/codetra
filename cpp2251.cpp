// not worked
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        unordered_map<int, int>mp;
        
        for(auto it:flowers){
            for(int i=0; i<2; i++){
                mp[it[i]]++;
            }

        }
        for(int i=0; i<people.size(); i++){
            ans.emplace_back(mp[people[i]]);
        }
    }
};



// worked
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        
        for (vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;


        Initialize the answer array ans and iterate over each person in people:
        Perform a binary search on starts for the rightmost insertion index of person to find i.
        Perform a binary search on ends for the rightmost insertion index of person to find j.
            
        for (int person : people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i - j);
        }
        
        return ans;
    }
};
