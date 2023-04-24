class MyHashMap {
public:
    
    int MAP[1000001];

    MyHashMap() {
        memset(MAP, -1, sizeof(MAP));        
    }
    
    void put(int key, int value) {
        MAP[key] = value;    
    }
    
    int get(int key) {
        return MAP[key];
    }
    
    void remove(int key) {
        MAP[key] = -1;
    }
};