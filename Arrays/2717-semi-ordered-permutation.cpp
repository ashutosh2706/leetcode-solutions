class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        if(nums[0] == 1 and nums.back() == nums.size()) return 0;
        int swaps = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                int ind = i;
                while(ind > 0) {
                    swap(nums[ind], nums[ind-1]);
                    swaps++;
                    ind--;
                }
                if(ind == 0 and nums[0] == 1) break;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == nums.size()) {
                int ind = i;
                while(ind < nums.size()-1) {
                    swap(nums[ind], nums[ind+1]);
                    ind++;
                    swaps++;
                }
                break;
            }
        }
        return swaps;
        
    }
};