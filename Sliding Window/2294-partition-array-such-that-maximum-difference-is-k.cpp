class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
    sort(begin(nums),end(nums));
    int ans = 0;
    for(int l=0,r=0; r<nums.size(); r++) {
        if(nums[r] - nums[l] > k) {
            ans++;
            l = r;
        }
    }
    return ans+1;
    }
};