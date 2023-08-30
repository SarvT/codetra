worked haha
Node* deleteNode(Node *head,int x)
{
    //Your code here
    // if(!head) return NULL;
    if(x==1){
        head = head->next;
        return head;
    }
    Node *tmp = head;
    while(tmp->next ){
        if(x==2 ){
            tmp->next=tmp->next->next;
            break;
        } else {
            x--;
            tmp = tmp->next;
        }
    }
    return head;
}
