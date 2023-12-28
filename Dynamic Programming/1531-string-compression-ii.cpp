class Solution {
public:
    int dp[101][101];
    int solve(int ind, int k, string &s) {
        if(k < 0) return 1e4;
        if(ind >= s.length() || (s.length()-ind) <= k) return 0;
        
        if(dp[ind][k] != -1) return dp[ind][k];
        int del = solve(ind+1, k-1, s);
        int take = INT_MAX, deleted = 0, f = 0, add = 0;
        for(int j=ind; j<s.length() && deleted <= k; ++j) {
            if(s[j] == s[ind]) {
                ++f;
                if(f == 2 or f == 10 or f == 100) {
                    ++add;
                }
            } else ++deleted;
            take = min(take, 1 + add + solve(j+1, k-deleted, s));
        }
        return dp[ind][k] = min(del, take);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0, k, s);
    }
};