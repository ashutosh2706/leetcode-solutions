class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long op = 0;
        for(int i=nums.size()-2; i>=0; --i) {
            if(nums[i] <= nums[i+1]) continue;
            int parts = nums[i]/nums[i+1];
            if(nums[i] % nums[i+1]) ++parts;
            op+=(parts-1);
            nums[i] /= parts;
        }
        return op;
    }
};