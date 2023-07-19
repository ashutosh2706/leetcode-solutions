class SummaryRanges {
public:
    set<vector<int>> set;
    SummaryRanges() {}
    
    void addNum(int num) {

    if(set.empty()) { set.insert({num,num}); return; }
    auto p = set.upper_bound({num, INT_MAX});
    if(p == begin(set)) {
        if((*p)[0] - 1 == num) {
            vector<int> vec = *p;
            set.erase(vec);
            vec[0] = num;
            set.insert(vec);

        } else set.insert({num,num});

    } else if(p == end(set)) {
        
        auto it = prev(p);
        vector<int> vec = *it;
        if(vec[1] + 1 == num) {
            set.erase(vec);
            vec[1] = num;
            set.insert(vec);
        } else if(!(num >= vec[0] and num <= vec[1])) set.insert({num,num});

    } else {
        auto it = prev(p);
        vector<int> vec0 = *it;
        it = p;
        vector<int> vec1 = *it;
        if(!(num >= vec0[0] and num <= vec0[1])) {

            if(vec0[1] + 2 == vec1[0]) {
                set.erase(vec0);
                set.erase(vec1);
                set.insert({vec0[0], vec1[1]});
            } else if(vec0[1] + 1 == num) {

                set.erase(vec0);
                set.insert({vec0[0], num});
            } else if(vec1[0] - 1 == num) {
                set.erase(vec1);
                set.insert({num, vec1[1]});
            } else set.insert({num,num});
        }
    }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> v(begin(set),end(set));
        sort(begin(v),end(v));
        return v;
    }
};