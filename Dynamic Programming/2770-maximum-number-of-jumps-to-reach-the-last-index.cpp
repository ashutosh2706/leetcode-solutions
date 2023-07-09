class Solution {
public:
    int dp[1005];
    int solve(int ind, vector<int> &nums, int t) {
        
        if(ind == nums.size()-1) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int ans = INT_MIN;
        for(int i=ind+1; i < nums.size(); i++) {
            if((nums[i] - nums[ind]) >= -t and (nums[i] - nums[ind]) <= t) {
                ans = max(ans, 1+solve(i, nums, t));
            }
        }
        
        return dp[ind] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,nums,target);
        if(ans <= 0) return -1;
        return ans;
    }
};