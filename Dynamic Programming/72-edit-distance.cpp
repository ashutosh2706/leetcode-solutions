class Solution {
public:
    int minDistance(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(max(n1, n2)+2, vector<int> (max(n1,n2)+2, 1e9)); 
    dp[n1][n2] = 0;

    for(int p1=n1; p1>=0; p1--) {
        
        for(int p2=n2; p2>=0; p2--) {

            int ans = INT_MAX;
            if(p1 == n1 && p2 == n2) continue;
            if(p2 == n2) {
                ans = 1 + dp[p1 + 1][p2];
            }else if(p1 < n1 && s1[p1] == s2[p2]) ans = dp[p1+1][p2+1]; // no operations done if both chars match 
            else {
                // INSERT
                ans = min(ans, 1+dp[p1][p2+1]);
                // update
                if(p1 < s1.length())
                ans = min(ans, 1+dp[p1+1][p2+1]);
                // delete
                if(p1 < s1.length())
                ans = min(ans, 1+dp[p1+1][p2]);
            }
            dp[p1][p2] = ans;
        }
    }

    return dp[0][0];
    }
};