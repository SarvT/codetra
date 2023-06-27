Not Worked
// int r = matrix.size(), c = matrix[0].size();
        // for(int i=0; i<r; i++){
        //     for(int j=0; j<c
        //     ; j++){
        //         if(target > matrix[i][j])
        //     }
        // }


Worked
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix.size();
        while(i<j && j>=0){
            if((matrix[i][j]) == target) return true;
            if((matrix[i][j]) > target) j--;
            else i++;
            
        }
        return false;
    }
};


Worked
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix.size()-1;
        if(j==0) return true;
        while(i<matrix.size()-1 && j>=0){
            if((matrix[i][j]) == target) return true;
            if((matrix[i][j]) > target) j--;
            else i++;
            
        }
        return false;
    }
};


Worked
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int i=matrix.size(), j=matrix[0].size();
        int l=0, h=(i*j)-1;
        while(l<=h){
            int mid = (l + (h - l) / 2);
            if((matrix[mid/j][mid%j]) == target) return true;
            if((matrix[mid/j][mid%j]) < target) l=mid+1;
            else h=mid-1;
            
        }
        return false;
    }
};
