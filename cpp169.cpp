// Leet
// Not worked
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> pr;
        int mj=0;
        int maxi;
        unordered_map<int, int> st;
        for(int i:nums){
            st[i] = i;
        }
        // maxi
        for(int i:nums){
            if(st.count(i) >= maxi){
                pr.first = i;
                pr.second = st.count(i);
                maxi = st.count(i);
            }
            // maxi = max(st.count(i), maxi);
        }
        return pr.first;
    }
};


// Worked
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> pr;
        int mj=0;
        int maxi;
        unordered_map<int, int> st;
        for(int i:nums){
            if(st.find(i) != st.end()) st[i]++;
            else st[i] = 1;
            cout << st[i];
        }
        // maxi
        for(int i:nums){
            if(st[i] >= pr.second){
                pr.first = i;
                pr.second = st[i];
                // maxi = st.count(i);
            }
            // maxi = max(st.count(i), maxi);
        }
        return pr.first;
    }
};
