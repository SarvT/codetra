class Solution {
    public long minimumSteps(String s) {
        long total = 0, cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') total += (long) cnt;
            else cnt++;
        }

        return total;
    }
}
