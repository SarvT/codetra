//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String S = in.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.maxLength(S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int maxLength(String S){
        // code here
        int maxi=0, op=0, cl=0;
        for(int i=0; i<S.length(); i++){
            if(S.charAt(i)=='(') op++;
            else cl++;
            if(op==cl) maxi=Math.max(maxi, op*2);
            else if(cl>op){
                cl=0;
                op=0;
            }
        }
        op=0;
        cl=0;
        for(int i=S.length()-1; i>=0; i--){
            if(S.charAt(i)==('(')) op++;
            else cl++;
            if(op == cl) maxi = Math.max(maxi, op*2);
            else if(cl<op){
                cl=0;
                op=0;
            }
        }
        return maxi;
    }
}
