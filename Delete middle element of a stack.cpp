// gfg
// not worked
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void rec(stack<int>&s, int mid, int l){
        
        if(s.size() == -1) return;
        if(l == mid) s.pop();
        int store = s.top();
        s.pop();
        rec(s, mid, l+1);
        s.push(store);
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int mid = ceil((sizeOfStack+1)/2);
        rec(s, mid, 0);
        
    }
};

// worked
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void rec(stack<int>&s, int mid){
        
        if(mid == 0) {
            s.pop();
            return;
        }
        int store = s.top();
        s.pop();
        rec(s, mid-1);
        s.push(store);
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int mid = (sizeOfStack/2);
        rec(s, mid);
        
    }
};
