class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0, nums.size()-1, nums, 1) >= 0;
    }

    int dp[21][21][2];

    int solve(int l, int r, vector<int>& nums, int p1) {
        if(l > r) return 0;
        if(dp[l][r][p1] != -1) return dp[l][r][p1];
        int ans;
        if(p1) {
            int res = INT_MIN;
            res = max(res, nums[l] + solve(l+1, r, nums, 0));
            res = max(res, nums[r] + solve(l, r-1, nums, 0));
            ans = res;
        }else {
            int res = INT_MAX;
            res = min(res, solve(l+1, r, nums, 1) - nums[l]);
            res = min(res, solve(l, r-1, nums, 1) - nums[r]);
            ans = res;
        }
        return dp[l][r][p1] = ans;
    }

};