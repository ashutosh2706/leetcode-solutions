class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = nums.front(), maxi = nums.front(), N = nums.size();
        for(auto &i : nums) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        int l=0 ,r=nums.size()-1;
        while(nums[l] != mini and nums[l] != maxi) l++;
        while(nums[r] != mini and nums[r] != maxi) r--;
        return min({N-l, r+1, l+1+N-r});
    }
};