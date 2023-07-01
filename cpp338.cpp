// Leet
// Worked
class Solution {
public:
    vector<int> countBits(int n) {
        int count=0;
        vector<int> sol(n+1);
        sol[0]=0;
        for(int i=0; i<=n; ++i) sol[i] = sol[i/2] + (i&1);
        return sol;
    }
};
