class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 1, dp[1] = 1;
        for(int ind=2; ind<=n; ind++) {
            for(int i=ind-1; i>=1; i--) {
                dp[ind] = max(dp[ind], i * dp[ind - i]);
            }
            if(ind < n) dp[ind] = max(dp[ind], ind);
        }
        return dp[n];
    }
};