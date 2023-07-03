class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int> v(n), v2(n);
        v[0] =arr[0];
        v2[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            v[i] = min(v[i - 1], arr[i]);
            v2[n-i-1] = max(arr[n-i-1], v2[n-i]);
        }
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (v[i] <= v2[j]) {
              ans = max(ans, j - i);
              j++;
            } 
            else i++;
      }
      return ans;
    }

};
