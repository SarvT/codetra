not worked --> TLE
class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int sumUp=0, sumDn=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++) sumUp+=matrix[i][j];
        }
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=i; j--) sumDn+=matrix[i][j];
        }
        
        return {sumDn, sumUp};
    }
};

worked --> optimal
class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int sumUp=0, sumDn=0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(j >= i) sumUp += matrix[i][j];
                if(j <= i) sumDn += matrix[i][j];
            }
        
        return {sumUp, sumDn};
    }
};
