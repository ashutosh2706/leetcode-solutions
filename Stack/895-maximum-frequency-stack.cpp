class FreqStack {
public:
    
    unordered_map<int, vector<int>> map;
    unordered_map<int, int> fmap;
    int maxf = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        fmap[val]++;
        if(fmap[val] > maxf) maxf = fmap[val];
        map[fmap[val]].push_back(val);
    }
    
    int pop() {
        int v = map[maxf].back();
        fmap[v]--;
        map[maxf].pop_back();
        if(map[maxf].size() == 0) maxf--;
        return v;
    }
};