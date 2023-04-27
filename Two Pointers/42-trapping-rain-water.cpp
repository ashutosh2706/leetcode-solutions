class Solution {
private:
int s, e;
int getWater(vector<int> &nums, int n) {
    int ans = 0;
    s = 0, e = 0;
    long long sum = 0;
    while(s < n) {
        e = s+1;
        sum = 0;
        while(e < n && (nums[s] > nums[e])) sum += nums[e++];
        if(e == n) break;
        ans += (nums[s] * (e - s - 1)) - sum;
        s = e;
    }
    return ans;
}
public:
    int trap(vector<int>& nums) {
        int ret = getWater(nums, nums.size());
        reverse(begin(nums), end(nums));
        ret += getWater(nums, nums.size() - s);
        return ret;
    }
};