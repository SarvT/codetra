//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		
		while(test > 0){
		    String s = scan.next();
		    String t = scan.next();
		    
		    System.out.println(new Solution().smallestWindow(s, t));
		    test--;
		}
	}
}
// } Driver Code Ends


class Solution
{
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    public static String smallestWindow(String s, String p)
    {
        // Your code here
        int n=p.length();
        int m=s.length();
        if(m<n) return new String("-1");
        int sol[]=new int[26];
        int lft=n;
        for(int i=0;i<n;i++){
            char ch=p.charAt(i);
            sol[ch-'a']++;
        }
        int min=Integer.MAX_VALUE;
        int ans[]=new int[26];
        int cnt=0;
        StringBuilder str=new StringBuilder();
        for(int i=0;i<m;i++){
            char ch=s.charAt(i);
            if(sol[ch-'a']>0&&ans[ch-'a']<sol[ch-'a']){
                lft--;
            }
            ans[ch-'a']++;
            while(cnt<m&&lft==0){
                if(min>i-cnt){
                    str.setLength(0); 
                    str.append(s, cnt, i+1); 
                    min=i-cnt;
                }
                char ch1=s.charAt(cnt);
                ans[ch1-'a']--;
                if(sol[ch1-'a']>0&&ans[ch1-'a']<sol[ch1-'a'])lft++;
                cnt++;
            }
        }
        if(min==Integer.MAX_VALUE) return new String("-1");
        return str.toString();
    }
}
