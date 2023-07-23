class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[n-1], sum = nums[n-1];
        for(int i=n-1; i>0; i--) {
            if(sum >= nums[i-1]) {
                sum += nums[i-1];
            } else sum = nums[i-1];
            ans = max(ans, sum);
        }
        return ans;
    }
};