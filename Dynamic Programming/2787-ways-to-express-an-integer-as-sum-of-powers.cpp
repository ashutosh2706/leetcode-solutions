class Solution {
public:
    int dp[400][500];
    int mod = 1e9+7;
int solve(int n, int sum, int &num, int &x) {
    if(sum == num) return 1;

    if(sum > num or pow(n, x) > num) return 0;

    if(dp[n][sum] != -1) return dp[n][sum];

    int take = solve(n+1, sum + pow(n,x), num, x);
    int skip = solve(n+1, sum, num, x);

    return dp[n][sum] = ((take % mod+ skip % mod) % mod);
}
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n, x);
    }
};