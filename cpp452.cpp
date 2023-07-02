// Leet
// Not worked
bool comparei(vector<int>& a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int cnt=0, ans=INT_MIN;
        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            if(x>=ans)ans=y; 
            else cnt++;
        }
        return cnt;
    }
};

// Worked
bool comparei(vector<int>& a, vector<int>&b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comparei);
        int n = points.size();
        int cnt=0, ans=INT_MIN;
        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            if(x>ans){
            ans=y; 
            cnt++;
            }
            else ans=min(ans, y);
        }
        return cnt;
    }
};






bool comparei(vector<int>& a, vector<int>&b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=1) return 1;
        sort(points.begin(), points.end(), comparei);
        int cnt=1, ans=points[0][1];
        for(int i=1; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            if(x>ans){
            ans=y; 
            cnt++;
            }
            else ans=min(ans, y);
        }
        return cnt;
    }
};
