class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                 int left=j+1;
                 int right=n-1;
                while(left<right){
                    int sum=(arr[i]+arr[j]+arr[left]+arr[right]);
                    if(sum==k) {
                        st.insert({arr[i],arr[j],arr[left],arr[right]});
                        left++;
                        right--;
                    }else if(sum<k) left++;
                    else right--;
                }
            }
        }
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};
