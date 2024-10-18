class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int maxi = 0;
        for (int num : nums) maxi |= num;

        int total = 1 << nums.length;
        int subMaxi = 0;

        for (int subsetMask = 0; subsetMask < total; subsetMask++) {
            int curr = 0;

            for (int i = 0; i < nums.length; i++)
                if (((subsetMask >> i) & 1) == 1) curr |= nums[i];

            if (curr == maxi)subMaxi++;
        }

        return subMaxi;
    }
}
