Input: nums = [4,3,6,16,8,2]
Output: 3


after sort
[2, 3, 4, 6, 8, 16]

take - no take
class Solution {

    public void tnt(int[] nums, ArrayList<Integer> list){
        for(int i=1; i<nums.length; i++){
        // if(i<0) return;
            if((nums[i-1]*nums[i-1])==nums[i]){
                list.add(nums[i]);
                tnt(nums, list);
            }

        }
    }
    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        // for(int i=0; i<nums.length; i++){
            
        // }
        ArrayList<Integer> list = new ArrayList<>();
        tnt(nums, list);
        return list.size();
    }
}




worked
class Solution {

    public boolean tnt(int[] nums, int tar){
        if (tar < 0) return false;

        int start = 0, end = nums.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tar) return true;
            if (nums[mid] > tar) end = mid - 1;
            else start = mid + 1;
        }

        return false;
    }
    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        Set<Integer> st = new HashSet<>();
        int ini = 0;

        for (int curr : nums) {
            if (st.contains(curr)) continue;

            int cnt = curr, maxi = 1;

            while (true) {
                if ((long) cnt * (long) cnt > 1e5) break;
                if (tnt(nums, cnt * cnt)) {
                    cnt *= cnt;
                    st.add(cnt);
                    maxi++;
                } else break;
            }
            ini = Math.max(ini, maxi);
        }
        return ini < 2 ? -1 : ini;
    }
}
