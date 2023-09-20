class Solution {
private:
int dp[20001];
int solve(int ind, vector<int> &nums) {
    if(ind >= nums.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    int ans = nums[ind], i = ind+1;
    while(i < nums.size() and nums[i] == nums[ind]) ans += nums[i++];
    while(i < nums.size() and nums[i] == (nums[ind]+1)) i++;
    ans = max(ans + solve(i, nums), solve(ind+1, nums));
    return dp[ind] = ans;
}
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(begin(nums), end(nums));
        memset(dp,-1,sizeof(dp));
        return solve(0, nums);
    }
};