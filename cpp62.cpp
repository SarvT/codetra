class Solution {
public:
    int uniquePaths1(int i, int j, int m, int n) {
       if(i == m-1 && j == n-1) return 1; 
       if(i >= m || j >= n) return 0;
       return uniquePaths1(i+1, j, m, n)+uniquePaths1(i, j+1, m, n); 
    }
    int uniquePaths(int m, int n) {
       return uniquePaths1(0, 0, m, n); 
    }
};



class Solution {
public:
    int uniquePaths1(int i, int j, int m, int n, vector<vector<int>>& v) {
       if(i == m-1 && j == n-1) return 1; 
       if(i >= m || j >= n) return 0;
       
       if(v[i][j]!=-1) return v[i][j];
       else return v[i][j]=uniquePaths1(i+1, j, m, n, v)+uniquePaths1(i, j+1, m, n, v); 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m+1, vector<int>(n+1, -1));
        return uniquePaths1(0, 0, m, n, v); 
    }
};
