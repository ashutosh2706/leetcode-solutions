class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int N = nums.size(), ans = 0;
        vector<vector<int>> dp(N, vector<int>(1001));
        for(int i=0; i<N; i++) {
            for(int j=i+1; j<N; j++) {
                int diff = (nums[j] - nums[i]) + 500;
                dp[j][diff] = max(2, 1+dp[i][diff]);
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};