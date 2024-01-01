class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int coockie = 0;
        while (coockie < s.size() && child < g.size()) {
            if (s[coockie] >= g[child]) child++;
            coockie++;
        }
        return child;
    }
};
