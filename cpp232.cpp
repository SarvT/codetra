not worked
class MyQueue {
public:
    MyQueue() {   
    }
    
    void push(int x) {
        if(s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()) s2.push(s1.pop());
        }
        return s2.pop();
    }
    
    int peek() {
        if(!s2.empty()) return s2.peek();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
stack<int> s1;
stack<int> s2;
int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



worked
class MyQueue {
public:
    stack<int> a;
    stack<int> b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top()); 
                a.pop();
            }
        }
        int f = b.top();
        b.pop();
        return f;
    }
    
    int peek() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top()); 
                a.pop();
            }
        }
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};
