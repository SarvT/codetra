// worked but TLE
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt=0, n=nums.size();
        set<pair<int, int>> st;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(st.find({nums[i], nums[j]})==st.end()){
                    st.insert({nums[i], nums[j]});
                    int maxi = max(nums[i], nums[j]);
                    int mini = min(nums[i], nums[j]);
                    if((maxi-mini)==k && i!=j) cnt++;
                }
            }
        }
        return cnt;
    }
};




// finally
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt=0, n=nums.size();
        int b=0, f=1;


        while(f<n){
            int maxi = max(nums[f], nums[b]);
            int mini = min(nums[f], nums[b]);
            if((maxi-mini)==k) {
                cnt++;
                f++;
                b++;
                while (f < n && nums[f] == nums[f - 1])f++;
            }
            else if(b+1 != f && (maxi-mini)>k) b++;
            else f++;
        }
        return cnt;
    }
};
