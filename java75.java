// workeed
class Solution {
    public void sortColors(int[] nums) {
        int zero = 0;
        for (int i = 0; i < nums.length; i++) 
            if (nums[i] == 0) swap(nums, i, zero++);
        for (int i = zero; i < nums.length; i++) 
            if (nums[i] == 1) swap(nums, i, zero++);
    }
    void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
