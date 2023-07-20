class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node (int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode) {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node* delNode) {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int _key) {
        if (mp.find(_key) != mp.end()) {
            node* resNode = mp[_key];
            int res = resNode->val;
            deleteNode(resNode);
            mp.erase(_key);
            addNode(resNode);
            mp[_key] = resNode;
            return res;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        if (mp.find(_key) != mp.end()) {
            node* existingNode = mp[_key];
            mp.erase(_key);
            deleteNode(existingNode);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(_key, value));
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
