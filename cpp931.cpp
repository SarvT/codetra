incomplete solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(), mini, cnt;
        for(int i=0; i<n; i++){
            int mini = min(matrix[0][i], mini);
        }
        for(int i=0; i<n; i++){
            int min2 = min
            cnt+=
        }
    }
};

complete worked
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int j=0;j<n; j++)dp[n-1][j]=matrix[n-1][j];

        for (int i=n-2;i>=0;i--){
            for (int j=0;j<n;j++){
                int up = dp[i+1][j];
                int left_diagonal = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right_diagonal = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up,left_diagonal,right_diagonal});
            }
        }

        int result=INT_MAX;
        for (int j=0;j<n;j++)result=min(result,dp[0][j]);

    return result;
    }
};
