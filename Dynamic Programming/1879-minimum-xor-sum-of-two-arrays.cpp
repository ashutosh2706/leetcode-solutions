class Solution {
public:
    int dp[15][32768];
    int solve(int ind, vector<int> &nums1, vector<int> &nums2, int mask) {
        if(ind == nums1.size()) return 0;
        if(dp[ind][mask] != -1) return dp[ind][mask];
        int ans = INT_MAX;
        for(int i=0; i<nums2.size(); ++i) {
            if((mask & (1 << i)) == 0) {
                ans = min(ans, (nums2[i]^nums1[ind]) + solve(ind+1, nums1, nums2, mask | (1 << i)));
            }
        }
        return dp[ind][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0, nums1, nums2, 0);
    }
};