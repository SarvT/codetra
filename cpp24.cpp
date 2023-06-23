// Leet
// Not Worked
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        ListNode* prev = head;
        ListNode* third = head;
        ListNode* temp = head;
        while(third!=NULL || third->next!=NULL){
            if((third==NULL) || (third->next==NULL)) break;
            third = third->next->next;
            temp = prev;
            prev = prev->next;
            tmp = temp;
            tmp->next = third;

            prev = third;
            tmp = third->next;
        }
        return head;
    }
};

// Worked
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* tmp = head;
        ListNode* third = new ListNode(); //debugged->thanks
        ListNode* prev = third;
        
        while(tmp && tmp->next){
            prev->next = tmp->next;
            tmp->next = prev->next->next;
            prev->next->next = tmp;
            
            prev = tmp;
            tmp = tmp->next;
        }
        return third->next;
    }
};
