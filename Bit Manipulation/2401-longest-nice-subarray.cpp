class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int t = 0, ans = 1;
        for(int i=1; i<nums.size(); ++i) {
            int j = max(t, i-29);
            for(; j<i; ++j) {
                if(nums[i] & nums[j]) 
                    t=j+1;
            }
            ans = max(ans, i-t+1);
        }
        return ans;
    }
};