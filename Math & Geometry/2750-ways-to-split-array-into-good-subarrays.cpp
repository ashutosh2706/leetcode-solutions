class Solution {
int mod = 1e9+7;
typedef long long ll;
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        ll ans = 1, ind = 0;
        for(; ind<nums.size() and !nums[ind]; ind++);
        if(ind == nums.size()) return 0;
        for(; ind < nums.size(); ind++) {
            if(nums[ind]) continue;
            ll cnt = 0;
            while(ind < nums.size() and !nums[ind]) {
                cnt++;
                ind++;
            }
            if(ind < nums.size()) ans = (ans * ++cnt) % mod;
        }
    return ans;
    }
};