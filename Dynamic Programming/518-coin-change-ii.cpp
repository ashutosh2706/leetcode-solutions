class Solution {
public:
    int f(int ind, int amt, vector<int> &coins, vector<vector<int>> &dp) {
        if(ind == 0) {
            return amt%coins[0] == 0;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int take = 0;
        if(coins[ind] <= amt) take = f(ind, amt-coins[ind], coins, dp);
        return dp[ind][amt] = (take + f(ind-1, amt, coins, dp));
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return f(coins.size()-1, amount, coins, dp);    
    }
};