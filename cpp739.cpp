// Leet
// not worked -- TLE
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int cnt = 0, n=temperatures.size();
        vector<int> sol;
        for(int i = 0; i< n; i++){
            for(int j = i+1; j<n; j++){
                if( temperatures[i] < temperatures[j]){
                    sol.push_back(cnt+1);
                    cnt=0;
                    break;
                } else if(j == n-1 &&  temperatures[i] >= temperatures[j]){
                    sol.push_back(0);
                    cnt=0;
                }
                else cnt++;
            }
        }
        sol.push_back(0);
        return sol;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int cnt = 0, n=temperatures.size(), i=0, maxi = temperatures[i], j=i+1;
        vector<int> sol;
        
        while(i != n-1){
            if(maxi < temperatures[j]){
                    maxi =  temperatures[j];
                    sol.push_back(cnt+1);
                    cnt=0;
                    i++;
                    j=i+1;
                } else if(j == n-1 &&  maxi >= temperatures[j]){
                    sol.push_back(0);
                    cnt=0;
                }
                else cnt++;
        }
        sol.push_back(0);
        return sol;
    }
};


// worked
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> sol(n, 0);
        for(int i = 0; i< n; i++){
            while(!st.empty() > 0 &&  temperatures[st.top()] <  temperatures[i]){
                int t = st.top();
                st.pop();
                cout<<t;
                sol[t] = i-t;
            }
            st.push(i);
        }
        return sol;
    }
};
