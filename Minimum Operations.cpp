class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int steps = 0;
        while(n) (n&1) ? n-- : n >>= 1, steps++;
        return steps;
    }
};
