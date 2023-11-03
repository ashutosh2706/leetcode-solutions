class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cnt = 0, cval = 1;
        vector<int> op;
        for(auto &a : target) {
            while(a > cval) {
                op.emplace_back(1);
                cval++;
                cnt++;
            }
            while(cnt > 0) { op.emplace_back(0); cnt--; }
            op.emplace_back(1);
            if(a == cval) ++cval;
        }
        vector<string> res;
        for(auto &a : op) {
            if(a) res.push_back("Push");
            else res.push_back("Pop");
        }
        return res;
    }
};