class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int r=0,l=0;
        for(; r<nums.size(); ++r) {
            mp[nums[r]]++;
            while(mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        ans = max(ans, r-l);
        return ans;
    }
};