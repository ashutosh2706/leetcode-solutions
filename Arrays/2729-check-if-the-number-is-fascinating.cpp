class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n);
        s += to_string(2*n);
        s += to_string(3*n);
        set<char> set;
        for(auto &c:s) {
            if(set.count(c)) return 0;
            set.insert(c);
        }
        return set.count('0') == 0;
    }
};