not worked
Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map<int, int> mp;
     Node *demo = head;
     Node *prev;
     while(demo!=NULL){
         prev = demo;
         demo = demo->next;
         if(mp.find(demo->data)){
            demo = demo->next;
            prev->next = demo; 
         }
         mp.push_back(demo->data);
     }
     return head;
    }

worked
Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int> mp;
     mp.insert(head->data);
     Node *demo = head;
     
     while(demo!=NULL&&demo->next!=NULL){
         if(mp.find(demo->next->data)!=mp.end()){
            Node *nxt = demo->next;
            demo->next = demo->next->next;
            free(nxt);
         }else{
             mp.insert(demo->next->data);
             demo = demo->next;
         }
     }
     return head;
