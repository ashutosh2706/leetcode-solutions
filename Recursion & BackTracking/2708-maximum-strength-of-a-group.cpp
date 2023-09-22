class Solution {
public:
    typedef long long int ll;
    ll ans = -1e13;
    void solve(int ind, vector<int> &nums, ll sum) {
        if(ind >= nums.size()) {
            ans = max(ans, sum);
            return;
        }
        if(sum == (ll)-1e13) {
            solve(ind+1, nums, nums[ind]);
        } else {
            solve(ind+1, nums, nums[ind]*sum);
        }
        solve(ind+1, nums, sum);
    }
    long long maxStrength(vector<int>& nums) {
        solve(0,nums,(ll)-1e13);
        return ans;
    }
};