// worked
class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        
        int cnt=0;
        int[] vis = new int[1000000];
        Arrays.fill(vis, 0);
        for(int i=0; i<nums.length; i++){
            if(vis[nums[i]]==0){
                vis[nums[i]] = 1;
            } else {
                cnt++;
                nums[i]=nums[i]+1;
                while(vis[nums[i]]!=0){
                    nums[i]=nums[i]+1;
                    cnt++;
                }
                vis[nums[i]] = 1;
            }
        }
        return cnt;
    }
}


// optimal
class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        final int mod = 100000007;

        int cnt=0;
        int[] vis = new int[10000];
        Arrays.fill(vis, 0);
        for(int i=0; i<nums.length; i++){
            if((vis[nums[i]]%mod)==0){
                vis[nums[i]] = 1;
            } else {
                cnt++;
                nums[i]=nums[i]+1;
                while((vis[nums[i]]%mod)!=0){
                    nums[i]=nums[i]+1;
                    cnt++;
                }
                vis[nums[i]] = 1;
            }
        }
        return cnt;
    }
}
