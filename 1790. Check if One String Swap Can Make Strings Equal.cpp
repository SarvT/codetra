//tried
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        while(i<n)
    }
};

//worked
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        int numDiffs = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                numDiffs++;
                if (numDiffs > 2)return false;
                else if (numDiffs == 1)firstIndexDiff = i;
                else secondIndexDiff = i;
            }
        }
        return s1[firstIndexDiff] == s2[secondIndexDiff] &&
               s1[secondIndexDiff] == s2[firstIndexDiff];
    }
};
