//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            ArrayList<Integer> array1 = new ArrayList<Integer>();
            String line = read.readLine();
            String[] tokens = line.split(" ");
            for (String token : tokens) {
                array1.add(Integer.parseInt(token));
            }
            ArrayList<Integer> v = new ArrayList<Integer>();
            int[] arr = new int[array1.size()];
            int idx = 0;
            for (int i : array1) arr[idx++] = i;

            v = new Solution().modifyAndRearrangeArr(arr);

            for (int i = 0; i < v.size(); i++) System.out.print(v.get(i) + " ");

            System.out.println();
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static ArrayList<Integer> modifyAndRearrangeArr(int arr[]) {
        // Complete the function
        ArrayList<Integer> list = new ArrayList<>();
        // for(int i=1; i<=cnt; i++) list.add(0);
        int cnt=0, n=arr.length;
        for(int i=0; i<n-1; i++){
            if(arr[i]!=0 && arr[i]==arr[i+1]){
                list.add(arr[i]*2);
                arr[i+1]=0;
                cnt++;
            } else if(arr[i]!=0) {
                cnt++;
                list.add(arr[i]);
            }
        }
        list.add(arr[n-1]);
        cnt++;
        if((n-cnt)!=0){
            for(int i=1; i<=(n-cnt); i++) list.add(0);
        }
        // for(int i=0; i<list.size(); i++){
        //     if(list.get(i)==0) list.remove(i);
        //     cnt++;
        // }
        // for(int i=1; i<=cnt; i++) list.add(0);
        return list;
    }
}