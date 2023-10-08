// not worked
class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        struct Node* ins;
        ins->data=data;
        if(head->data > data){
            ins->next = head;
            return ins;
        }
        struct Node* prev=head;
        struct Node* tmp=prev->next;
        while(tmp->next){
            if(tmp->data>data){
                prev->next = ins;
                ins->next = tmp;
            }
            if(tmp->next==NULL){
                tmp->next=ins;
                ins->next=NULL;
                return head;
            }
        }
        return head;
        
        
    }
};



// worked
class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node * newnode = new Node(data);
        Node * prev = nullptr;
        Node *Itr = head;
        if(data <= head -> data){
            newnode -> next = head;
            head = newnode;
            return head;
        }
    
         while(data > Itr -> data){
             prev = Itr;
            Itr = Itr -> next;
            if(Itr -> next == NULL && data > Itr -> data){
                Itr -> next = newnode;
                return head;
            }
         }
         newnode -> next = Itr;
         prev -> next = newnode;
         
        
      return head;  
        
        
    }
};
