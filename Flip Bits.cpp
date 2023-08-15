class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int cntOnes=0, cntZeroes=0, maxi=0;
        
        for(int i=0; i<n; i++)
        {
            if(a[i] == 0) 
            {
                cntZeroes++;
                maxi = max(maxi, cntZeroes);
            }
            else
            {
                cntOnes++;
                cntZeroes--;
            }
            if(cntZeroes < 0) cntZeroes = 0;
        }
        return maxi + cntOnes;
    }
};
