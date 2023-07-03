class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size()-1, i=0;
        while(i<=n){
           if(!isalnum(s[i])){
               i++;
               continue;
               }
           if(!isalnum(s[n])){
               n--;
               continue;
               }
           if(tolower(s[i])!=tolower(s[n]))return false;
           else{
               i++;
               n--;
           }
       }
       return true;
        
    }
};
