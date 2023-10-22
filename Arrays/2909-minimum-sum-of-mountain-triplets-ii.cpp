class Solution {
public:
    int minimumSum(vector<int>& nums) {
    
        vector<int> l(nums.size()), r(nums.size());
        l[0] = -1;
        int mini = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i] <= mini) l[i]=-1;
            else l[i] = mini;
            mini = min(mini, nums[i]);
        }
        r.back() = -1;
        mini = nums.back();
        for(int i=nums.size()-2; i>=0; --i) {
            if(nums[i] <= mini) r[i] = -1;
            else r[i] = mini;
            mini = min(mini, nums[i]);
        }
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); ++i) {
            if(l[i] != -1 and r[i] != -1) {
                ans = min(ans, nums[i] + l[i] + r[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};