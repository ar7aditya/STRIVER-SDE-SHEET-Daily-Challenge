class MyHashSet {
public:
    unordered_map<int,int> mp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key] = 1;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
    
    bool contains(int key) {
        if(mp[key] == 1) return true;
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