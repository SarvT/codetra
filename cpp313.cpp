class Solution {
public:
    int nthSuperUglyNumber(int nI, vector<int>& primes) {
        if(nI==1) return 1;

        int n = primes.size();
        vector<int> index(n, 0);

        int uglies[nI];
        uglies[0]=1;

        for(int i=1; i<nI; i++){
            long mini = INT_MAX;
            for(int j=0; j<n; j++)
                mini = min(mini, (long)primes[j] * uglies[index[j]]);

            uglies[i] = (int)mini;


            for(int j=0; j<n; j++){
                if(mini == (long)primes[j]*uglies[index[j]]) index[j]++;
            }
        }
        return uglies[nI-1];
    }
};
