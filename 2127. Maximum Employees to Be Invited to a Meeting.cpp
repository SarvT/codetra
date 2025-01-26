//not worked
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> vec(n);
        for(int i=0;i<n;i++){
            vec[favorite[i]].emplace_back(i);
        }
        int cnt=0;
        for(auto it:vec){
            if(it.size()>2) continue;
            else if((it.size()==2)){
                for(auto i:it){
                    for(int k:vec[i])
                        if(k==it){
                            cnt++;
                            break;
                        }

                }
            }
            cnt++;
        }
        return cnt;

    }
};


//worked
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // vector<vector<int>> vec(n);
        // for(int i=0;i<n;i++){
        //     vec[favorite[i]].emplace_back(i);
        // }
        // int cnt=0;
        // for(auto it:vec){
        //     if(it.size()>2) continue;
        //     else if((it.size()==2)){
        //         for(auto i:it){
        //             for(int k:vec[i])
        //                 if(k==it){
        //                     cnt++;
        //                     break;
        //                 }

        //         }
        //     }
        //     cnt++;
        // }
        // return cnt;
        vector<int> vec(n, 0);

        for (int p = 0; p < n; ++p) {
            vec[favorite[p]]++;
        }

        queue<int> q;
        for (int p = 0; p < n; ++p) {
            if (vec[p] == 0) {
                q.push(p);
            }
        }

        vector<int> depth(n, 1); 
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            int nextNode = favorite[currentNode];
            depth[nextNode] = max(depth[nextNode], depth[currentNode] + 1);
            if (--vec[nextNode] == 0) {
                q.push(nextNode);
            }
        }

        int maxi = 0, pairs = 0;

        for (int p = 0; p < n; ++p) {
            if (vec[p] == 0) continue;  
            int len = 0;
            int current = p;
            while (vec[current] != 0) {
                vec[current] = 0;  
                len++;
                current = favorite[current];
            }

            if (len == 2) {
                pairs += depth[p] + depth[favorite[p]];
            } else {
                maxi = max(maxi, len);
            }
        }

        return max(maxi, pairs);

    }
};
