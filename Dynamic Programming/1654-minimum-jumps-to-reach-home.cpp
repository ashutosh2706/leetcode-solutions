class Solution {
public:
    int dp[7000][2];
    int f(int ind, int prev, unordered_set<int> &set, int &x, int &a, int &b) {
        if(ind == x) return 0;
        if(ind > 6000 or set.count(ind) or ind < 0) return 1e9;

        if(dp[ind][prev] != -1) return dp[ind][prev];

        
        dp[ind][prev] = 1 + f(ind+a,1,set,x,a,b);
        if(prev) {
            dp[ind][prev] = min(dp[ind][prev], 1 + f(ind-b, 0, set,x,a,b));
        }

        return dp[ind][prev];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        memset(dp,-1,sizeof(dp));
        unordered_set<int> set(begin(forbidden), end(forbidden));
        int ret = f(0,1,set,x,a,b);
        if(ret >= 1e9) return -1;
        return ret;
    }
};