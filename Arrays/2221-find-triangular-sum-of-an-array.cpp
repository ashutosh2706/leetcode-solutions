class Solution {
public:
    int solve(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        for(int i=0; i<n-1; ++i) {
            nums[i] = (nums[i] + nums[i+1])%10;
        }
        nums.pop_back();
        return solve(nums);
    }
    int triangularSum(vector<int>& nums) {
        return solve(nums);
    }
};