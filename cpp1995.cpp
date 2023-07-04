// Leet
// Not worked
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j, k, l, n=nums.size(), cnt=0;
        for(int i=0; i<n-3; i++){
            j=i+1;
            l=i+3;
            k=l-1;
            while(j<k && l<n){
                if(nums[i]+nums[j]+nums[k] == nums[l] ) {
                    cnt++;
                    j++;
                    cout<<cnt<<" "<<i;
                    // k--;
                }
                else if(nums[i]+nums[j]+nums[k] > nums[l]) {
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k] < nums[l]) {
                    j++;
                }
                else l++;
            }
        }
        return cnt;
    }
};

// Worked
class Solution {
public:
    int countQuadruplets(vector<int>& arr) {
        int c=0,n=arr.size();
        map<int,int>mp;
         for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                mp[arr[i]+arr[j]]++;
            }
            for(int k=i+2;k<n;k++){
                c+=mp[arr[k]-arr[i+1]];
            }
         }
         return c;
    }
};
