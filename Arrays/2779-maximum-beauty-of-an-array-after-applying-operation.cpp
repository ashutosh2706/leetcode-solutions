class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
    sort(begin(nums),end(nums));
    int ans = 0;
    for(int l=0,r=0; r<nums.size(); r++) {
        while(l < r and (nums[r] - nums[l]) > 2*k) {
            l++;
        }
        ans = max(ans, r-l+1);
    }
    return ans;
    }
};