class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    long sum = 0;
    int s = 0, e = 0, ans = 1e9;
    while(e < nums.size()) {
        sum += nums[e++];
        
        while(sum >= target && s <= e) {
            ans = min(ans, e-s);
            sum -= nums[s++];
        }
    }
    return ans == 1e9 ? 0 : ans;
    }
};