class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind, int len) {
        if(len == 0) return 1;
        if(dp[ind][len] != -1) return dp[ind][len];
        int cnt = 0;
        for(int i=ind; i<=5; ++i) {
            cnt += solve(i,len-1);
        }
        return dp[ind][len] = cnt; 
    }
    int countVowelStrings(int n) {
        dp.resize(6, vector<int>(51,-1));
        return solve(1,n);

    }
};