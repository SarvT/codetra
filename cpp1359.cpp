class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9+7;
        long long cnt=1;
        for(int i=2; i<=n; ++i) cnt = (cnt * (2*i-1)*i)%mod;
        return (int)cnt;
    }
};
