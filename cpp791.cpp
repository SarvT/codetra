//not worked
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        int idx=0, n=s.size();
        char str[n];
        for(auto it: order)mp[it]=idx++;
        for(int i=0; i<n; i++){
            str[mp[s[i]]] = s[i];
            s[i]='0';
        }
        for(int i=n-2; i>=0; i++){
            if(s[i]!='0') str[i]=s[i];
        }
        return str;
    }
};


// worked
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.length(); ++i) mp[order[i]] = i;
        auto customComparator = [&](char a, char b) {
            return mp[a] < mp[b];
        };
        sort(s.begin(), s.end(), customComparator);
        return s;
    }
};
