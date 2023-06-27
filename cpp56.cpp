class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        vecctor<int> v1;
        for(auto i: intervals){
            if(intervals[1] >= intervals[0])

            intervals[0]
            intervals[1]
            else sol.emplace_back(i);
            v1.clear();
            v1 = i;
        }
    }
};


// Worked
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        sort(intervals.begin(), intervals.end()); //dependent
        vector<int> tmp = intervals[0];

        for(auto i: intervals){
            if(i[0] <= tmp[1]) tmp[1] = max(i[1], tmp[1]);
            else {
                sol.emplace_back(tmp);
                tmp = i;
            }
        }
        sol.emplace_back(tmp);
        return sol;
    }
};
