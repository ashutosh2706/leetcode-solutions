class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp(begin(nums), end(nums));
        for(int i=nums.size()-1; i>=0; i--) {
            int index = (i+k) % nums.size();
            nums[index] = tmp[i];
        }
    }
};