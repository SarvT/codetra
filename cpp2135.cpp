class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        for(auto& s : startWords) sort(s.begin(), s.end());
        sort(startWords.begin(), startWords.end());
        
        int cnt=0;
        for(auto& t : targetWords) {
            sort(t.begin(), t.end());
            int n=t.size();
            for(int i=0; i<n; i++) {
                string s = t.substr(0, i) + t.substr(i+1, n-i-1); 
                if(binary_search(startWords.begin(), startWords.end(), s)) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
