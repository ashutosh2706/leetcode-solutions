class Solution {
public:
int dp[101][101];
int solve(int i1, int i2, string &s1, string &s2, string &s3) {

    if(i1+i2 == s3.length()) return 1;

    if(dp[i1][i2] != -1) return dp[i1][i2];
    int ans = 0;
    if(s1[i1] == s3[i1+i2]) {
        ans = ans or solve(i1+1,i2,s1,s2,s3);
    }
    if(s2[i2] == s3[i1+i2]) {
        ans = ans or solve(i1,i2+1,s1,s2,s3);
    }

    return dp[i1][i2] = ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length()+s2.length()) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2,s3);
    }
};