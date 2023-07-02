// Leet
// Not worked




// Worked
bool checkValid(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ct = 0, sm=INT_MIN;
        sort(intervals.begin(), intervals.end(),  checkValid);
        
        for(int i=0; i<intervals.size(); i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(a>=sm) sm=b;
            else ct++;
        }
        return ct;
    }
};
