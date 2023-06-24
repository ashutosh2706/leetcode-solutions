class Solution {
int dp[3][51][51][51];
public:
    int solve(char prev, int a, int b, int c) {
    if(dp[prev-'a'][a][b][c] != -1) return dp[prev-'a'][a][b][c];
    int ans =0;
    if(prev == 'a') {
        if(b > 0)
        ans = max(ans, 2+solve('b', a, b-1, c));
    } else if(prev == 'b') {
        if(a > 0) 
            ans = max(ans, 2+solve('a', a-1,b,c));
        if(c > 0)
            ans = max(ans, 2+solve('c', a,b,c-1));
    } else {
        if(c > 0)
            ans = max(ans, 2+solve('c', a,b,c-1));
        if(a > 0)
            ans = max(ans, 2+solve('a', a-1,b,c));
    }
    return dp[prev-'a'][a][b][c] = ans;
}
    int longestString(int a, int b, int c) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        ans = max(ans, 2+solve('a', a-1,b,c));
        ans = max(ans, 2+solve('b', a,b-1,c));
        ans = max(ans, 2+solve('c', a,b,c-1));
        return ans;
    }
};