
class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here
        int sum[n]={0};
        int colsum[n]={0};
        int temp=0;
        for(int i=0;i<n;i++)
        {
         for(int j=0;j<n;j++)
         {
            sum[i] += matrix[i][j];
            colsum[i] += matrix[j][i];
         }
         if(temp<colsum[i] || temp<sum[i])
         {
          temp=max(colsum[i],sum[i]);  
         }
        }
       
        int ans=0;
        for(int i=0;i<n;i++)
        {
          ans+=temp-colsum[i];
        }
        return ans;
    } 
};
