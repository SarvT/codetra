
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        stack<Node*> st;
        Node* tmp=odd;
        while(tmp || tmp->next || tmp->next->next){
            st.push(tmp->next);
            tmp->next=tmp->next->next;
        }
        while(!st.empty()){
            tmp->next=st.top();
            st.pop();
        }
        tmp->next=NULL;
        
    }
};

// worked

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
       
       Node *prev=NULL;
    Node *curr=head;
       
        while(curr!=NULL)
        {
             Node *next=curr->next;
             curr->next=prev;
             
             prev=curr;
             curr=next;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        Node *curr1=odd;
        Node *curr2=odd->next;
        Node *c=odd->next;
         
        while(curr1!=NULL && curr2!=NULL&&curr1->next!=NULL &&curr2->next!=NULL)
        {
            curr1->next=curr2->next;
            curr1=curr1->next;
            curr2->next=curr1->next;
            curr2=curr2->next;
        }
        struct Node* d=reverseList(c);
        curr1->next=d;
    }
};
