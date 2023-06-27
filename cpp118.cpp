// Leet
// Not worked
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numRows; i++){
                if(j>2){
                    if(j>0 && j<i){
                        ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
                    }
                }
            }
        }
        return ans;
    }
};

// Worked
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j=1; j<i; j++) ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
        }
        return ans;
    }
};
