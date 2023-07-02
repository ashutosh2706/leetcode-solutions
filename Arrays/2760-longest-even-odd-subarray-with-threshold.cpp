class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2 == 0 and nums[i] <= threshold) {
                int j = i+1;
                for(; j < nums.size(); j++) {
                    if((nums[j-1] + nums[j]) % 2 == 0 or nums[j] > threshold) break;
                }
                
                ans = max(ans, j-i);
            }
            
        }
        return ans;
    }
};