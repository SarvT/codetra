class Solution {
public:
    int rec(vector<int>& nums, int target){
        int idx=0, cnt=0;
        while(idx<nums.size()-1){
            if(nums[idx+1]-nums[idx]<=target){
                cnt++;
                idx++;
            }
            idx++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int l=0, r=nums[n-1]-nums[0];

        while(l<r){
            int mid=l+(r-l)/2;
            if(rec(nums, mid)>=p) r=mid;
            else l =mid+1;
        }
        return l;
    }
};
