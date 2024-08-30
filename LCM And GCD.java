//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            Long A = Long.parseLong(S[0]);
            Long B = Long.parseLong(S[1]);

            Solution ob = new Solution();
            Long[] ptr = ob.lcmAndGcd(A,B);
            
            System.out.print(ptr[0]);
            System.out.print(" ");
            System.out.println(ptr[1]);
        }
    }
}
// } Driver Code Ends


class Solution {
    static Long rec(Long a, Long b){
        if(b==0) return a;
        return rec(b, a%b);
    }
    static Long[] lcmAndGcd(Long A , Long B) {
        // code here
        Long[] ans = new Long[2];
        if(A%B==0 || B%A==0){
            ans[0]=Math.max(A,B);
            ans[1]=Math.min(A,B);
        }
        Long gcd = rec(A, B);
        Long lcm = A*B/gcd;
        
        ans[1]=gcd;
        ans[0]=lcm;
        return ans;
    }
};
