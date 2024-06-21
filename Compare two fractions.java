// Not worked

//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str = read.readLine().trim();
            String ans = ob.compareFrac(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {

    String compareFrac(String str) {
        // Code here
        String rx = ", ";
        String[] arr = str.split(rx);
        // int n1, n2, n3, n4;
        String[] val_arr1 = arr[0].split("/");
        String[] val_arr2 = arr[1].split("/");
        double val1 = (int)val_arr1[0]/(int)val_arr1[1];
        double val2 = (double)val_arr2[0]/(double)val_arr2[1];
        // double val2 = n3/n4;
        // if(val1==val2) ? return "equal" : 
        if(val1>val2) return (String)val1;
        return (String)val2;
        // return "greater";
    }
}



// worked
//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str = read.readLine().trim();
            String ans = ob.compareFrac(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {

    String compareFrac(String str) {
        // Code here
        int firstSlashIdx = str.indexOf('/');
        int secondSlashIdx = str.indexOf('/', firstSlashIdx + 1);
        int commaIdx = str.indexOf(',');
        int num1 = Integer.parseInt(str.substring(0,firstSlashIdx));
        int den1 = Integer.parseInt(str.substring(firstSlashIdx+1,commaIdx));
        int num2 = Integer.parseInt(str.substring(commaIdx+2,secondSlashIdx));
        int den2 = Integer.parseInt(str.substring(secondSlashIdx+1,str.length()));
        
        double val1 = (double)num1/den1;
        double val2 = (double)num2/den2;
        if(val1 == val2) return "equal";
        else if(val1>val2) return str.substring(0,commaIdx);
        else return str.substring(commaIdx+2,str.length());
        // return "greater";
    }
}

