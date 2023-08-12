class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;
        vector<long long> dp(n);
        dp[n-1] = 1;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] == 1) dp[j] = 0;
                else if(j == n-1) continue;
                else dp[j] = dp[j] + dp[j+1];
            }
        }
        return dp[0];
    }
};