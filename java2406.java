class Solution {

    public int minGroups(int[][] intervals) {
        TreeMap<Integer, Integer> cnt = new TreeMap<>();
        for (int[] interval : intervals) {
            cnt.put(interval[0],cnt.getOrDefault(interval[0], 0) + 1);
            cnt.put(interval[1] + 1,cnt.getOrDefault(interval[1] + 1, 0) - 1);
        }

        int intCurr = 0, maxi = 0;

        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            intCurr += entry.getValue();
            maxi = Math.max(maxi, intCurr);
        }

        return maxi;
    }
}
