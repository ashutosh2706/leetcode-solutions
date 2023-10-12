class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2) {

        if(i == nums1.size() or j == nums2.size()) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        int val = nums1[i]*nums2[j] + solve(i+1,j+1,nums1,nums2);
        int t = max({solve(i+1,j,nums1,nums2), solve(i,j+1,nums1,nums2)});
        return dp[i][j] = max({nums1[i]*nums2[j], val, t});


    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};