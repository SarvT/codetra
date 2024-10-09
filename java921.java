class Solution {
    public int minAddToMakeValid(String s) {
        int cnt = 0, maxi = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') cnt++;
            else {
                if (cnt > 0) cnt--;
                else maxi++;
            }
        }
        return maxi + cnt;
    }
}
