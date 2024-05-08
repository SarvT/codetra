class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> pairs;
        for(int i=0;i<n;i++)pairs.push_back({score[i],i});
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        vector<string> res(n);
        for(int i=0;i<n;i++) {
            if(i==0)res[pairs[i].second]="Gold Medal";
            else if(i==1)res[pairs[i].second]="Silver Medal";
            else if(i==2)res[pairs[i].second]="Bronze Medal";
            else res[pairs[i].second] = to_string(i+1);
        }
        return res;
    }
};
