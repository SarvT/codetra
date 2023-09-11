not worked
bool isLucky(int n) {
        // code here
        if(n&1) return false;
        int i=1, flag=1;
        while(i<=n){
            if(i>n) return true;
            if(i==n) return false;
            if(flag){
                flag=0;
                i+=2;
            } else{
                flag=1;
                i+=4;
            }
        }
        return true;
    }


after correction not worked
class Solution{
public:
    bool isLucky(int n) {
        // code here
        if(!(n&1)) return false;
        int i=1, flag=1;
        while(i<=n){
            if(i>n) return false;
            if(i==n) return true;
            if(flag){
                flag=0;
                i+=2;
            } else{
                flag=1;
                i+=4;
            }
        }
        return true;
    }
};

worked
class Solution{
public:
    bool solve(int n,int k)
        {
            if(n%k==0) return false;
            if(n<k) return true;
            return solve((n-(n/k)),k+1);
        }

    bool isLucky(int n) {
        // code here
        return solve(n, 2);
    }
};
