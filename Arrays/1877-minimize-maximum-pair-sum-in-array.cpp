class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0, n = nums.size();
        for(int i=0; i<n; ++i) {
            ans = max(ans, nums[i] + nums[n-1-i]);
        }
        return ans;
    }
};