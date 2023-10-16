class Solution {
public:
    long long dp[501][501];
    long long solve(int ind, int wall, vector<int> &cost, vector<int> &time) {
        if(wall <= 0) return 0;
        if(ind == cost.size()) return INT_MAX;
        if(dp[ind][wall] != -1) return dp[ind][wall];
        long long paint = solve(ind+1, wall-1-time[ind], cost, time) + cost[ind];
        long long skip = solve(ind+1, wall, cost, time);
        return dp[ind][wall] = min(paint, skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return solve(0,cost.size(), cost, time);
    }
};