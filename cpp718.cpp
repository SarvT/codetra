// Leet
// not worked
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int cnt=0, currCnt=cnt;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j] && cnt == 0){
                    cnt++;
                }
                else if(nums1[i]==nums2[j] && cnt != 0){
                    cnt++;
                    currCnt = max(currCnt, cnt);
                } else{
                    currCnt = max(currCnt, cnt);
                    cnt=0;
                }
                

            }
        }
        return currCnt;
    }
};

// worked

int findLength(vector<int>& A, vector<int>& B) {
        
        if (A.size() < B.size()) swap(A, B);
        int M = A.size(), N = B.size();
        vector<int> dp(N + 1, 0);
        int ans = 0;
        
        for(int i = 0; i < M; i++) {
            for(int j = N - 1; j >= 0; j--) {
                
                if (A[i] == B[j]) {
                    dp[j + 1] = 1 + dp[j];
                } else {
                    dp[j + 1] = 0;
                }
                              
                ans = max(ans, dp[j + 1]);
            }
            
        }
        
        return ans;
    }
