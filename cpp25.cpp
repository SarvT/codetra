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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* tmp = head;
        ListNode* dummy = new ListNode();
        dummy->next=head;
        ListNode *prev=dummy, *cur=dummy, *forw=dummy;
        while(tmp!=NULL){
            cnt++;
            tmp = tmp->next;
        }
        while(cnt>=k){
            cur=prev->next;
            forw=cur->next;
            for(int i=1; i<k; i++){
                cur->next=forw->next;
                forw->next=prev->next;
                prev->next=forw;
                forw=cur->next;
            }
            prev=cur;
            cnt-=k;
        }
        return dummy->next;
    }
};
