class Solution {

    public int minimumMountainRemovals(int[] nums) {
        int N = nums.length;

        int[] lsl = new int[N];
        int[] rsl = new int[N];

        Arrays.fill(lsl, 1);
        Arrays.fill(rsl, 1);

        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] > nums[j]) lsl[i] = Math.max(lsl[i], lsl[j] + 1);
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++)
                if (nums[i] > nums[j]) rsl[i] = Math.max(rsl[i], rsl[j] + 1);
        }

        int minRemovals = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            if (lsl[i] > 1 && rsl[i] > 1) {
                minRemovals = Math.min(
                    minRemovals,
                    N - lsl[i] - rsl[i] + 1
                );
            }
        }

        return minRemovals;
    }
}
