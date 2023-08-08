class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<double, int> mp;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            ans += mp[((double)(denominator[i]-numerator[i])/(double)denominator[i])];
            mp[(double)numerator[i]/(double)denominator[i]]++;
        }
        return ans;
    }
};
