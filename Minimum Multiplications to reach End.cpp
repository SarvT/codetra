class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int ans=-1, cnt=0;
        for(int i=0; i<arr.size(); i++){
            if(start==end) return cnt;
            else {
                start = 
            }
        }
        
        return ans;
    }
};



// worked
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<long long,int>>q;
        q.push({start,0});
        int m=1e5;
        vector<bool>vis(1e5+1,0);
        vis[start]=1;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            long long val=front.first;
            int steps=front.second;
            if(val==end) return steps;
            
            for(int i=0;i<arr.size();i++){
                if(!vis[(arr[i]*1LL*val)%m]){
                    vis[(arr[i]*1LL*val)%m]=1;
                    q.push({(arr[i]*1LL*val)%m,steps+1});
                }
            }
        }
        return -1;
    }
};
