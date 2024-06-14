//worked

//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();

            System.out.println(ob.armstrongNumber(n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    static String armstrongNumber(int n) {
        // code here
        int cop = n;
        ArrayList<Integer> arr = new ArrayList<>();
        while(n>0){
            int num = n%10;
            arr.add(num);
            n = n/10;
        }
        int sol = 0;
        Collections.reverse(arr);
        for(int it:arr){
            sol+=(it*it*it);
        }
        if(sol == cop) return "true";
        return "false";
    }
}
