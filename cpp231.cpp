// Not worked
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n<=0) return false;
        int sol = n&n-1;
        return sol;
    }
};

// Worked
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n<=0) return false;
        return ceil(log2(n) == floor(log2(n)));
    }
};
