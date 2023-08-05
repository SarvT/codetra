class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long ans;
    
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if((i+m)<n) ans = min(a[i+m-1]-a[i], ans);
    }
    return ans;
    }   
};


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(), a.end());
    long long ans = a[m]-a[0];
    for(int i=0; i<n; i++){
        if((i+m-1)<n) ans = min(a[i+m-1]-a[i], ans);
    }
    return ans;
    }   
};


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(), a.end());
    long long ans=1e9+7;
    long long start=0,end=m-1;
        
        while(end<n){
            if(a[end] - a[start] <= ans ){
                ans = a[end] - a[start];
            }   
            start++;
            end++;
        }
    return ans;
    }   
};
