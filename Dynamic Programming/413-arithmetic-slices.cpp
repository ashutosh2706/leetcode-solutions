// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

    int i = 0, j = 1, res = 0, n = nums.size();
    while(j < n) {
        i = j-1;
        int diff = nums[j] - nums[i];
        while(j < n && (nums[j] - nums[j-1] == diff)) j++;
        int ele = (j - 1 - i) + 1;
        res += (ele * (ele - 1))/2 - (j - 1 - i);
    }

    return res;
        
    }
};