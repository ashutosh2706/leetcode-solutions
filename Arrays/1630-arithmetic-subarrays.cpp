class Solution {
public:

bool check(vector<int> &t) {
    sort(begin(t), end(t));
    int d = t[1] - t[0];
    for(int i=1; i<t.size(); ++i) {
        if((t[i] - t[i-1]) != d) return 0;
    }
    return 1;
}

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for(int i=0; i<l.size(); ++i) {
        vector<int> t;
        for(int x=l[i]; x<=r[i]; ++x) {
            t.push_back(nums[x]);
        }
        res.push_back(check(t));

    }
    return res;
    }
};