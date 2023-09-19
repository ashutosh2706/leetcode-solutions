class Solution {
public:
    int dp[201][10005];
    int solve(int ind, vector<int> &nums, int sum) {
        if(sum == 0) return 1;
        if(ind >= nums.size() or sum < 0) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int ans = solve(ind+1, nums, sum-nums[ind]);
        ans = ans or solve(ind+1, nums, sum);
        return dp[ind][sum] = ans;
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum&1) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0, nums,sum/2);
    }
};