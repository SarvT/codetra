class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0, n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.') continue;
              // important as it checks previous place --> no adjancency
                if((i>0 && board[i-1][j]=='X') || (j>0 && board[i][j-1]=='X')) continue;
                cnt++;
            }
        }
        return cnt;
    }
};
