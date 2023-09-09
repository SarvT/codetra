class Solution
{
    private:
    void dfs(Node *root, priority_queue<int>& pq){
        if(!root) return;
        dfs(root->left, pq);
        pq.push(root->data);
        dfs(root->right, pq);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        priority_queue<int> pq;
        dfs(root, pq);
        while(K!=1){
            K--;
            pq.pop();
        }
        return pq.top();
    }
};
