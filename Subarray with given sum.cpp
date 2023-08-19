class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        
        int sum = 0,l = 0,r = -1;
        while(r < n && sum != s){
            sum += arr[++r];
            if(sum > s){
              while(sum > s)
              sum -= arr[l++];
            }
        }
        if(r == n || l > r) return {-1};  
        
       return {l+1,r+1};
        
    }
};
