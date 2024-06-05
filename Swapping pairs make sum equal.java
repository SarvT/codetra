//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    long findSwapValues(long a[], int n, long b[], int m) {
        // Your code goes here
        long asum=0,bsum=0;
        for(long i:a)asum+=i;
        for(long i: b)bsum+=i;
        if(asum>bsum)return findSwapValues(b,m,a,n);
        if((bsum-asum)%2!=0)return -1;
        long d=(bsum-asum)/2;
        Arrays.sort(b);
        for(int i=0;i<n;i++){
            if(search(a[i]+d,b,m))return (long)1;
        }
        return (long)-1;
    }
    boolean search(long k,long[] b,int m){
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(b[mid]==k)return true;
            else if(b[mid]<k)low=mid+1;
            else high=mid-1;
        }
        return false;
    }
}

//{ Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            String line = br.readLine();
            String[] q = line.trim().split("\\s+");
            int n = Integer.parseInt(q[0]);
            int m = Integer.parseInt(q[1]);
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(a1[i]);
            }
            String line2 = br.readLine();
            String[] a2 = line2.trim().split("\\s+");
            long b[] = new long[m];
            for (int i = 0; i < m; i++) {
                b[i] = Long.parseLong(a2[i]);
            }
            Solution ob = new Solution();
            long ans = ob.findSwapValues(a, n, b, m);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends
