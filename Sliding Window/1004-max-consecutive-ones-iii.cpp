class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0, n = nums.size();
        int zero = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            if(nums[r] == 0) zero++;
            while(l <= r and zero > k) {
                if(nums[l++] == 0) zero--;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};