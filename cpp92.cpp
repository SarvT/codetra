// not worked
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmpStart=head;
        ListNode* tmpHead=head;
        stack<ListNode*> st;
        int l=1, r=left;
        while(l!=left){
            if(l==left-1) tmpHead=tmpStart;
            l++;
            tmpStart = tmpStart->next;
        }
        ListNode* tmpEnd=tmpStart;
        while(r!=right){
            st.push(tmpStart);
            tmpStart = tmpStart->next;
            r++;
        }
        while(!st.empty()){
            tmpHead->next = st.top();
            st.pop();
            tmpHead = tmpHead->next;
        }
        tmpHead->next = tmpStart;

        return head;

    }
};

// after debug --> not worked
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head; // Handle edge cases: empty list or no reversal needed.
        }
        if(left==1 && left+1 == right){
            ListNode* tmpStart = head;
            head = head->next;
            head->next=tmpStart;
            return head;
        }
        
        ListNode* tmpStart = head;
        ListNode* tmpHead = head;
        stack<ListNode*> st;
        int l = 1, r = left;
        
        // Traverse the list until you reach the 'left' position.
        while (l != left) {
            if (l == left - 1)
                tmpHead = tmpStart;  // Store the node before the left position.
            tmpStart = tmpStart->next;
            l++;
        }
        
        ListNode* tmpEnd = tmpStart;
        
        // Traverse the list and push nodes into the stack until you reach the 'right' position.
        while (r != right+1) {
            st.push(tmpStart);
            tmpStart = tmpStart->next;
            // tmpStart = tmpStart->next;
            r++;
        }
            // st.push(tmpStart);
        
        // Now, 'tmpStart' points to the node at the 'right' position.
        // Pop nodes from the stack and connect them to reverse the sub-list.
        while (!st.empty()) {
            tmpHead->next = st.top();
            st.pop();
            tmpHead = tmpHead->next;
        }
        
        // Connect the end of the reversed sub-list to the remaining part of the list.
        tmpEnd->next = tmpStart;

        if (left == 1) {
            return tmpHead; // If reversing starts from the first node, return the new head.
        } else {
            return head; // Otherwise, return the original head.
        }
    }
};


// worked
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode* current = prev->next;
        
        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        return dummy.next;
    }
};
