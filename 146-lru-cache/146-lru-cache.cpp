class dll {
public:
    int key, val;
    dll *next, *prev;
    
    dll() {
        next = nullptr;
        prev = nullptr;
    }
    
    dll(int key, int val){
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    dll *head, *tail;
    unordered_map<int, dll*> mp;
    int cap;
    
    void update(int key, int val){
        dll *node = mp[key];
        node->val = val;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void insert(int key, int val){
        if(cap > 0) {
            dll *node = new dll(key, val);
            mp[key] = node;

            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            cap--;
        }else{
            evict();
            insert(key, val);
        }
    }
    
    void evict() {
        dll *node = tail->prev;
        mp.erase(node->key);
        tail->prev = node->prev;
        node->prev->next = tail;
        cap++;
        delete node;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new dll();
        tail = new dll();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            dll *node = mp[key];
            update(key, node->val);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            update(key, value);
            return;
        }else{
            insert(key, value);
        }
    }
};