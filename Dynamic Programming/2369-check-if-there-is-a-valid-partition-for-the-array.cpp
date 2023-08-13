class Solution {
public:
int dp[100001];
int solve(int ind, vector<int> &nums) {
    if(ind >= nums.size()) {
        return 1;
    }
    if(dp[ind] != -1) return dp[ind];
    bool ans = 0;
    vector<int> vec;
    for(int i=ind; i<nums.size(); i++) {

        vec.push_back(nums[i]);
        if(vec.size() == 2) {
            if(vec[0] == vec[1]) {
                ans = ans or solve(i+1, nums);
            }
        }
        if(vec.size() == 3) {
            if((vec[0] == vec[1] and vec[1] == vec[2])) {
                ans = ans or solve(i+1, nums);
            }else if(vec[0]+1 == vec[1] and vec[1]+1 == vec[2]) {
                ans = ans or solve(i+1, nums);
            }
        }

        if(vec.size() > 3) break;
    }

    return dp[ind] = ans;
}
    bool validPartition(vector<int>& nums) {
    
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};