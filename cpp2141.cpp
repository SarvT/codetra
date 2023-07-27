// Leet
// not worked
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int i:batteries) sum+=i;
        if(n>sum) return -1;
        return (long long)sum/(long long)n;
        
    }
};

// worked
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long sum = 0;
        for(int i:batteries) sum+=i;
        // if(n>sum) return -1;
        // return (long long)sum/(long long)n;
        long l=1, r=sum/n; 
        while(l<r){
            long t = r-(r-l)/2;
            long rem = 0;

            for(int p:batteries){
                if(p<t) rem += p;
                else rem += t;
            }

            if(rem >= (long)(n*t)) l = t;
            else r = t-1;
        }
        return l;
    }
};
