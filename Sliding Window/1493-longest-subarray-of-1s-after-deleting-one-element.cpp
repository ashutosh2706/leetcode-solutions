class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    
    int l = 0, n = nums.size(), zero = 0;
    int ans = 0;
    for(int r=0; r<n; r++) {
        if(nums[r] == 0) zero++;
        while(l <= r && zero >= 2) {
            if(nums[l++] == 0) zero--;
        }
        ans = max(ans, r-l);
    }
    return ans;

    }
};