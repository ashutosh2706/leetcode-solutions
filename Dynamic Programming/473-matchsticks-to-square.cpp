class Solution {
public:
    vector<int> dp;

    bool solve(int ind, int k, int sum, int target, int mask, vector<int>& nums) {
        if(k == 0) return 1;
        if(sum == target) return solve(0, k-1, 0, target, mask, nums);

        if(dp[mask] != -1) return dp[mask];

        bool b = 0;
        for(int j = ind; j<nums.size(); j++) {
            if((mask & (1 << j)) == 0 and sum + nums[j] <= target) {
                b |= solve(j+1, k, sum+nums[j], target, mask|(1 << j), nums);
            }
        }
        return dp[mask] = b;

    }
    bool makesquare(vector<int>& nums, int k = 4) {
        int s = accumulate(begin(nums),end(nums),0);
        int N = nums.size();
        dp.resize((1 << N)-1, -1);
        if(s % k) return 0; 
        return solve(0, 4, 0, s/k, 0, nums);
    }
};