// Leet
// Not Worked

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<int, int> m;
        int i=1;
        while(head!=NULL){
            if(head==NULL) return false;
            else if(m.find(head->val) != m.end()){
                return true;            }
            else{
                m[i++] = head->val;
            }
            head = head->next;
        }
        return false;
    }
};


// Worked
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while((p1!=NULL) && (p1->next!=NULL)){
            p1 = p1->next->next;
            p2 = p2->next;
            if(p1 == p2) return true;
        }
        return false;
    }
};
