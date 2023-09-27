class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int diff = INT_MAX;
        int res_l, res_r;
    
        int l = 0, r = m-1;
        while (l < n && r >= 0) {
            if (abs(arr[l] + brr[r] - x) < diff) {
                res_l = l;
                res_r = r;
                diff = abs(arr[l] + brr[r] - x);
            }
    
            if (arr[l] + brr[r] > x) {
                r--;
            } else {
                l++;
            }
        }
    
        return {arr[res_l], brr[res_r]};
    }
};
