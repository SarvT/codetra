class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        int high = a[n-1];
        for(int i=n-1; i>=0; i--){
            if(a[i]>=high){
                high = a[i];
                ans.emplace_back(a[i]);
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};
