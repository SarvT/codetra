// gfg
// not worked
long long power(int N,int R)
    {
       //Your code here
       long long sol = 1.0;
       long long val = R;
       if(val<0) val = -1*val;
       while(val){
           if(val%2){
               sol *= N;
               val-=1;
           } else{
               N = N*N;
               val=val/2;
           }
       }
       if(R<0) sol = (long long)1.0/ (long long)sol;
       return sol;
        
    }


// worked
long long pow = N, ans = 1;
        int mod = 1e9+7;
        while(R > 0){
            if(R & 1){
                ans = (ans * pow)%mod;
            }
            pow = (pow * pow)%mod;
            R = R >> 1;
        }
        return ans;
