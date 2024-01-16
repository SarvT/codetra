class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> trace;
        multiset<int> mst;
        vector<vector<int>> res;
		
        for (auto it : buildings) {
            trace.push_back({it[0], -it[2]});
            trace.push_back({it[1], it[2]});
        }
        sort(trace.begin(), trace.end());
        int prev = 0, cur = 0;
        
        
        mst.insert(0);
        for (auto i:trace) {
            if (i.second < 0) mst.insert(-i.second);
            else mst.erase(mst.find(i.second)); 
            
            cur = *mst.rbegin();
            if (cur != prev) {
                res.push_back({i.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};
