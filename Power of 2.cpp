not worked --> TLE
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        if(n==1) return 1;
        for(int i=1; ((int)pow(2, i))<=n; i++){
            if(((int)pow(2, i)) == n) return true;
        }
        return false;
        
        
    }
};



worked
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        while(n>0 && n%2==0) n=n/2;
        if(n==1) return true;
        else return false;
        
        
    }
};
