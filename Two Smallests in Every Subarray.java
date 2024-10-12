// TLE --> partial
//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) a[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            int res = obj.pairWithMaxSum(a);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    ArrayList<Integer> res = new ArrayList<>();
    void rec(int[] arr, int st, int l){
        if(l-st<1) return;
        // int maxi1=arr[l], maxi2=arr[l];
        int maxi1=arr[st], maxi2=arr[l];
        for(int i=st; i<=l; i++){
            if(arr[i]<maxi1){
                maxi2=maxi1;
                maxi1=arr[i];
            // System.out.print(arr[i]+ " "+i+ " "+maxi1+" ");
            }
            // System.out.println();
        }
        res.add(maxi1+maxi2);
    }
    public int pairWithMaxSum(int[] arr) {
        // code here
        if(arr.length<=1) return -1;
        for(int i=0;i<arr.length; i++){
            for(int j=i+1;j<arr.length; j++){
                if(i!=j)rec(arr, i, j);
            }
        }
        int maxi1=res.get(0);
        for(int it:res) {
            maxi1=Math.max(it, maxi1);
        }
        return maxi1;
    }
}





// Worked --> charm solution
//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) a[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            int res = obj.pairWithMaxSum(a);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {

    public int pairWithMaxSum(int[] arr) {
        // code here
        if(arr.length<=1) return -1;
        int mini=arr[0]+arr[1];
        
        for(int i=1;i<arr.length-1; i++)mini=Math.max(mini, arr[i]+ arr[i+1]);
        return mini;
    }
}
