class Solution {
public:
    int dp[1001][1001];
    int solve(int ind, int target, vector<int> &nums) {
        if(target == 0) return 0;
        if(ind == nums.size() or nums[ind] > target) return -1e9;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = solve(ind+1, target-nums[ind], nums) + 1;
        int skip = solve(ind+1, target, nums);
        return dp[ind][target] = max(take, skip);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        sort(begin(nums), end(nums));
        memset(dp,-1,sizeof(dp));
        int len = solve(0,target,nums);
        return len <= 0 ? -1 : len;
    }
};