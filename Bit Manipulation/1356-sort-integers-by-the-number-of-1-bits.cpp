class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [](int &a, int &b) {
            int b1 = __builtin_popcountll(a), b2 = __builtin_popcountll(b);
            return b1 == b2 ? a < b : b1 < b2;
        });
        return arr;
    }
};