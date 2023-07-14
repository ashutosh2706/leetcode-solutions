class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        int ans = 0;
        unordered_map<int,int> dp;
        for(auto &i : nums) {
            int p = i-d;
            dp[i] = dp[p] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};