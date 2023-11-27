class Solution {
public:
    vector<vector<int>> adj {{4,6}, {6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
    
    int mod = 1e9+7, dp[10][5001];
    int solve(int node, int len) {
        if(len <= 0) return 1;
        if(dp[node][len] != -1) return dp[node][len];
        int ans = 0;
        for(auto &a : adj[node]) {
            ans = (ans + solve(a, len-1)) % mod;
        }
        return dp[node][len] = ans%mod;
    }

    int knightDialer(int n) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<=9; ++i) {
            ans = (ans + solve(i, n-1))%mod;
        }
        return ans;
    }
};
