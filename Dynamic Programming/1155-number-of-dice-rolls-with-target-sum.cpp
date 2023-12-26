class Solution {
public:

    int K, mod=1e9+7;
    int DP[31][1001];
    int F(int d, int target) {
        if(target < 0) return 0;
        if(d == 0) return target == 0;
        if (DP[d][target] != -1)
            return DP[d][target];
        int cnt = 0;
        for (int i = 1; i <= K; ++i) {
            cnt = (cnt + F(d - 1, target - i) % mod) % mod;
        }

        return DP[d][target] = cnt;
    }
    int numRollsToTarget(int n, int k, int target) {
        K = k;
        memset(DP, -1, sizeof(DP));
        return F(n, target)%mod;
    }
};