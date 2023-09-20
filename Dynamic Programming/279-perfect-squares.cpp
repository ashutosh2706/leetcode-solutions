class Solution {
public:
    int dp[10001];
    int solve(int n) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i=100; i>0; --i) {
            if((i*i) <= n)
            ans = min(ans, 1+solve(n-(i*i)));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};