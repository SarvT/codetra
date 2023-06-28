// Leet
// Worked
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i:nums) st.insert(i);
        int l=0;

        for(int n:nums){
            if(!st.count(n-1)){
                int curN = n;
                int curS = 1;

                while(st.count(curN+1)){
                    curN++;
                    curS++;
                }
                l = max(l, curS);
            }

        }
        return l;
    }
};
