class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(begin(nums),end(nums));
        int l = 0, r = k-1;
        while(l < r) swap(nums[l++], nums[r--]);
        l = k, r=nums.size()-1;
        while(l<r) swap(nums[l++], nums[r--]);
    }
};