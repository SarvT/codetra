// Leet
// Not worked
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=b){
            if(!a) a=headA;
            else a=a->next;
            if(!b) b=headB;
            else b=b->next;
        }
        return a;
    }
};

// Worked
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* nxt = NULL;
        ListNode* pre = NULL;
        while(head!=NULL){
            nxt = head->next;
            head->next = pre;
            pre = head;
            head=nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};
