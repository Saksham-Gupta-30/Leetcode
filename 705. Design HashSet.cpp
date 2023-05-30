class MyHashSet {
private:
    vector<bool> HS;
public:
    MyHashSet() : HS(1e6 + 1, false) {}
    
    void add(int key) {
        HS[key] = true;
    }
    
    void remove(int key) {
        HS[key] = false;
    }
    
    bool contains(int key) {
        return HS[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
