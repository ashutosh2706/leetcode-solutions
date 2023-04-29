class Solution {
private:
    int lcs(vector<int>& n1, vector<int>& n2, int i, int j, int &ans, vector<vector<int>>&dp){
        if (i >= n1.size() || j >= n2.size()) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
        int cur = 0;
        if (n1[i] == n2[j]){
            cur = lcs(n1, n2, i + 1, j + 1, ans, dp)+1; 
        }
        lcs(n1, n2, i, j + 1, ans, dp);
        lcs(n1, n2, i + 1, j, ans, dp);
        ans = max(ans, cur);
        return dp[i][j] = cur;
    } 
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = 0;
        lcs(nums1, nums2, 0, 0, ans, dp);
        return ans;
    }
};