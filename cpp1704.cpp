class Solution {
public:
int vowel(char c){
        char it = tolower(c);
        return it=='a'||it=='e'||it=='i'||it=='o'||it=='u';
    }
    bool halvesAreAlike(string s) {
        int vow=0;
        for(int i=0;i<s.size()/2;i++)if(vowel(s[i]))vow++;
        for(int i=s.size()/2;i<s.size();i++)if(vowel(s[i]))vow--;
        return vow==0?true:false;
    }
};
