class Solution {
public:
    int climbStairs(int n) {
        int prev=0, prev2 = 0, curr;
        if(n<=3)return n;
        prev2 = 2;
        prev = 3;
        for(int i = 4;i<=n;i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
