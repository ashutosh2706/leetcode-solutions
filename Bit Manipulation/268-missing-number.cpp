class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = 0, b = 0, i = 0;
        for(; i<nums.size(); i++) {
            a = a ^ nums[i];
            b = b^i;
        }
        b = b^i;
        return a^b;
    }
};