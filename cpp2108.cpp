worked

class Solution {
public:
bool isPal(string str){
    int i=0, j=str.length()-1;
    while(i<j) if(str[i++]!=str[j--]) return false;
    return true;
}
    string firstPalindrome(vector<string>& words) {
        for(auto it:words)if(isPal(it)) return it;
        return "";
    }
};
