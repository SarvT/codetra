not
class Solution{
public:
    void Reverse(stack<int> &St){
        if(St.empty()) return;
        int n = St.top();
        St.pop();
        Reverse(St);
        St.push(n);
    }
};

// worked
class Solution{
public:
    void rec(stack<int> &St, int tmp){
        if(St.empty()){
            St.push(tmp);
            return;
        }
        
        int data = St.top();
        St.pop();
        rec(St, tmp);
        St.push(data);
    }
    void Reverse(stack<int> &St){
        if(St.empty()) return;
        int n = St.top();
        St.pop();
        Reverse(St);
        rec(St, n);
    }
};
