class Solution {
public:
int M = 1000000007;
    long long pow_temp(long long n){
        if(n == 1) return 2;
        long long t = pow_temp(n/2);
        if(n%2 == 0) return (t*t) % M;
        return (2 * (t*t)%M)%M;
    }
    int monkeyMove(int n) {
        int t = pow_temp(n)%M - 2;
        return (t < 0)? M + t: t;
    }
};
