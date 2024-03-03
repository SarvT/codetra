/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        ListNode* ptr2 = head;
        int count = 0;
        if(head->next == NULL)
            return NULL;
        while(count != n){
            count++;
            ptr = ptr->next;
        }
        if(!ptr) return head->next;
        while(ptr->next){
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        ptr2->next = ptr2->next->next;
        return head;
    }
};
