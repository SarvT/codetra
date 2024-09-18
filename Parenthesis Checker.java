//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        //Reading total number of testcases
        int t= sc.nextInt();
        
        while(t-- >0)
        {
            //reading the string
            String st = sc.next();
            
            //calling ispar method of Paranthesis class 
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(new Solution().ispar(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");
        
        }
    }
}
// } Driver Code Ends



class Solution
{
    //Function to check if brackets are balanced or not.
    static boolean ispar(String x)
    {
        // add your code here
        int n=x.length();
        if(n%2!=0) return false;
        Stack<Character> st = new Stack<>();
        int i=0;
        while(i<n ){
            if((x.charAt(i)=='(') || (x.charAt(i)=='[') || (x.charAt(i)=='{'))
                st.push(x.charAt(i));
            else if((x.charAt(i)==')') || (x.charAt(i)==']') || (x.charAt(i)=='}')){
                if(st.empty()) return false;
                char sEle = x.charAt(i);
                char ele = st.pop();
                // System.out.print(ele + " " + sEle);
                if(ele == '(' && sEle != ')') return false;
                else if(ele == '[' && sEle != ']') return false;
                else if(ele == '{' && sEle != '}') return false;
            } 
            i++;
            
        }
        if(st.empty())return true;
        return false;
    }
}
