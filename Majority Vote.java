//worked like a charm

//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            List<Integer> nums = new ArrayList<>();
            for (String part : parts) {
                nums.add(Integer.parseInt(part));
            }
            Solution ob = new Solution();
            List<Integer> ans = ob.findMajority(nums);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    // Function to find the majority elements in the array
    public List<Integer> findMajority(List<Integer> nums) {
        // Your code goes here.
        int n=nums.size();
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer> ls = new ArrayList<Integer>();
        for(int it:nums) mp.put(it, mp.getOrDefault(it, 0)+1);
        for(Map.Entry<Integer, Integer> e:mp.entrySet())if(e.getValue()>n/3) ls.add(e.getKey());
        // (ls.size()==0)? ls.add(-1): return ls;
        if(ls.size()<=0) ls.add(-1);
        ls.sort(Comparator.naturalOrder());
        return ls;
    }
}
