// Leet
class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* copy(Node* ptr){
        if(!ptr) return NULL;
        if(m.count(ptr)) return m[ptr];

        Node* sol = new Node(ptr->val);
        m[ptr] = sol;
        sol->next = copyRandomList(ptr->next);
        sol->random = copyRandomList(ptr->random);
        return sol;
    }
    Node* copyRandomList(Node* head) {
        return copy(head);
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(m.count(head)) return m[head];

        Node* sol = new Node(head->val);
        m[head] = sol;
        sol->next = copyRandomList(head->next);
        sol->random = copyRandomList(head->random);
        return sol;
    }
};
