class Solution {
public:
    vector<int> ans;
    void addBoundary(int firstRow, int lastRow, int firstCol, int lastCol, vector<vector<int>>& a){
        for(int j=firstCol; j<lastCol; j++) ans.push_back(a[firstRow][j]);
        for(int i=firstRow; i<lastRow; i++) ans.push_back(a[i][lastCol]);
    
            for(int j=lastCol; j>firstCol; j--) ans.push_back(a[lastRow][j]);

            for(int i=lastRow; i>firstRow; i--) ans.push_back(a[i][firstCol]);
    }
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int firstRow=0, lastRow=n-1, firstCol=0, lastCol=m-1;
        while(firstRow<lastRow && firstCol<lastCol){
            addBoundary(firstRow++, lastRow--, firstCol++, lastCol--, a);
        }
        cout<<firstRow<<"\n"<<lastRow<<"\n"<<firstCol<<"\n"<<lastCol<<"\n";
        if (firstRow>lastRow || firstCol>lastCol){
            cout<<"case 1";
            return ans;
        }         
        if ( firstRow==lastRow && firstCol<=lastCol){
            for(int j=firstCol; j<=lastCol; j++) ans.push_back(a[firstRow][j]);
            cout<<"case 2";
        } 
            
        else if ( firstCol==lastCol && firstRow<=lastRow ){
            for(int i=firstRow; i<=lastRow; i++) ans.push_back(a[i][lastCol]);
            cout<<"case 3";
        }
           
        return ans;
    }
};
