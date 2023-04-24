class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    int n = nums.size(), changed = 0;
    for(int i=0; i<n-1; i++) {

        if(nums[i] > nums[i+1]) {
            if(changed) return 0;
            if(i == 0 || nums[i-1] <= nums[i+1])
                nums[i] = nums[i+1];
            else 
                nums[i+1] = nums[i];
            changed = 1;
        }
    }  
    return 1;
    }
};