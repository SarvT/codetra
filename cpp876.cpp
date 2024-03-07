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
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr = head;
        int count = 0;
        while(ptr->next != NULL){
            ptr = ptr->next;
            count++;
        }
        ptr = head;
        if(count & 1)
            count = (count/2)+1;
        else
            count = (count/2);
        while(count != 0){
            ptr = ptr->next;
            count--;
        }
        return ptr;
    }
};
