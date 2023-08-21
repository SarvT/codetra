class Solution {
public:
int validate(vector<vector<int> >& matrix,int i,int j,int n,int m){
        int c=0;
        for(int k=i-1;k<i+2;k++){
            for(int l=j-1;l<j+2;l++){
                if(k>=0&&k<n&&l>=0&&l<m&&matrix[k][l]==0)
                    c++;
            }
        }
        return c;
        
    }
    int Count(vector<vector<int> >& matrix) {
        // Code here
         int c,d=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                c=1;
                if(matrix[i][j]==1)
                    c=validate(matrix,i,j,n,m);
                if(!(c%2)&&c!=0)
                    d++;
            }
        }
        return d;
    }
};
