class Solution {
public:

    int dp[1001][1001];

    int solve(int i1, int i2, string &s1, string &s2) {
        if(i1 >= s1.length() and i2 >= s2.length()) return 0;
        if(i1 >= s1.length()) {
            int sum = 0;
            while(i2 < s2.length()) {
                sum += (int)s2[i2];
                i2++;
            }
            return sum;
        }
        if(i2 >= s2.length()) {
            int sum = 0;
            while(i1 < s1.length()) {
                sum += (int)s1[i1];
                i1++;
            }
            return sum;
        }

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s1[i1] == s2[i2]) return dp[i1][i2] = solve(i1+1,i2+1,s1,s2);
        int ans = min((int)s1[i1] + solve(i1+1,i2,s1,s2), (int)s2[i2] + solve(i1,i2+1,s1,s2));
        return dp[i1][i2] = ans;    
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};