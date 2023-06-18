class Solution {
public:

    unsigned int mod = 1e9+7;
    int dp[16][16384];

    int f(int prev, int i, vector<int>& v, int mask) {
        if(i == v.size()) return 1;
        if(dp[prev+1][mask] != -1) return dp[prev+1][mask];
 
        int ans = 0;
        for(int j=0; j<v.size(); j++) {
            if(prev == -1 or ((mask & (1 << j)) == 0) and prev != j and (v[prev] % v[j] == 0 or v[j] % v[prev] == 0)) {
                ans += f(j, i+1, v, mask | (1 << j));
                ans %= mod;
            }
        }
        return dp[prev+1][mask] = ans;
    }

    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return f(-1,0,nums,0);
    }
};