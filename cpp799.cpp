// optimized working 
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> A(query_row + 2, 0.0);
        A[0] = static_cast<double>(poured);
        
        for (int r = 1; r <= query_row; ++r) {
            for (int c = r; c >= 0; --c) {
                double overflow = max(0.0, (A[c] - 1.0) / 2.0);
                A[c] = overflow;
                A[c + 1] += overflow;
            }
        }
        
        return min(1.0, A[query_glass]);
    }
};




// working
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> A(102, vector<double>(102, 0.0));
        A[0][0] = static_cast<double>(poured);
        
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                double q = (A[r][c] - 1.0) / 2.0;
                if (q > 0) {
                    A[r + 1][c] += q;
                    A[r + 1][c + 1] += q;
                }
            }
        }
        
        return min(1.0, A[query_row][query_glass]);
    }
};
