class Solution {
public:
    bool static cmp(char a,char b){
        return a>b;
    }
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end(),cmp);
        s.push_back('1');
        s.erase(0,1);
        return s;
    }
};
