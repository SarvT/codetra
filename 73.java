// tried
class Solution {
    public void setZeroes(int[][] matrix) {
        int[]  rows = new int[30];
        int[]  cols = new int[30];
        int x=0;
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                if(matrix[i][j]==0){
                    rows[x]=i;
                    cols[x]=j;
                    x++;
                }
            }
        }

        // while(){
            for(int i=0; i<matrix.length; i++){
                for(int k=0; k<matrix[0].length; k++){
                    matrix[k][cols[i]]=0;
                }
            }
            for(int i=0; i<matrix[0].length; i++){
                for(int k=0; k<matrix.length; k++){
                    matrix[k][cols[i]]=0;
                }
            }
        // }

        
        
    }
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr = false,fc = false;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) fr = true;
                    if(j == 0) fc = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
            }}
        }
        if(fr) {
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if(fc) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }

    }
};
