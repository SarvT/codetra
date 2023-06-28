// Leet
// Not worked
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<int> s;
        int flag=0;
        while(!(headA->next) || !(headB->next)){
            s.push_back
        }
        return v[0];
    }
};

// Worked
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
