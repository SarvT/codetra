// Leet
// Not Worked
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        vector<int> res;
        for(int i:asteroids){
            if(i>0 && )
            res.push_back(i)
        }
    }
};


// Worked
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        stack<int> s;
        for(int i:asteroids){
            int flag=1;
            while(!s.empty() && (s.top()>0 && i<0)){
                if(abs(s.top())<abs(i)){
                    s.pop();
                    continue;
                } else if(abs(s.top())==abs(i)) s.pop();

                flag=0; break;
            }
            if(flag) s.push(i);
        }

        vector<int> res(s.size());
        for(int i=res.size()-1; i>=0; i--){
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
