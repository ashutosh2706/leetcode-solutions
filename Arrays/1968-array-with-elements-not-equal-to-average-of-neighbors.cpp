class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    
        int n = nums.size();
        for(int i=0; i<n-2; i++) {
            if(nums[i] + nums[i+2] == 2 * nums[i+1]) swap(nums[i+1], nums[i+2]);
        }

        for(int i=n-1; i>=2; i--) {
            if(nums[i] + nums[i-2] == 2*nums[i-1]) swap(nums[i-1], nums[i-2]);
        }

        return nums;
    }
};