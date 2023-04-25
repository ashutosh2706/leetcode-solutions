class SmallestInfiniteSet {
public:
    set<int> S;
    SmallestInfiniteSet() {
        for(int i=1; i<=1001; i++) S.insert(i);
    }
    
    int popSmallest() {
        int ret = *(begin(S));
        S.erase(ret);
        return ret;
    }
    
    void addBack(int num) {
        S.insert(num);
    }
};