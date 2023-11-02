class Solution {
public:
    long long dp[100001];
    long long solve(int ind, vector<int>& nums, int k) {
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        if(ind + 2 >= nums.size()) return 0;
        long long ans = min({
            max(0, k-nums[ind]) + solve(ind+1, nums, k),
            max(0, k-nums[ind+1]) + solve(ind+2, nums, k),
            max(0, k-nums[ind+2]) + solve(ind+3, nums, k)
        });

        return dp[ind] = ans;

    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k);
    }
};

static auto var = []() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
}();