class SnapshotArray {
public:
    unordered_map<int, map<int,int>> map;
    int id = 0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        map[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it = map[index].upper_bound(snap_id);
        if(it == map[index].begin()) return 0;
        return std::prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */