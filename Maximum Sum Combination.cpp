class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int>ans;
        while(K>0){
            int sol = max();
            ans.emplace_back()
        }
    }
};


// worked
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        priority_queue<vector<int>> pq;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(int i = N - 1; i >= 0; i--) pq.push({A[i] + B[N - 1], i, N - 1});
            
        vector<int> ans;
        while(--K > 0) {
            auto p = pq.top();
            pq.pop();
            
            int sum = p[0], x = p[1], y = p[2];
            ans.push_back(sum);
            pq.push({A[x] + B[y - 1], x, y - 1});
        }
        
        ans.push_back(pq.top()[0]);
        return ans;
    }
};
