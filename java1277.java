//charm
class Solution {
    public int rec(int i, int j, int[][] matrix, int[][] dp){
        if(i >= matrix.length || j>=matrix[0].length) return 0;
        if(matrix[i][j] == 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int rht = rec(i, j+1, matrix, dp);
        int dia = rec(i+1, j+1, matrix, dp);
        int btm = rec(i+1, j, matrix, dp);

        return dp[i][j]=1+Math.min(rht, Math.min(dia, btm));
    }
    public int countSquares(int[][] matrix) {
        int sol=0;
        int [][]dp = new int[matrix.length][matrix[0].length];
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++)Arrays.fill(dp[i], -1);
        }
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++)sol+=rec(i, j, matrix, dp);
        }

        return sol;
    }
}
