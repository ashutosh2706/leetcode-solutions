class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return (double)0;
        
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = poured;
        for(int i=0; i<=query_row; ++i) {
            for(int j=0; j<=i; ++j) {
                if(dp[i][j] > 1) {
                    double d = (double)(dp[i][j] - 1.0)/(double)2.0;
                    dp[i+1][j] += d;
                    dp[i+1][j+1] +=d;
                    dp[i][j] = 1;
                }
            }
        }

        return dp[query_row][query_glass];

    }
};