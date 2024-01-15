// incomplete soluton
class Solution {
public:
    bool cmp(pair<string, int>& a, pair<string, int>& b) { 
        return a.second < b.second; 
    } 
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it:words) mp[it]++;
        // sort(mp.begin(), mp.end(), cmp);
        for(auto )
    }
};



// worked --> complete solution
class Solution {
public:
// new part to learn to practicize
struct comp{
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)return a.second > b.second;
        else return a.first < b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int>mp;
        vector<string>ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(int i=0; i<n; i++)mp[words[i]]++;
        for(auto it= mp.begin(); it!=mp.end(); it++)pq.push({it->second,it->first});
            
        
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
