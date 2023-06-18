class Solution {
public:
    unsigned int mod = 1e9+7;
    int dp[1001][1001];
    int DFS(int i, int j, int prev, vector<vector<int>>& grid) {
        if(i < 0 or j < 0 or i == grid.size() or j == grid[0].size()) return 0;
        if(grid[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int paths = 1;
        paths = (paths + DFS(i+1, j, grid[i][j], grid)) % mod;
        paths = (paths + DFS(i-1, j, grid[i][j], grid)) % mod;
        paths = (paths + DFS(i, j+1, grid[i][j], grid)) % mod;
        paths = (paths + DFS(i, j-1, grid[i][j], grid)) % mod;
        return dp[i][j] = paths;
    }

    int countPaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                ans = (ans + DFS(i,j,0,grid)) % mod; 
            }
        }
        return ans;
    }
};