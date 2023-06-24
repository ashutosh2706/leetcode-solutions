class Solution {
public:
    int dp[21][10000];
    int solve(int i, int diff, vector<int>& rods) {
        if(i == rods.size()) {
            if(diff == 0) {
                return 0;
            }
            return INT_MIN;
        }

        if(dp[i][diff + 5000] != -1) return dp[i][diff + 5000];

        int a = solve(i+1, diff, rods);
        int b = rods[i] + solve(i+1, diff + rods[i], rods);
        int c = rods[i] + solve(i+1, diff - rods[i], rods);
        return dp[i][diff + 5000] = max({a,b,c});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, rods)/2;
    }
};