class Solution {
public:
    int minDistance(string word1, string word2) {
        int m1 = word1.size();
        int m2 = word2.size();
        vector<vector<int>> dp(m1+1,vector<int>(m2+1,0));
        for(int i=0;i<=m1;++i){
            dp[i][0] = i;
        }
        for(int i=0;i<=m2;++i){
            dp[0][i] = i;
        }
        dp[0][0] = 0;
        for(int i=1;i<=m1;++i){
            for(int j=1;j<=m2;++j){
                if(word1[i-1]==word2[j-1]){dp[i][j] = dp[i-1][j-1];}
                else{dp[i][j] = 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});}
            }
        }
        return dp[m1][m2];
    }
};
