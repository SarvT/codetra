//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        int i, j;
        if(q == 1 || q > 2*n)return 0;
        long long midCnt = n, midEle = n+1, ans = 0;
            
        if(q >= midEle)ans = midCnt - q + midEle;
        else ans = midCnt - midEle + q;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends
