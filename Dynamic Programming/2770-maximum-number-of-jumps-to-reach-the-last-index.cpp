class Solution {
private:
    int dp[1005][1005];

int solve(int ind, int prev, vector<int>& nums, int target) {
    if(ind >= nums.size()) return INT_MIN;
    if(ind == nums.size() - 1) 
    {   
        if((nums[ind] - nums[prev]) >= -target and (nums[ind] - nums[prev]) <= target)
        return 1;
        else return INT_MIN;
    }

    if(dp[ind][prev] != -1) return dp[ind][prev];
    int ans = INT_MIN;

    if((nums[ind] - nums[prev]) >= -target and (nums[ind] - nums[prev]) <= target) {
        // out(ind) out(prev)
        ans = max(ans, 1 + solve(ind+1, ind, nums, target));
    }

    ans = max(ans, 0 + solve(ind+1, prev, nums, target));
    return dp[ind][prev] = ans;
}
public:
    
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int x = solve(1,0,nums,target);
        if(x <= 0) return -1;
        return x;
    }
};