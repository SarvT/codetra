class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;    
        tail->prev = head;    
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        node *nde = m[key];
        remove(nde);
        add(nde);
        return nde->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
        node *oldNode = m[key];
        remove(oldNode);
    }
    
    node *nde = new node(key, value);
    m[key] = nde;
    add(nde);
    
    if (m.size() > cap) {
        node *nodeToDelete = head->next;
        remove(nodeToDelete);
        m.erase(nodeToDelete->key);
    }
        
    }

    void add(node *nde) {
        node *previousEnd = tail->prev;
        previousEnd->next = nde;
        nde->prev = previousEnd;
        nde->next = tail;
        tail->prev = nde;
    }
    
    void remove(node *nde) {
        nde->prev->next = nde->next;
        nde->next->prev = nde->prev;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
