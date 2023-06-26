// Leet
// Not worked
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
    ListNode* rotateRight(ListNode* head, int k) {
        // int cnt=0;
        if(!head || !head->next) return head;
        int l=1;
        ListNode* tmp = head;
        ListNode* prev = head;
        while(tmp->next!=NULL){
            l++;
            tmp = tmp->next;
            prev = tmp;
        // cout<< tmp->val << " "<<l;
        }
        prev = head;
        l =l-k;
        tmp->next = head;
        // tmp = head;
        // ListNode* n = head;
        while(l<=0){
            l--;
            prev = prev->next;
        }
        prev->next = NULL;
        return prev;

    }
};



// Worked
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int l=1;
        ListNode* tmp = head;
        while(tmp->next!=NULL){
            l++;
            tmp = tmp->next;
        }
        tmp->next = head;
        k=k%l;
        l =l-k;
        tmp = head;
        while(l>1){
            l--;
            tmp = tmp->next;
        }
        head= tmp->next;
        tmp->next = NULL;
        return head;

    }
};
