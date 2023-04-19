class Solution {
private:
    int f(int ind, vector<int>& nums, vector<int> &dp, int sz) {
        if(ind >= sz) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(f(ind+2, nums,dp,sz) + nums[ind], f(ind+1,nums,dp,sz));
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sz = nums.size();
        vector<int> dp(sz, -1);
        int l = f(0, nums, dp, sz-1);
        vector<int> dp2(sz+1, -1);
        int r = f(1, nums, dp2, sz);
        return max(l,r);
    }
};