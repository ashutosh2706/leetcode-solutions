class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int l = 0, r = n;
        for(; r < nums.size(); l++,r++) {
            res.push_back(nums[l]);
            res.push_back(nums[r]);
        }
        return res;
    }
};