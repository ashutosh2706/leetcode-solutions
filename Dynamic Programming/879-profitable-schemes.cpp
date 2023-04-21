class Solution {
private:

const int mod = 1e9+7;

int dp[101][101][101];

int find(int ind, int n, int p, int minProfit, vector<int> &group, vector<int> &profit) {
    if(ind == group.size()) return p == minProfit;
    
    if(dp[ind][n][p] != -1) return dp[ind][n][p];    

    int ways = 0;
    if(group[ind] <= n) {
        ways = (ways + (find(ind+1, n - group[ind], min(p + profit[ind], minProfit), minProfit, group, profit) % mod)) % mod;
    }

    ways = (ways + (find(ind+1, n, p, minProfit, group, profit) % mod)) % mod;

    return dp[ind][n][p] = ways % mod;

}
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

    memset(dp, -1, sizeof(dp));
    return find(0, n, 0, minProfit, group, profit);

    }
};