// not worked
//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.padovanSequence(n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{

  public int padovanSequence(int n)
    {
        //code here.
        if(n==1 || n==2 || n==0) return 1;
        int[] arr = new int[n+1];
        arr[0]=1;
        arr[1]=1;
        arr[2]=1;
        for(int i=3; i<=n; i++){
            arr[n]=(arr[n-2]+arr[n-3]);
        }
        return (arr[n]);
    }
    
}





// not worked
//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.padovanSequence(n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
  public int padovanSequence(int n)
    {
        //code here.
        if(n==1 || n==2 || n==0) return 1;
        int[] arr = new int[n+1];
        return (padovanSequence(n-2)+padovanSequence(n-3));
    }
    
}










// worked
//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.padovanSequence(n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
  public int padovanSequence(int n)
    {
        //code here.
        final int MOD = 1000000007;
        int p0 = 1, p1 = 1, p2 = 1, p = 0;
        if(n==1 || n==2 || n==0) return 1;
        // int[] arr = new int[n];
        // int[] arr = new int[n+1];
         for (int i = 3; i <= n; i++) {
            p = (p1 + p0) % MOD;
            p0 = p1;
            p1 = p2;
            p2 = p;
        }
        return (p);
    }
    
}
