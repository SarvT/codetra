//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int sortHelper(long long int a, long long int b){
    if(a>b) return a;
    return b;
}
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int vec[n];
        vec[n-1] = 0;
        for(long long int i=n-2; i>=0; i--) vec[i] = sortHelper(0,a[i+1] + vec[i+1]);
        long long sum[n], ans=0;
        sum[0] = a[0];
        for(long long int i=0; i<n; i++){
            // with all four conditions
            if(i==0) sum[0] = a[0];
            else sum[i] = a[i] + sum[i-1];
            if(i == k-1) ans = sum[k-1] + vec[k-1];
            else if(i >= k) ans = sortHelper(ans,sum[i] - sum[i-k] +vec[i]);
        }
        return ans;
   
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
