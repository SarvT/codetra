// Leet
// Not worked
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length(), count=0;
        cout << n;
        if(n==1) return 1;
        while(n >= 0){
            if(s[n] != ' ' && s[n] != '\0' && n>=0){
                while(s[n] != ' ' && n>=0){
                    count++;
                    n--;
                }
                if(s[n] == ' ') break;
            } else n--;
        }
        return count;
    }
};



// Worked
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1, count=0, flag=0;
        if(n==1) return 1;
        while(n >= 0){
            if(s[n] == ' ' && flag) break;
            if(s[n] != ' '){
                flag=1;
                count++;    
            }
            n--;
        }
        return count;
    }
};
