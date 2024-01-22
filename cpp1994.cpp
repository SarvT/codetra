class Solution {
public:
// Take, no take with recursion
    vector<int> vec;
    unordered_map<int,int> mp, mp1;
    int mod = 1e9+7;
    int rec(int i, int mask){
        if(i >= vec.size()) return 1;
        int notake = rec(i+1,mask);
        int take = 0;
        if((mask&vec[i])==0)take = (long(mp1[vec[i]]) * long(rec(i+1,mask|vec[i])))%mod;
        return (take + notake)%mod;
    }

    //fiding power in modulo gfg code
    long long power(long long x, unsigned int y){
        long long res = 1;    
        x = x % mod;    
        if (x == 0) return 0;    
        while (y > 0) {
            if (y & 1)res = (res*x) % mod;
            y = y>>1;
            x = (x*x) % mod;
        }
        return res;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        int a[] = {2,3,5,7,11,13,17,19,23,29};
        int ones = 0;
        for(auto x: nums) mp[x]++;
        for(auto y :mp){
            int x = y.first;
            int b = 0;
            if(x==1) ones = mp[1];// seprating 1
            else { // taking number if it satisfies the rule
                for(int i = 0; i < 10; i++){
                    if(x%a[i]==0){
                        x/=a[i]; // mask according to primes
                        b|=(1<<i);
                    }
                    if(x%a[i]==0||x==1) break;
                }
                if(x==1){
                    vec.push_back(b);
                    mp1[b] = mp[y.first];
                    // creating new frequency using mask
                }
            }
        }
        return (power(2,ones) * (rec(0,0)-1+mod))%mod;
    }
};
