Leet
Not worked
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> rc;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix.size(); j++){
                if(matrix[i][j] == 0) rc[i]=j;
            }
        }
        for(auto it:rc){
            for(auto i=it->first; i<matrix.size(); i++){
                for(auto j=it->second; j<matrix.size(); j++){
                    matrix[i][j] == 0;
                }
        }   
        }
    }
};


Worked
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
