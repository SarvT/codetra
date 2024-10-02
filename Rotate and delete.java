//works like a charm
//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends

class Solution {
    public static int rotateDelete(ArrayList<Integer> arr) {
        // code here
        int i=1, n=arr.size();
        while(i<=n){
            arr.add(0, arr.get(arr.size()-1));//rotates the array
            arr.remove(arr.size()-1);//deletes the rotated element from the array
            arr.remove(n-i);//deletes the kth element from the aaray
            n--; //5 4 3-x   //size decreases of n
            i++; //2 3 4-x //size increases of i i.e.moving to next element
            // System.out.println(arr);
        }
        return arr.get(0);
        // 1, 2, 3, 4, 5, 6
        // 6, 1, 2, 3, 4, (5)
        // 4, 6, 1, (2), 3
        // 3, 6, (1)
        // 3, (6)
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> arr = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                arr.add(Integer.parseInt(token));
            }

            Solution obj = new Solution();
            int res = obj.rotateDelete(arr);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends
