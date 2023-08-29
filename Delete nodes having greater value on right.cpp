// not worked
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next) return head;
        // int n=head->data;
        // if(head->data<head->next->data) head = head->next;
        // if(!head->next) return head;
        if(head->data<head->next->data) head = head->next;
        if(!head->next) return head;
        Node *prev = head;
        Node *tmp = head->next;
        while(tmp->next){
            if(tmp->data<tmp->next->data) {
                prev->next = tmp->next;
                tmp = prev->next;
            }
            else {
                // prev = tmp;
                tmp = tmp->next;
            }
            
        }
        return head;
    }
    
};

// worked
class Solution
{
    public:
    Node* reverse(Node *head)
    {
        Node *prev = NULL,*curr = head,*dum = head;
        while(curr != NULL)
        {
            dum = dum->next;
            curr->next = prev;
            prev = curr;
            curr = dum;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node *u= reverse(head);
        Node *temp = u,*ans = u,*var=u;
        while(temp != NULL)
        {
            if(var->data <=temp->data && var!= temp)
            {
                var->next = temp;
                var = temp;
                temp = temp->next;
            }
           
            else
            temp = temp->next;
            
        }
        var->next = NULL;
       
        return reverse(ans);
    }
    
};
