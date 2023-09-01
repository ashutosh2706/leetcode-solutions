class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        auto ctoi = [](char c) {
            return c == '0' ? 0 : 1;
        };
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for(int i=0; i<n; ++i) {

            dp[0][i] = ctoi(mat[0][i]);
            if(dp[0][i]) ans = 1;
        }
        for(int i=0; i<m; ++i) {
            dp[i][0] = ctoi(mat[i][0]);
            if(dp[i][0]) ans = 1;
        }
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(mat[i][j] == '1') {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    ans = max(ans, dp[i][j] * dp[i][j]);
                }
            }
        }
        return ans;
    }
};