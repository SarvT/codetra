gfg
worked
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        vector<int> v;
        
        while(!q.empty()){
            v.emplace_back(q.front());
            q.pop();
        }
        for(int i=v.size()-1; i>=0; i--){
            q.push(v[i]);
        }
        return q;
    }
};
