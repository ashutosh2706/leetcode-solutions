class Solution {
public:
    bool canIWin(int m, int d) {
        if(d == 0) return 1;
        int sum = (m*(m+1))/2;
        if(d > sum) return 0;
        memset(dp,-1,sizeof(dp));
        return dfs(d, m, 0);
    }
    
    int dp[1<<21];
    int dfs(int total, int choosable, int mask) {
        if(total <= 0) return 0;

        if(dp[mask] != -1) return dp[mask];

        for(int i=0; i<choosable; i++) {
            if((mask & (1 << i)) == 0 and !dfs(total-(i+1), choosable, mask | (1 << i))) {
                dp[mask] = 1;
                return 1;
            }
        }
        return dp[mask] = 0;

    }
};