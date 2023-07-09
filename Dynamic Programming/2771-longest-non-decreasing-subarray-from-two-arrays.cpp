class Solution {
public:
    int dp[100005][3];
    int solve(int ind, int prev, vector<int> &nums1, vector<int> &nums2) {
        if(ind >= nums1.size()) return 0;
            
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int ans = 0;
        if(prev == -1) {
            ans = max(ans, 0+solve(ind+1,-1,nums1,nums2));
            ans = max({ans, 1 + solve(ind+1, 0, nums1, nums2), 1 + solve(ind+1, 1, nums1, nums2)});
        } else if(prev == 0) {
            if(nums1[ind] >= nums1[ind-1]) {
                ans = max(ans, 1+solve(ind+1,0,nums1,nums2));
            }
            if(nums2[ind] >= nums1[ind-1]) {
                ans = max(ans, 1+solve(ind+1, 1, nums1, nums2));
            }
        } else {
            if(nums1[ind] >= nums2[ind-1]) {
                ans = max(ans, 1+solve(ind+1,0,nums1,nums2));
            }
            if(nums2[ind] >= nums2[ind-1]) {
                ans = max(ans, 1+solve(ind+1,1,nums1,nums2));
            }
        }
        return dp[ind][prev+1] = ans;
        
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums1,nums2);
        
    }
};