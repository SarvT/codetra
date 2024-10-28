class Solution {
    public int calculate(String s) {
        Stack<Integer> st = new Stack<>();
        int num = 0, mark = 1, sol = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (Character.isDigit(c)) num = num * 10 + (c - '0'); 
            else if (c == '+') {
                sol += mark * num;
                mark = 1;
                num = 0; 
            } else if (c == '-') {
                sol += mark * num; 
                mark = -1; 
                num = 0; 
            } else if (c == '(') {
                st.push(sol);
                st.push(mark);
                sol = 0;
                mark = 1; 
            } else if (c == ')') {
                sol += mark * num; 
                sol *= st.pop();
                sol += st.pop();
                num = 0;
            }
        }

        sol += mark * num;
        return sol;
    }
}
