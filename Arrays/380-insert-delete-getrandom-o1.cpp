class RandomizedSet {
private:

unordered_map<int, int> map;
vector<int> nums;

public:
    unordered_set<int> st;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(map.count(val)) return 0;
        nums.push_back(val);
        map[val] = nums.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        if(map.count(val) == 0) return 0;
        int ind = map[val];
        map[nums.back()] = ind;
        nums[ind] = nums.back();
        nums.pop_back();
        map.erase(val);
        return 1;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */