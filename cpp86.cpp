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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* temp1=new ListNode();
        ListNode* small=temp1;

        ListNode* temp2=new ListNode();
        ListNode* big=temp2;

        ListNode* curr = head;

        while(curr){
            if(curr->val<x){
                small->next=curr;
                small=small->next;
            } else{
                big->next=curr;
                big=big->next;
            }
            curr=curr->next;
        } 
        big->next=NULL;
        small->next=temp2->next;

        head=temp1->next;

        return head;

    }
};
