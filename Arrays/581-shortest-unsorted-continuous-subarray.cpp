class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(begin(nums),end(nums));
        sort(begin(v),end(v));
        if(v == nums) return 0;
        int mini = nums.size()-1, maxi = 0;
        for(int i=0; i<nums.size(); i++) {
            if(v[i] != nums[i]) {
                maxi = max(maxi,i);
                mini = min(mini, i);
            }
        }
        return maxi-mini+1;
    }
};