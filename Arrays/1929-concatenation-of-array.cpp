class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(begin(nums), end(nums));
        for(auto &a:nums) res.push_back(a);
        return res;
    }
};