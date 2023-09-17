// worked ofc
class Solution
{
    // private:
    // int fib(int n, vector<long long>& vec){
    //     if(n==2 || n==1){
    //         vec.emplace_back(1);
    //         return 1;
    //     }
    //     int a = n*fib(n-1, vec);
    //     vec.emplace_back(a);
    //     return 
        
    // }
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> vec(n, 1);
        if(n<=2) return vec;
        for(int i=2; i<n; i++) vec[i]=vec[i-1]+vec[i-2];
        return vec;
        
    }
};
