class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int curr = 0;
        for(int i=0; i<nums.size(); i++) {
            if(curr > nums[i]) return 0;
            nums[i] -= curr;
            curr += nums[i];

            if(i + 1 >= k) {
                curr -= nums[i-k+1];
            }
        }
        return curr == 0;
    }
};