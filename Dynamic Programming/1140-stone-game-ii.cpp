class Solution {
private:
int DP[2][201][201];

int func(int ind, vector<int>& nums, int M, int alice) {
    if(ind >= nums.size()) return 0;
    if(DP[alice][ind][M] != -1) return DP[alice][ind][M];
    int ans = 0;
    if(alice) {
        int sum = 0;
        for(int i=1; i<=2*M; i++) {
            if(ind+i-1 == nums.size()) break;
            sum += nums[ind+i-1];
            ans = max(ans, sum + func(ind+i, nums, max(M,i), 0));
        }
    }else {
        int sum = 1e9;
        for(int i=1; i<=2*M; i++) 
            sum = min(sum, func(ind+i, nums, max(M,i),1));
        ans = sum;
    }
    return DP[alice][ind][M] = ans;
}
public:
    int stoneGameII(vector<int>& piles) {
        memset(DP,-1,sizeof(DP));
        return func(0,piles,1,1);
    }
};