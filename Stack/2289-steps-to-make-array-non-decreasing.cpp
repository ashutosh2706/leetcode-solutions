class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        vector<int> vec, dp(nums.size(),0);
        for(int i=nums.size()-1; i>=0; i--) {
            while(vec.size() and nums[i] > nums[vec.back()]) {
                dp[i] = max(++dp[i], dp[vec.back()]);
                vec.pop_back();
                ans = max(ans, dp[i]);
            }
            vec.push_back(i);
        }
        return ans;
    }
};