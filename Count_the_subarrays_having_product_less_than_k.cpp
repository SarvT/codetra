// gfg
// Not worked
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
  int cnt=0;
    void rec(const vector<int>& a, int n, long long k, int l, long long sum){
        if(l == n && sum<k){
            cnt++;
            return;
        }
        if(sum<k){
            cnt++;
            // return;
        }
        
        // for(int i=l; i<n; i++){
            sum+=a[l];
            rec(a, n, k, l+1, sum);
            sum-=a[l];
            rec(a, n, k, l+1, sum);
        // }
    }
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
            long long sum;
            rec(a, n, k, 0, sum);
            return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}



// Worked
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int cnt=0;
        long cur=1;
        for(int i=0; i<n; i++){
            cur=1;
            for(int j=i; j<n; j++){
                cur*=a[j];
                if(cur>=k) break;
                else cnt++;
            }
        }
        
        return cnt;
    }
};
