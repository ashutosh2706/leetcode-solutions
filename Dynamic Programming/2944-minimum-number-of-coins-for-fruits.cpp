class Solution {
public:
    int dp1[1001][1002];
    int solve3(int ind, int free, vector<int> &nums) {
        if(ind == nums.size()) return 0;

        if(dp1[ind][free] != -1) return dp1[ind][free];

        int ans = 0;
        if(free) {
            int skip=solve3(ind+1, free-1, nums);
            int take=solve3(ind+1, ind+1, nums) + nums[ind];
            ans = min(take, skip);
        } else 
            ans = nums[ind] + solve3(ind+1, ind+1, nums);
        return dp1[ind][free] = ans;
    }
    int minimumCoins(vector<int>& prices) {
        memset(dp1,-1,sizeof(dp1));
        return solve3(0,0,prices);
    }
};
