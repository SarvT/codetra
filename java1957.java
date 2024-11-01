class Solution {

    public String makeFancyString(String s) {
        if (s.length() < 3) return s;

        StringBuilder str = new StringBuilder();
        str.append(s.charAt(0)).append(s.charAt(1));

        for (int i = 2; i < s.length(); ++i) {
           if (s.charAt(i) != str.charAt(str.length() - 1) ||
                s.charAt(i) != str.charAt(str.length() - 2))
                str.append(s.charAt(i));
        }
        return str.toString();
    }
}
