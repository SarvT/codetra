// it worked
class Solution {
    public int minSubarray(int[] nums, int p) {
        int sum=0;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int it:nums)sum=(sum+it)%p;
        int mod = sum%p;
        if(mod==0) return 0;

        int ans = nums.length, n=ans;
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);
        int currSum=0;
        for(int i=0; i<n; i++){
            currSum= (currSum+nums[i])%p;
            int requi = (currSum-mod+p)%p;
            if(mp.containsKey(requi)) ans = Math.min(ans, i-mp.get(requi));
            mp.put(currSum, i);
        }
        return ans==n?-1:ans;
    }
}
