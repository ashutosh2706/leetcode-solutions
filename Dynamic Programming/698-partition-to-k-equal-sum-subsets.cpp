class Solution {
public:
    
    vector<int> dp;
    bool solve(int ind, int k, int sum, int target, int mask, vector<int>& nums) {

        if(k == 0) return 1;
        if(sum == target) return solve(0, k-1, 0, target, mask, nums); 

        if(dp[mask] != -1) return dp[mask];

        bool b = 0;
        for(int j=ind; j<nums.size(); j++) {
            if((mask & (1<<j)) or (sum + nums[j]) > target) continue;
            b |= solve(j+1, k, sum + nums[j], target, (mask | (1<<j)), nums);
        }
        return dp[mask] = b;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        int s = accumulate(begin(nums),end(nums),0);
        dp.resize((1<<N), -1);
        if(s%k) return 0;
        return solve(0,k,0,s/k,0,nums);
    }
};