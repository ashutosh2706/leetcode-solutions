class Solution {
public:
long long dp[100001][2];
long long solve(int ind, int odd, vector<int> &nums, int &x) {

    if(ind >= nums.size()) return 0;
    if(dp[ind][odd] != -1) return dp[ind][odd];
    long long ans =  nums[ind] + solve(ind+1,nums[ind]&1,nums,x);
    (nums[ind]&1) == odd ? ans -= 0 : ans -= x;
    if(ind > 0) {
        ans = max(ans, solve(ind+1, odd, nums, x));
    }
    return dp[ind][odd] = ans;
}

    long long maxScore(vector<int>& nums, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums[0]&1, nums, x);
    }
};