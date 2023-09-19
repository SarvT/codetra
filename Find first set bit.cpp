class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        if(n==0)return 0;
        int cnt=1;
        for(int i=0; i<n; i++){
            if(n&1<<i) return cnt;
            else cnt++;
        }
        return cnt;
    }
};


// this is from internet but still my approach is better
unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int count = 0;
        while(n)
        {
            count++;
            if(n % 2 != 0)
                return count;
            n = n / 2;
        }
        return 0;
    }



