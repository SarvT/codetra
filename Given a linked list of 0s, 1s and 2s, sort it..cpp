Node* segregate(Node *head) {
        
        // Add code here
        if(!head) return head;
        vector<int>v;
        Node*ptr=head;
        while(ptr!=NULL)
        {
            v.push_back(ptr->data);
            ptr=ptr->next;
        }
        sort(v.begin(),v.end());
        Node*start=head;
        for(auto i:v)
        {
            start->data=i;
            start=start->next;
        }
        return head;
    }
