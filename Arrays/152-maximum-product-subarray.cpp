class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pos = nums[0], max_neg = nums[0], ans = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            int pos = max({nums[i], nums[i] * max_pos, nums[i] * max_neg});
            max_neg = min({nums[i], nums[i] * max_pos, nums[i] * max_neg});
            max_pos = pos;
            ans = max(ans, max_pos);
        }
        return ans;
    }
};