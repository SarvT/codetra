class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> ans;
        vector<int> vec[n+1];
        for(int i=0; i<n; i++){
            vec[groupSizes[i]].emplace_back(i);
            if(vec[groupSizes[i]].size() == groupSizes[i]){
                ans.emplace_back(vec[groupSizes[i]]);
                vec[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};
