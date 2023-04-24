class Solution {
public:
int dp[501][501];
int find(string &s1, string &s2, int i1, int i2) {
    if(i1 == s1.length() && i2 == s2.length()) return 0;
    else if(i1 == s1.length()) return 1 + find(s1,s2,i1,i2+1);
    else if(i2 == s2.length()) return 1 + find(s1,s2,i1+1,i2);
    if(dp[i1][i2] != -1) return dp[i1][i2];
    if(s1[i1] == s2[i2]) return find(s1,s2,i1+1,i2+1);
    
    return dp[i1][i2] = min(1+find(s1,s2,i1+1,i2), 1 + find(s1,s2,i1,i2+1));
}
    int minDistance(string s1, string s2) {
    memset(dp,-1,sizeof(dp));
    return find(s1,s2,0,0);        
    }
};