class LRUCache {
public:
    int cap, time = 0;
    int last[10001];
    map<pair<int,int>, int> map;
    LRUCache(int capacity) {
        this->cap=capacity;
        memset(last,-1,sizeof(last));
    }
    
    int get(int key) {
        int t=last[key];
        if(t==-1) return t;
        int val = map[{t,key}];
        map.erase({t,key});
        last[key] = time++;
        map[{last[key], key}]=val;
        return val;
    }
    
    void put(int key, int value) {
        if(last[key] ==- 1) {
            // insert into cache
            if(map.size() == cap) {
                auto p = *map.begin();
                last[p.first.second] = -1;
                map.erase(p.first);
                last[key] = time++;
                map[{last[key], key}]=value;
            } else {
                last[key]=time++;
                map[{last[key], key}]=value;
            }
        } else {
            // update cache
            map.erase({last[key],key});
            last[key]=time++;
            map[{last[key], key}]=value;
        }
    }
};
