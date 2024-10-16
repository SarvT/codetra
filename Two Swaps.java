// worked

//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine()); // Read number of test cases

        // Loop through each test case
        while (t-- > 0) {
            String input = scanner.nextLine();
            String[] inputArr = input.split(" ");
            List<Integer> arr = new ArrayList<>();

            // Convert input to list of integers
            for (String str : inputArr) {
                arr.add(Integer.parseInt(str));
            }

            Solution ob = new Solution();
            boolean ans = ob.checkSorted(arr);

            // Output result
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");
        }

        scanner.close();
    }
}

// } Driver Code Ends


class Solution {
    // boolean checkSorted(List<Integer> arr){
    //     for(int it=0; it<arr.length-1; it++)if(arr.get(it)>arr.get(it+1)) return false;
    //     return true;
    // }
    void swapThem(List<Integer> arr, int st, int en){
        int tmp = arr.get(en);
        arr.set(en, arr.get(st));
        arr.set(st, tmp);
    }
    public boolean checkSorted(List<Integer> arr) {
        // code here
        int i=0, cnt=0;
        while(i<arr.size()){
            if(arr.get(i)!=i+1){
                swapThem(arr, i, arr.get(i)-1);
                cnt++;
            } else i++;
        }
        return cnt==0 || cnt==2;
        
    }
}
