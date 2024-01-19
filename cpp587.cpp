class Solution {
public:
int cross(vector<int>& a, vector<int>& b, vector<int>& c){
        return (c[0]-a[0])*(b[1]-a[1]) - (b[0]-a[0])*(c[1]-a[1]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> top, down;
        for(auto t : trees){
            while(top.size()>=2 && cross(top[top.size()-2], top.back(), t) > 0)top.pop_back();
            top.push_back(t);
            while(down.size()>=2 && cross(down[down.size()-2], down.back(), t) < 0)down.pop_back();
            down.push_back(t);
        }
        top.insert(top.end(), down.begin(), down.end());
        // again a recheck
        set<vector<int>> set(top.begin(), top.end());
        // learnt about a new method
        return vector<vector<int>>(set.begin(), set.end());
    }
};
