class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        vector<int> tmp;
        vector<vector<int>> res;
        for (auto& a : nums) {
            if (tmp.empty()) {
                tmp.push_back(a);
                continue;
            }
            if ((a - tmp.front()) <= k) {
                tmp.push_back(a);
            } else {
                tmp.clear();
                tmp.push_back(a);
            }
            if (tmp.size() == 3) {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res.size() == (nums.size() / 3) ? res : vector<vector<int>>{};
    }
};