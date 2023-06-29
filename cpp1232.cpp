class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        for(int i=0; i<coordinates.size()-1; i++){
            for(int j=0; j<coordinates[0].size()-1; j++){
                if(coordinates[i][j]+1 != (coordinates[i+1][j])) return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    int getYDiff(vector<int>& a, vector<int>& b) {
        return a[1] - b[1];
    }
    int getXDiff(vector<int>& a, vector<int>& b) {
        return a[0] - b[0];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dY = getYDiff(coordinates[1], coordinates[0]);
        int dX = getXDiff(coordinates[1], coordinates[0]);
        for(int i=2; i<coordinates.size(); i++){
            if(dY*getXDiff(coordinates[i], coordinates[0]) != 
            dX*getYDiff(coordinates[i], coordinates[0])) return false;
        }
        return true;
    }
};
