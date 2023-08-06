class Solution {
public:
int dp[101][101];

int solve(int s, int e, int sum, vector<int> &nums, int &m) {
    if(s==e) return 1;
    if(e < s or sum < m) return 0;

    if(dp[s][e] != -1) return dp[s][e];
    int ans = 0, lc = 0;

    for(int i=s; i<=e; ++i) {
        ans = ans or (solve(s, i-1, lc, nums, m)
            and solve(i, e, sum - lc, nums, m));
        lc += nums[i];
    }
    return dp[s][e] = ans;
}

    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() <= 2) return 1;
        int sum = accumulate(begin(nums), end(nums), 0);
        memset(dp, -1, sizeof(dp));
        return solve(0, nums.size()-1, sum, nums, m);
    }
};