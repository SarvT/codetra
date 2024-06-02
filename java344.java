//solved
class Solution {
    public void reverseString(char[] s) {
        int n = s.length-1;
        char[] str = new char[n+1];
        char tmp;
        for(int i=0; i<=n; i++){
            tmp = s[i];
            s[i] = s[n];
            s[n] = tmp;
            n--;
        }
    }
}
