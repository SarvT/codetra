// worked
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1 || n==4) return true;
        if(n<=0) return false;
        // if(n==4) return false;
        float t=n;
        while(t>4){
            t=t/4;
            if(t==4) return true;
        }
        return false;
    }
};
