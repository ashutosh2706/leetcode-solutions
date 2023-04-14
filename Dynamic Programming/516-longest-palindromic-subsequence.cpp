// Time: O(n^2)
// Space: O(n^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string r = s;
        reverse(begin(r), end(r));
        vector<vector<int>> dp(s.length() + 1, vector<int> (s.length() + 1));
        for(int i=s.length()-1; i>=0; i--) {
            for(int j=r.length()-1; j>=0; j--) {
                if(s[i] == r[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};