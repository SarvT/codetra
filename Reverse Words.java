// not worked
class Solution {
    // Function to reverse words in a given string.
    String reverseWords(String str) {
        // code here
        String rev="", s="";
        int l=0;
        for(int i=str.length()-1; i>=0; i--){
            l=i;
            while(l>=0 && str.charAt(l)!='.'){
                s=str.charAt(l)+s;
                l--;
            }
            System.out.print(str.charAt(l));
            i=l;
            if(str.charAt(i)=='.'){
                rev = rev + s;
                s = "";
            }
            
        }
        return rev;
    }
}




// worked



class Solution {
    // Function to reverse words in a given string.
    String reverseWords(String str) {
        // code here
        String rev="", s="";
        int l=0;
        for(int i=str.length()-1; i>=0; i--){
            // l=i;
            // while(l>=0 && str.charAt(l)!='.'){
            //     s=str.charAt(l)+s;
            //     l--;
            // }
            // System.out.print(str.charAt(l));
            // i=l;
            if(str.charAt(i)!='.')s = str.charAt(i) + s;
            else{
                rev+=s+".";
                s = "";
            }
            
        }
        rev+=s;
        return rev;
    }
}
