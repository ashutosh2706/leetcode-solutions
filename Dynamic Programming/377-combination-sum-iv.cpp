class Solution {
private:
    int dp[1001];
    int solve(vector<int> &nums, int target) {
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ways = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > target) break;
            ways += solve(nums, target-nums[i]);
        }
        return dp[target] = ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        memset(dp,-1,sizeof(dp));
        return solve(nums,target);

    }
};