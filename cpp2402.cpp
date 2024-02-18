class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occ;
        priority_queue<int, vector<int>, greater<int>> free;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)free.push(i);
        
     
        sort(meetings.begin(), meetings.end());

        for (auto &&meeting : meetings){
            int start = meeting[0], end = meeting[1];
            while (occ.size() > 0 && occ.top().first <= start){
                free.push(occ.top().second);
                occ.pop();
            }

       
            if (free.size() > 0){
                int top = free.top();
                ans[top]++;
                free.pop(); 
                occ.push({end, top});
            }
            else{
                auto top = occ.top();
                int end1 = top.first, index = top.second;

                ans[index]++;
                occ.pop();
                occ.push({top.first + end - start, index});
            }
        }

     
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};
