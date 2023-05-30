class MyHashSet {
public:
    unordered_set<int> mp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp.insert(key);
    }
    
    void remove(int key) {
        mp.erase(key);
    }
    
    bool contains(int key) {
        if(mp.find(key) != mp.end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */