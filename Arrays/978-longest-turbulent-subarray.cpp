class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int ans = 0, d = 0, r = 0, l = 0;
        while(r < nums.size()-1 and nums[r] == nums[r+1]) { l++; r++; } 
        for(; r < nums.size()-1; r++) {
            if(nums[r] == nums[r+1]) {
                ans = max(ans, r-l+1);
                l = r+1;
                continue;
            }
            if((nums[r] > nums[r+1] and d == -1) or (nums[r] < nums[r+1] and d == 1)) {
                ans = max(ans, r-l+1);
                l = r;
            } else (nums[r] > nums[r+1]) ? d = -1 : d = 1;
            
        }
        ans = max(ans, r-l+1);
        return ans;
    }
};