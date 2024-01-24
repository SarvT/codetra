// worked
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>queue;
    int ele;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums) queue.push(it);
        ele=k;
    }
    
    int add(int val) {
        queue.push(val);
        while(queue.size()>ele) queue.pop();
        return queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
