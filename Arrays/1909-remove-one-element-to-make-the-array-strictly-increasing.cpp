class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int prev = -1, b = 1;
            for(int j=0; j<nums.size() and b; j++) {
                if(i == j) continue;
                if(prev == -1) prev = nums[j];
                else {
                    if(nums[j] <= prev) b = 0;
                    else prev = nums[j];
                }
            }
            if(b) return 1;
        }
        return 0;
    }
};