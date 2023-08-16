// not worked --> gave TLE(failed for n=5000)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l=0, r=nums.size();
        while(l+k<=r){
            int maxi=nums[l];
            for(int i=l; i<l+k; i++){
                maxi = max(nums[i], maxi);
            }
                // ans.push_back(max(nums[i], nums[l+k]));
                ans.push_back(maxi);
                l++;
        }
        return ans;
    }
};


// worked
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<k; i++){
            while(!dq.empty()&&nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        ans.emplace_back(nums[dq.front()]);

        for(int i=k; i<nums.size(); i++){
            if(dq.front()==i-k) dq.pop_front();
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            ans.emplace_back(nums[dq.front()]);
        }



        return ans;
    }
};
