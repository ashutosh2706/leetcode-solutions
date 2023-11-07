class Solution {
public:
    int slots;
    int dp[10][524288][3];
    int solve(int ind, vector<int>& nums, int mask, int rem) {
        if(ind > slots) return 0;
        if(dp[ind][mask][rem] != -1) return dp[ind][mask][rem];
        int ans = solve(ind+1, nums, mask, 2);

        for(int i=0; i<nums.size(); ++i) {

            if((mask & (1<<i)) == 0) {
                if(rem > 1) 
                    ans = max(ans, (ind & nums[i]) + solve(ind, nums, mask | (1 << i), rem-1));
                else 
                    ans = max(ans, (ind & nums[i]) + solve(ind+1, nums, mask | (1 << i), 2));
            } 
        }

        return dp[ind][mask][rem] = ans;

    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        slots = numSlots;
        memset(dp,-1,sizeof(dp));
        return solve(1, nums, 0, 2);
    }
};