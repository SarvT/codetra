not worked
class Solution
{
public:
    vector<int> leafs;
    void rec(Node *root, int k){
        if(!root) return;
        if(!root->left && !root->right && root->data<=k){
            leafs.emplace_back(root->data);
            return;
        }
        rec(root->left, k);
        rec(root->right, k);
    }
    int getCount(Node *root, int k)
    {
        //code here
        rec(root, k);
        sort(leafs.begin(), leafs.end());
        int cnt=0;
        for(auto i:leafs){
            if(i>k) break;
            else {
                k = k-i;
                cnt++;
            }
        }
        return cnt;
    }
};


worked
queue<pair<Node*, int>> q;
        q.push({root, 1});
        int cnt = 0;

        while (!q.empty() && k > 0) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (!node->left && !node->right) {
                if (level > k)
                    return cnt;

                ++cnt;
                k -= level;
            } else {
                if (node->left)
                    q.push({node->left, level + 1});
                if (node->right)
                    q.push({node->right, level + 1});
            }
        }

        return cnt;
