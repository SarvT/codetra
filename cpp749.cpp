class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size());
        vis[0] = true;
        stack<int> s;
        s.push(0);

        while(!s.empty()){
            int nd = s.top();
            s.pop();
            for(int i:rooms[nd])
                if(!vis[i]){
                    vis[i]=true;
                    s.push(i);
                }
        }

        for(bool b:vis) if(!b) return false;
        return true;
    }
};
