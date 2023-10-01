not worked
class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        // for(int i=0; i<i+1; i++){
        //     for(int j=0; j<m; j++){
        //         ans.emplace_back(matrix[i][j])
        //     }
        // }
        vector<int>ans;
        int i=1, j=0;
        while(j<m) ans.emplace_back(matrix[0][j++]);
        while(i<n) ans.emplace_back(matrix[i++][m-1]);
        j=m-2;
        while(j>=0) ans.emplace_back(matrix[n-1][j--]);
        i=n-2;
        while(i>=1) ans.emplace_back(matrix[i--][0]);
        return ans;
    }
};

worked
class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int>ans;
        
        for(int i = 0; i<m; i++) ans.push_back(matrix[0][i]);
        if(n == 1) return ans;
        
        for(int i = 1; i<n; i++)ans.push_back(matrix[i][m-1]);
        if(m == 1) return ans;
        
        for(int i = m-2; i>=0; i-- )ans.push_back(matrix[n-1][i]);
        
        for(int i = n-2; i>=1; i--)ans.push_back(matrix[i][0]);
        
        return ans;
    }
};
