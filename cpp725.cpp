class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* cur = root;
        int N = 0;
        while (cur != nullptr) {
            cur = cur->next;
            N++;
        }

        int width = N / k, rem = N % k;

        vector<ListNode*> ans(k);
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode* head = cur;
            for (int j = 0; j < width + (i < rem ? 1 : 0) - 1; ++j) {
                if (cur != nullptr) cur = cur->next;
            }
            if (cur != nullptr) {
                ListNode* prev = cur;
                cur = cur->next;
                prev->next = nullptr;
            }
            ans[i] = head;
        }
        return ans;
    }
};
