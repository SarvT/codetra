class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<vector<int>> directions{{1,-1},{1,-1},{1,-1},{1,-1}};

        int count = 0;

        unordered_set<string> dead;

        unordered_set<string> vis;

        for(auto& str : deadends) {
            dead.insert(str);
        }
        string start = "0000";
        queue<string> q;

        q.push(start);

        while(!q.empty()) {
            int n = q.size();

            for(int i=0; i<n; i++) {
                string curr = q.front();
                q.pop();

                if(dead.find(curr) != dead.end()) continue;
                if(curr == target)  return count;

                for(int i=0; i<4; i++) {
                    for(int dir : directions[i]) {
                        string next = curr;
                        next[i] = (next[i] - '0' + dir + 10)% 10 + '0';

                        if(vis.find(next) == vis.end()) {
                            q.push(next);
                            vis.insert(next);
                        }

                    }
                }
            }
            count++;
        }

        return -1;
    }
};
