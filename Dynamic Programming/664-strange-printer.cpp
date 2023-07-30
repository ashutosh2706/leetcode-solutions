class Solution {
public:
    int solve(int i, int j, string &s) {
        if(i == j) {
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<j; k++) {
            mini = min(mini, solve(i, k, s) + solve(k+1, j, s));
        }

        return dp[i][j] = s[i] == s[j] ? (mini - 1) : mini;
    }

    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0, s.length()-1, s);
    }
    int dp[101][101];
};