class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
         if (indexDiff < 1 || valueDiff < 0)return false;
        SortedSet<Long> sst = new TreeSet<Long>();
        for (int j = 0; j < nums.length; j++) 
        {
            long st = (long) nums[j] - valueDiff;
            long en = (long) nums[j] + valueDiff + 1;
            SortedSet<Long> subSet = sst.subSet(st, en);
            if (!subSet.isEmpty())return true;
            sst.add((long) nums[j]);
            if (j >= indexDiff) sst.remove((long) nums[j - indexDiff]);
        }
        return false;
    }
}
