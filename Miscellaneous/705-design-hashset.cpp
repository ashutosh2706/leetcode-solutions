class MyHashSet {
public:
    int set[1000001];
    MyHashSet() {
        memset(set,0,sizeof(set));
    }
    
    void add(int key) {
        set[key] = 1;
    }
    
    void remove(int key) {
        set[key] = 0;
    }
    
    bool contains(int key) {
        return set[key];
    }
};