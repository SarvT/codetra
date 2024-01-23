class Solution {
public:
    int minNonZeroProduct(int p) {
        long long mod = 1000000007, x = (((long long)1 << p) - 2) % mod, y = (((long long)1 << p) - 1) % mod, res = 1;
        while (--p) {
            res *= res, res %= mod;
            res *= x, res %= mod;
        }
        res *= y, res %= mod;
        return res;
    }
};
