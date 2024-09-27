// TLE

//{ Driver Code Starts
// Initial template for JAVA

import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        // taking input using class Scanner
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            // taking total number of elements
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            ArrayList<Integer> res = new Solution().max_of_subarrays(k, arr);

            // printing the elements of the ArrayList
            for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function template for JAVA

class Solution {
    // Function to find maximum of each subarray of size k.
    int subArray(int st, int en, int k, int arr[]){
       int maxi = arr[st];
       for(int i=st; i<en; i++){
           maxi = Math.max(arr[i], maxi);
       }
       return maxi; 
    }
    public ArrayList<Integer> max_of_subarrays(int k, int arr[]) {
        // Your code here
        ArrayList<Integer> sol = new ArrayList<>();
        for(int i=0; i<arr.length-k; i++){
            sol.add(subArray(i, i+k, k, arr));
        }
        return sol;
    }
}






// Worked


//{ Driver Code Starts
// Initial template for JAVA

import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        // taking input using class Scanner
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            // taking total number of elements
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            ArrayList<Integer> res = new Solution().max_of_subarrays(k, arr);

            // printing the elements of the ArrayList
            for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function template for JAVA

class Solution {
    // Function to find maximum of each subarray of size k.
    int subArray(int st, int en, int k, int arr[]){
       int maxi = arr[st];
       for(int i=st+1; i<=en; i++)maxi = Math.max(arr[i], maxi);
       return maxi; 
    }
    public ArrayList<Integer> max_of_subarrays(int k, int arr[]) {
        // Your code here
        ArrayList<Integer> sol = new ArrayList<>();
        int maxi = subArray(0, k-1, k, arr);
        sol.add(maxi);
        for(int i=1; i<=arr.length-k; i++){
            if(maxi==arr[i-1]){
                maxi=subArray(i, i+k-1, k, arr);
                sol.add(maxi);
            } else {
                maxi=Math.max(arr[i+k-1], maxi);
                sol.add(maxi);
            }
        }
        return sol;
    }
}


















// working version 
 public ArrayList<Integer> max_of_subarrays(int k, int arr[]) {
        // Your code here
        ArrayList<Integer> sol = new ArrayList<>();
        Deque<Integer> dq = new LinkedList<>();
    
        for (int i = 0; i < arr.length; i++) {
            if (!dq.isEmpty() && dq.peekFirst() == i - k) dq.pollFirst();
            while (!dq.isEmpty() && arr[dq.peekLast()] < arr[i]) dq.pollLast();
            dq.addLast(i);
            if (i >= k - 1) sol.add(arr[dq.peekFirst()]);
        }
    
        return sol;
    }