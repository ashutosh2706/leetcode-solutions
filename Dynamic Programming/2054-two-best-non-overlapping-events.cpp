// DP + Binary Search

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind, int k, vector<vector<int>>& e) {
        if(ind == e.size() or k == 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        int skip = solve(ind+1, k, e);
        
        int x = upper_bound(begin(e)+ind+1, end(e), vector<int>{e[ind][1], INT_MAX, INT_MAX}) - begin(e);

        int take = e[ind][2] + solve(x, k-1, e);
        return dp[ind][k] = max(skip, take);
    }
    int maxTwoEvents(vector<vector<int>>& e) {
        sort(begin(e),end(e));
        dp.resize(e.size()+1, vector<int>(3,-1));
        return solve(0,2,e);

    }
};