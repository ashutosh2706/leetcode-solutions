class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    long prod = 1;
    int s = 0, e = 0, ans = 0;
    while(e < nums.size()) {
        prod *= nums[e];
        while(s <= e && prod >= k) prod /= nums[s++];
        ans += (e - s) + 1;
        e++;
    }   
    
    return ans;
    }
};