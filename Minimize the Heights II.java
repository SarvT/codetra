not worked
//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int k = Integer.parseInt(inputLine[0]);

            // Ensure input is read correctly
            inputLine = br.readLine().trim().split(" ");
            if (inputLine == null || inputLine.length == 0) {
                System.out.println("Invalid input");
                continue;
            }

            int[] arr = new int[inputLine.length];
            for (int i = 0; i < inputLine.length; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().getMinDiff(arr, k);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    int getMinDiff(int[] arr, int k) {
        // code here
        Arrays.sort(arr);
        for(int i=0; i<arr.length-1; i++){
            if(arr[i]+k<=arr[i+1]) arr[i] = arr[i]+k; 
            else if(arr[i]-k>=0)arr[i] = arr[i]-k;
            else {
                
                if(arr[i]-k<0) return -1;
                // else if((arr[i]+k > arr[i]-k))
            }
        }
            if(arr[arr.length-1]+k<=arr[arr.length-1]) arr[arr.length-1] = arr[arr.length-1]+k; 
            else if(arr[arr.length-1]-k>=0)arr[arr.length-1] = arr[arr.length-1]-k;
            else arr[arr.length-1]=arr[arr.length-1]-k;
        return (arr[arr.length-arr[0]]);
    }
}


// worked
//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int k = Integer.parseInt(inputLine[0]);

            // Ensure input is read correctly
            inputLine = br.readLine().trim().split(" ");
            if (inputLine == null || inputLine.length == 0) {
                System.out.println("Invalid input");
                continue;
            }

            int[] arr = new int[inputLine.length];
            for (int i = 0; i < inputLine.length; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().getMinDiff(arr, k);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    int getMinDiff(int[] arr, int k) {
        // code here
        if(arr.length==1) return 0;
        Arrays.sort(arr);
        int diff = arr[arr.length-1] - arr[0];
        int st = arr[0]+k;
        int en = arr[arr.length-1]-k;
        
        for(int i=0; i<arr.length-1; i++){
            int mini = Math.min(st, arr[i+1]-k);
            int maxi = Math.max(en, arr[i]+k);
            
            if(mini>=0) diff = Math.min(diff, maxi-mini);
            
        }
        return diff;
    }
}
