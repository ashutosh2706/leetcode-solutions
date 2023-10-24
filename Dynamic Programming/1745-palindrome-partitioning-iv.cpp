class Solution {
public:
int n;
int palin(int a, string &s, int b) {
    while(a <= b) {
        if(s[a] != s[b]) return 0;
        a++; b--;
    }
    return 1;
}
int dp[2001][3];
int solve(int curr, string &s, int splits) {
    if(curr >= n) return splits == 0;
    if(splits == 0) return palin(curr, s, n-1);
    if(dp[curr][splits] != -1) return dp[curr][splits];
    int ans = 0;
    for(int idx=curr; idx < n-1; ++idx) {
        if(palin(curr, s, idx)) 
            ans = ans or solve(idx+1, s, splits-1);
    }
    return dp[curr][splits] = ans;
}
    bool checkPartitioning(string& s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,s,2);
    }
};